/*********************************************************************
 ** Program Filename: Weapon.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Weapon class.
 *********************************************************************/


#include <sstream>      // std::stringstream

#include "Weapon.hpp"


/*********************************************************************
 ** Function: Weapon::get_description()
 ** Description: Returns a simple description of this Item.
 ** Parameters: none
 *********************************************************************/

std::string Weapon::get_description()
{
  std::string acc;
  
  if (accuracy < 0.5) acc = "inaccurate";
  else if (accuracy < 0.75) acc = "fairly accurate";
  else if (accuracy < 1.0) acc = "extremely accurate";
  else acc = "perfectly accurate";
  
  std::string damage;
  
  if (base_damage < 30) damage = "weak";
  else if (base_damage < 60) damage = "moderately strong";
  else damage = "powerful";
  
  std::string area = area_wide ? "affects all enemies" : "targets a single enemy";
  
  std::stringstream ss;
  
  ss << "A " << damage << " and " << acc << " weapon that " << area << ".";
  
  return ss.str();
}