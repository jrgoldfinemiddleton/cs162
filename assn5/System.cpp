/*********************************************************************
 ** Program Filename: System.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              System class.
 *********************************************************************/


#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

#include "System.hpp"
#include "Info.hpp"
#include "Map.hpp"
#include "Pilot.hpp"
#include "Bolq.hpp"
#include "Lamborqini.hpp"
#include "Raw.hpp"
#include "SleazeLiner.hpp"
#include "Suxel.hpp"
#include "TrollE.hpp"
#include "Voltsweeper.hpp"
#include "Windweeper.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: System::ask_info()
 ** Description: Asks someone on the planet in this System for
 **              information about the next key Item needed.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 *********************************************************************/

void System::ask_info()
{
  Info i (player, map, type, next_key, rand() % 2 == 0);
  i.run();
}


/*********************************************************************
 ** Function: System::buy_ship()
 ** Description: Displays the ship depot menu and allows the player to
 **              purchase a new Fighter.  If the player wants one, it
 **              charges money and set's the player's ship to a new
 **              Fighter of the desired type.  The Items held by the
 **              player do not change.
 ** Parameters: none
 *********************************************************************/

void System::buy_ship()
{
  Menu ship_menu;
  ship_menu.set_header("System " + name + " Ship Depot");
  
  double mult = 1.0;
  
  // price multipliers based on friendliness of system
  switch (type)
  {
    case ENEMY: mult = 2.5; break;
    case NEUTRAL: mult = 1.6; break;
    case FRIENDLY: case EMPTY: case INVALID: break;
  }
  
  // base prices
  int cst[8] = { 1000, 1000, 2000, 2500, 4500, 6000, 8500, 10000 };
  std::vector<int> costs(cst, cst + 8);
  
  // modify prices
  for (int i = 0; i < static_cast<int>(costs.size()); ++i)
    costs.at(i) *= mult;
  
  int op = 0;
  
  ship_menu.add_option(op, "Buy Windweeper for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy Voltsweeper for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy TrollE for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy R.A.W. for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy Sleaze Liner for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy 003SI Suxel for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy Lamborqini for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats"); ++op;
  ship_menu.add_option(op, "Buy Bolq XXXL for " +
                       std::to_string(static_cast<long long>(costs.at(op))) + " ducats");
  
  ship_menu.display();
  
  std::cout << "You have " << player->get_money() <<
  " ducats.  Which ship do you want to buy? (0 to leave ship depot)\n";
  
  int choice = utilities::get_valid_int_in_range(0, static_cast<int>(ship_menu.get_num_options()));
  
  if (choice != 0)
  {
    // if user can afford chosen ship, make user a new one of that type
    if (player->get_money() >= costs.at(choice - 1))
    {
      switch (choice)
      {
        case 1: player->set_ship(new Windweeper); break;
        case 2: player->set_ship(new Voltsweeper); break;
        case 3: player->set_ship(new TrollE); break;
        case 4: player->set_ship(new Raw); break;
        case 5: player->set_ship(new SleazeLiner); break;
        case 6: player->set_ship(new Suxel); break;
        case 7: player->set_ship(new Lamborqini); break;
        case 8: player->set_ship(new Bolq); break;
        default: break;
      }
      
      // spent money
      player->gain_money(-costs.at(choice - 1));
      std::cout << "You are the proud owner of a new " << player->get_ship()->get_name() << ".  ";
      
      // give it full fuel and hit points
      player->restore_all_fuel();
      player->restore_all_health();
    }
    
    // user can't afford desired ship
    else
      std::cout << "You don't have enough money for that!\n";
  }
  
  std::cout << "Leaving ship depot.\n\n";
}


/*********************************************************************
 ** Function: System::gen_header()
 ** Description: Create menu header for this System.
 ** Parameters: none
 *********************************************************************/

std::string System::gen_header()
{
  switch (type)
  {
    case EMPTY: return "System: " + name + " (empty)";
    case ENEMY: return "System: " + name + " (enemy)";
    case NEUTRAL: return "System: " + name + " (neutral)";
    case FRIENDLY: return "System: " + name + " (friendly)";
    case INVALID: break;
  }
  
  return "SYSTEM ERROR";
}


/*********************************************************************
 ** Function: System::jump_to()
 ** Description: Set the Pilot's current System to the one
 **              corresponding to option menu_op in the System menu.
 ** Parameters: menu_op   the menu option representing the System
 **                       to jump to
 *********************************************************************/

