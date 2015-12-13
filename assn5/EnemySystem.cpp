/*********************************************************************
 ** Program Filename: EnemySystem.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              EnemySystem class.
 *********************************************************************/


#include <cstdlib>    // rand()
#include <iostream>   // std::cout

#include "EnemySystem.hpp"
#include "FightEvent.hpp"
#include "MonetaryEvent.hpp"
#include "TaxEvent.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: EnemySystem::special()
 ** Description: Plays out the occurrences that happen to the user
 **              on this EnemySystem this turn.  If the user's ship
 **              has fuel, it is possible to jump to a new System.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 *********************************************************************/

void EnemySystem::special()
{
  System::special();
  
  utilities::clear_display();
  
  // always an ambush
  FightEvent fe(player, 3, 4);
  fe.run();
  
  utilities::wait_for_user();
  utilities::clear_display();

  // game is over
  if (player->is_dead())
    return;
  
  // 10% chance of user finding money
  if (rand() % 100 < 10)
  {
    MonetaryEvent me(player);
    me.run();
    
    utilities::wait_for_user();
    utilities::clear_display();
  }
  
  // 15% chance of user being taxed
  if (rand() % 100 < 15)
  {
    TaxEvent te(player);
    te.run();
    
    utilities::wait_for_user();
  }
  
  // user done with menu
  bool done = false;
  
  // user already asked for info?
  bool asked = false;
  
  // display menu
  while (!done)
  {
    utilities::clear_display();
    
    make_menu();
    
    int num_ops = static_cast<int>(system_menu.get_num_options());

    system_menu.display();
  
    std::cout << "What would you like to do?\n";
    int choice = utilities::get_valid_int_in_range(1, num_ops);
    
    utilities::clear_display();
    
    std::string map_header = std::string("========== Map - Current System: ") + player->get_cur_system()->get_name() + " ==========\n\n";
  
    switch (choice)
    {
      case 1: done = true; break;
      case 2: player->print_status("========== Status ==========\n\n"); break;
      case 3: std::cout << map_header; view_map(); break;
      case 4: open_store(); break;
      case 5: sell(); break;
      case 6: refuel(); break;
      case 7: repair(); break;
      case 8: buy_ship(); break;
      case 9:
      {
        if (!asked)
        {
          ask_info();
          asked = true;
        }
        else
          std::cout << "You have already gotten all the information you can get right now!\n\n";
        
        break;
      }
      default: jump_to(choice); done = true; // wants to jump
    }
    
    utilities::wait_for_user();
  }
}