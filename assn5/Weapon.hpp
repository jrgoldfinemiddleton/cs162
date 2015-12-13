/*********************************************************************
 ** Program Filename: Weapon.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Weapon class. A
 **              Weapon represents a special weapon that a Fighter has
 **              and has base damage and accuracy stats.  A Weapon may
 **              be either targeted or area-wide.
 *********************************************************************/


#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <cstdlib>
#include <string>

class Weapon
{
protected:
  // weapon name
  std::string name;
  
  // damage in hit points before any modifiers or armor come into effect
  int base_damage;
  
  // percent of time the attack is successful
  double accuracy;
  
  // true if usage affects all enemy fighters
  bool area_wide;
  
public:
  Weapon(std::string nm, int base_attk, double acc, bool area) :
          name(nm), base_damage(base_attk), accuracy(acc), area_wide(area) { }
  
  int get_base_damage() const { return base_damage; }
  
  std::string get_description();
  
  std::string get_name() const { return name; }
  
  bool is_area_wide() const { return area_wide; }
  
  // pre-condition: srand() called
  bool successful() const { return rand() % 101 <= 100 * accuracy; }
};

#endif /* WEAPON_HPP */