void System::jump_to(int menu_op)
{
  // first jump menu option
  int cur = first_jump_option;
  
  for (int i = 0; i < static_cast<int>(neighbors.size()); ++i)
  {
    System* neigh = neighbors.at(i);
    
    // skip nonexistent neighbors
    if (neigh != NULL)
    {
      if (cur == menu_op)
      {
        std::cout << "About to jump to the " << neigh->get_name() << " system!\n\n";
        
        player->set_cur_system(neigh);
        player->set_fuel(player->get_fuel() - 1);
      }
      
      ++cur;
    }
  }
}


/*********************************************************************
 ** Function: System::make_menu()
 ** Description: Creates a menu for this System.  It will include
 **              Systems that can be jumped to if the player has fuel.
 ** Parameters: none
 *********************************************************************/

void System::make_menu()
{
  // clear old version of menu
  for (int i = static_cast<int>(system_menu.get_num_options() - 1); i >= 0; --i)
    system_menu.remove_option(i);
  
  system_menu.set_header(gen_header());
  
  int op = 0;
  
  // all systems
  system_menu.add_option(op++, "Stick around");
  system_menu.add_option(op++, "Print status");
  system_menu.add_option(op++, "View map");
  
  // enemy, friendly, and neutral only
  if (type != EMPTY)
  {
    system_menu.add_option(op++, "Hit up the store for items");
    system_menu.add_option(op++, "Sell item");
    system_menu.add_option(op++, "Refuel ship");
    system_menu.add_option(op++, "Repair ship");
    system_menu.add_option(op++, "Buy new ship");
    system_menu.add_option(op++, "Ask someone for information");
  }
  
  // add jump options only if user's ship has fuel
  if (player->get_fuel() > 0)
  {
    for (int i = 0; i < static_cast<int>(neighbors.size()); ++i)
    {
      System* neigh = neighbors.at(i);
      
      // don't add non-existent neighbors to menu
      if (neigh != NULL)
        system_menu.add_option(op++, "Jump to system " + neigh->get_name());
    }
  }
}


/*********************************************************************
 ** Function: System::open_store()
 ** Description: Display a store where the player can buy a new Item
 **              he/she can afford and has room for it.  If the player
 **              buys an Item, it is added to his/her collection.
 ** Parameters: none
 *********************************************************************/

void System::open_store()
{
  store_menu.display();
  
  if (!(player->has_room()))
  {
    std::cout << "You don't have room for new items.  Sell one and come back.\n\n";
    
    utilities::wait_for_user();
    return;
  }
  
  std::cout << "You have " << player->get_money() <<
  " ducats.  Which item do you want? (0 to exit store)\n";
  
  int choice = utilities::get_valid_int_in_range(0, static_cast<int>(store_menu.get_num_options()));
  
  if (choice > 0)
  {
    // if user can afford desired item buy it
    if (player->get_money() >= prices.at(choice - 1))
    {
      Item &desired = store.at(choice - 1);
      std::cout << "You bought the " << desired.get_name() << ".  ";
      player->gain_item(desired);
      player->gain_money(-prices.at(choice - 1));
    }
    
    else
      std::cout << "Sorry, you don't have enough money for that item.  ";
  }
  
  std::cout << "Leaving store.\n\n";
}


/*********************************************************************
 ** Function: System::refuel()
 ** Description: Allows the player to refuel its ship to max.
 ** Parameters: none
 *********************************************************************/

void System::refuel()
{
  int charge = 0;
  
  // price depends on friendliness of system
  switch (type)
  {
    case ENEMY:     charge = 300; break;
    case FRIENDLY:  charge = 100; break;
    case NEUTRAL:   charge = 200; break;
    case EMPTY: case INVALID:        charge = -1;
  }
  
  std::cout << "Refueling here will cost you " << charge << " ducats.  Is that okay? (y/n) ";
  
  char c = std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  if (c == 'y' || c == 'Y')
  {
    // if user can afford it, pay and refuel
    if (charge <= player->get_money())
    {
      std::cout << "\nYour ship is completely refueled!\n";
      player->gain_money(-charge);
      player->restore_all_fuel();
    }
    
    else
      std::cout << "\nYou could not afford to refuel!\n";
  }
  
  std::cout << '\n';
}


/*********************************************************************
 ** Function: System::repair()
 ** Description: Allows the player to repair its ship and restore full
 **              health.
 ** Parameters: none
 *********************************************************************/

