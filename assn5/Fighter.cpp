/*********************************************************************
 ** Program Filename: Fighter.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Fighter class.
 *********************************************************************/


#include <sstream>      // std::stringstream

#include "Fighter.hpp"


/*********************************************************************
 ** Function: Fighter::set_description()
 ** Description: Initialize this Fighter's description based on its
 **              base stats.
 ** Parameters: none
 *********************************************************************/

void Fighter::set_description()
{
  std::string speed;
  
  if (base_speed < 120) speed = " slow";
  else if (base_speed < 180) speed = " moderately fast";
  else speed = "n extremely speedy";
  
  std::string hp;
  
  if (base_health < 200) hp = "low";
  else if (base_health < 350) hp = "a decent amount of";
  else hp = "very high";
  
  std::string fuel;
  
  if (max_fuel < 4) fuel = " tiny";
  else if (max_fuel < 6) fuel = " medium";
  else fuel = "n enormous";
  
  std::stringstream ss;
  ss << "A" << speed << " ship with " << hp << " HP and a" << fuel << " fuel tank.\n" <<
        "Special Weapon: " << weapon->get_name() << "\n\t" << weapon->get_description();
  description = ss.str();
}