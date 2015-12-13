/*********************************************************************
 ** Program Filename: Fighter.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Fighter class. A
 **              Fighter represents a fighter ship that has health,
 **              armor, speed, and a special weapon.
 *********************************************************************/


#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <cstdlib>    // rand()
#include <vector>     // std::vector
#include <string>     // std::string

#include "Item.hpp"
#include "Weapon.hpp"


class Fighter
{
protected:
  std::string name; // ship type
  
  int base_health; // raw hit points, when 0 or less, fighter is irreparably destroyed
  //int base_attack; // number of hit points of damage default weapon does to a single enemy fighter per turn
  int base_armor; // number of hit points of each enemy fighter’s attack that are cancelled out before
                  // applying damage to this fighter every turn
  int base_speed; // higher value has precedence in a fight
  
  int cur_health;
  
  int max_fuel; // number of System jumps user can make with full fuel tank
  int cur_fuel; // number of System jumps left before tank is empty
  
  Weapon *weapon;
  
  std::string description; // description of ship
  
  Fighter(std::string name, int health, int armor, int speed, int fuel) :
          name(name), base_health(health), base_armor(armor), base_speed(speed),
          cur_health(health), max_fuel(fuel), cur_fuel(fuel) { }
  
public:
  virtual ~Fighter() { }
  
  int attack_enemy() { return (!is_area_wide() && weapon->successful()) ? get_base_attack() : 0; }
  
  int attack_enemies() { return (is_area_wide() && weapon->successful()) ? get_base_attack() : 0; }
  
  bool is_area_wide() { return weapon->is_area_wide(); }
  
  void defend(int attk) { cur_health -= attk; }        // apply enemy attack
  
  void restore_half_fuel() { cur_fuel += max_fuel / 2; }
  void restore_all_fuel() { cur_fuel = max_fuel; }
  void restore_all_health() { cur_health = base_health; }
  int get_fuel() const { return cur_fuel; }
  int get_base_attack() const { return weapon->get_base_damage(); }
  int get_base_armor() const { return base_armor; }
  int get_base_speed() const { return base_speed; }
  int get_base_health() const { return base_health; }
  int get_cur_health() const { return cur_health; }
  int get_max_fuel() const { return max_fuel; }
  std::string get_name() const { return name; }
  void set_fuel(int amount) { cur_fuel = amount; }
  std::string get_description() const { return description; }
  void set_description();
};

#endif /* FIGHTER_HPP */