void System::repair()
{
  int charge = 0;
  
  // price depends on friendliness of system
  switch (type)
  {
    case ENEMY:     charge = 400; break;
    case FRIENDLY:  charge = 50; break;
    case NEUTRAL:   charge = 100; break;
    case EMPTY: case INVALID:        charge = -1;
  }
  
  std::cout << "Getting your ship repaired here will cost you " << charge <<
  " ducats.  Is that okay? (y/n) ";
  
  char c = std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  if (c == 'y' || c == 'Y')
  {
    // if user can afford it, pay and repair ship
    if (charge <= player->get_money())
    {
      std::cout << "\nYour ship is completely repaired!\n";
      player->gain_money(-charge);
      player->restore_all_health();
    }
    
    else
      std::cout << "\nYou could not afford to get your ship repaired!\n";
  }
  
  std::cout << '\n';
}


/*********************************************************************
 ** Function: System::sell()
 ** Description: Creates a menu listing the user's non-key Items and
 **              sell prices for each and allows the player to sell an
 **              Item.
 ** Parameters: none
 *********************************************************************/

void System::sell()
{
  Menu sell_menu;
  sell_menu.set_header("System " + get_name() + " Swap Meet");
  
  // all salable items
  std::vector<Item> sell_items;
  
  // corresponding prices
  std::vector<int> sell_prices;
  
  double price_reduct = 0.0;
  
  switch (type)
  {
    case ENEMY: price_reduct = 0.2; break;
    case FRIENDLY: price_reduct = 0.6; break;
    case NEUTRAL: price_reduct = 0.4; break;
    case EMPTY: case INVALID: price_reduct = -1;
  }
  
  // items the player has
  std::vector<Item> *player_items = player->get_items();
  
  for (int i = 0; i < static_cast<int>(player_items->size()); ++i)
  {
    const Item &cur_item = player_items->at(i);
    
    // only allow selling of non-key items
    if (!(cur_item.is_key()))
    {
      sell_items.push_back(cur_item);
      sell_prices.push_back(cur_item.get_base_price() * price_reduct);
    }
  }
  
  for (int i = 0; i < static_cast<int>(sell_items.size()); ++i)
    sell_menu.add_option(i,
                         sell_items.at(i).get_name() + ": " +
                         std::to_string(static_cast<long long>(sell_prices.at(i))) + " ducats" +
                         "\n\t" + sell_items.at(i).get_description() + "\n");
  
  sell_menu.display();
  
  std::cout << "You have " << player->get_money() <<
  " ducats.  Which item do you want to sell? (0 to leave swap meet)\n";
  
  int choice = utilities::get_valid_int_in_range(0, static_cast<int>(sell_menu.get_num_options()));
  
  // sell the chosen item
  if (choice > 0)
  {
    Item &desired = sell_items.at(choice - 1);
    std::cout << "You sold the " << desired.get_name() << ".  ";
    player->remove_item(desired);
    player->gain_money(sell_prices.at(choice - 1));
  }
  
  std::cout << "Leaving swap meet.\n\n";
}


/*********************************************************************
 ** Function: System::set_up_store()
 ** Description: Selects the Items to have in the store and their
 **              prices.
 ** Parameters: items   the set of all salable Items
 ** Pre-Conditions: There must at least be 4 Items in the list.
 ** Post-Conditions:
 *********************************************************************/

void System::set_up_store(const std::vector<Item>& items)
{
  long num_items = items.size();
  
  // choose one of each type of item
  store.push_back(items.at(rand() % (num_items / 4)));
  store.push_back(items.at(rand() % (num_items / 4) + (num_items / 4)));
  store.push_back(items.at(rand() % (num_items / 4) + 2 * (num_items / 4)));
  store.push_back(items.at(rand() % (num_items / 4) + 3 * (num_items / 4)));
  
  store_menu.set_header("System " + get_name() + " Battle Store");
  
  double cost_mult = 0.0;
  
  // multipliers of price based on friendliness of system
  switch (type)
  {
    case ENEMY: cost_mult = 2.5; break;
    case NEUTRAL: cost_mult = 1.0; break;
    case FRIENDLY: cost_mult = 0.75; break;
    case EMPTY: case INVALID: break;
  }
  
  for (int i = 0; i < static_cast<int>(store.size()); ++i)
  {
    prices.push_back(static_cast<int>(store.at(i).get_base_price() * cost_mult));
    
    store_menu.add_option(i, store.at(i).get_name() + ": " +
                          std::to_string(static_cast<long long>(prices.at(i))) + " ducats" +
                          "\n\t" + store.at(i).get_description() + "\n");
  }
}


/*********************************************************************
 ** Function: System::view_map()
 ** Description: If the player has the Electron MipMap, displays its
 **              contents to the screen.  The map only shows the names
 **              of Systems the player has visited.
 ** Parameters: none
 *********************************************************************/

void System::view_map()
{
  // print only if user has Electron MipMap
  if (player->has_map())
    map->print_universe(false);
  
  else
    std::cout << "Sorry, you need to find the Electron MipMap first.\n\n";
}
