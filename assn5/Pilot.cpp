/*********************************************************************
 ** Program Filename: Pilot.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Pilot class.
 *********************************************************************/


#include "Pilot.hpp"


/*********************************************************************
 ** Function: Pilot::get_current_health()
 ** Description: Calculates and returns the number of hit points the
 **              Pilot's ship has.
 ** Parameters: none
 *********************************************************************/

int Pilot::get_current_health()
{
  int cur_health = ship->get_cur_health();
  
  // items may modify base health
  for (int i = 0; i < static_cast<int>(items.size()); ++i)
    cur_health += items.at(i).get_health_mod();
  
  if (cur_health > 0)
    return cur_health;
  
  return 0;
}


/*********************************************************************
 ** Function: Pilot::get_drunk()
 ** Description: Returns true if the Pilot has the Eye of the Hack.
 ** Parameters: none
 *********************************************************************/

bool Pilot::get_drunk()
{
  // 12.5% chance of getting drunk if the user has Eye of the Hack
  for (int i = 0; i < static_cast<int>(items.size()); ++i)
    if (items.at(i).get_name() == "Eye of the Hack")
      return rand() % 8 == 0;
  
  return false;
}


/*********************************************************************
 ** Function: Pilot::get_adjusted_max_health()
 ** Description: Calculates and returns the number of hit points the
 **              Pilot's ship has.
 ** Parameters: none
 *********************************************************************/

int Pilot::get_adjusted_max_health()
{
  int max_health = ship->get_base_health();
  
  // items may modify base health
  for (int i = 0; i < static_cast<int>(items.size()); ++i)
    max_health += items.at(i).get_health_mod();
  
  return max_health;
}


/*********************************************************************
 ** Function: Pilot::has_map()
 ** Description: Returns true if the Pilot has the Electron MipMap.
 ** Parameters: none
 *********************************************************************/

bool Pilot::has_map()
{
  for (int i = 0; i < static_cast<int>(items.size()); ++i)
    if (items.at(i).get_name() == "Electron MipMap")
      return true;
  
  return false;
}


/*********************************************************************
 ** Function: Pilot::print_status()
 ** Description: Displays various facts about the current game to the
 **              user.
 ** Parameters: header    the header for the display
 *********************************************************************/

void Pilot::print_status(std::string header)
{
  std::cout << header;
  
  std::cout << "Pilot: " << name << '\n';
  std::cout << "Turn " << tick << '\n';
  std::cout << "Current System: " << cur_system->get_name() << '\n';
  std::cout << "Finances: " << money << " ducats\n\n";
  std::cout << "Ship Type: " << ship->get_name() << '\n';
  std::cout << "Ship Description: " << ship->get_description() << "\n\n";
  std::cout << "Ship Health: " << get_current_health() << '/' << get_adjusted_max_health() << '\n';
  std::cout << "Battles Won: " << battles << '\n';
  std::cout << "Jumps Left: " << ship->get_fuel() << '/' << ship->get_max_fuel() << "\n\n";
  
  print_items();
}


/*********************************************************************
 ** Function: Pilot::print_items()
 ** Description: Display the Items the Pilot has collected.
 ** Parameters: none
 *********************************************************************/

void Pilot::print_items()
{
  std::cout << "Items Obtained: \n";
  
  long num_items = items.size();
  
  if (num_items == 0)
    std::cout << "\tnone\n";
  
  for (int i = 0; i < static_cast<int>(items.size()); ++i)
  {
    std::cout << '\t' << items.at(i).get_name() << '\n';
    std::cout << "\t\t" << items.at(i).get_description() << '\n';
  }
  
  std::cout << "\n\n";
}


/*********************************************************************
 ** Function: Pilot::remove_item()
 ** Description: Removes an Item from the Pilot's collection.  If the
 **              Pilot lacks the Item, nothing is removed.
 ** Parameters: item    the Item to be removed
 *********************************************************************/

void Pilot::remove_item(Item& item)
{
  long num_items = items.size();
  bool found = false;
  
  for (int i = 0; i < num_items && !found; ++i)
  {
    if (item == items[i])
    {
      items.erase(items.begin() + i);
      found = true;
    }
  }
}


/*********************************************************************
 ** Function: Pilot::won()
 ** Description: Returns true if the Pilot has Chronicles of
 **              Sharnia.
 ** Parameters: none
 *********************************************************************/

bool Pilot::won()
{
  for (int i = 0; i < static_cast<int>(items.size()); ++i)
    if (items.at(i).get_name() == "Chronicles of Sharnia")
      return true;
  
  return false;
}