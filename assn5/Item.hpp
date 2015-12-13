/*********************************************************************
 ** Program Filename: Item.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Item class. An Item
 **              represents either a powerup for the player's Fighter
 **              or one of the key items needed to win the game.
 *********************************************************************/


#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
private:
  std::string name;
  std::string description;
  int base_price;
  double attack_mod;
  double armor_mod;
  int health_mod;
  int speed_mod;
  bool key;
  
public:
  Item(std::string nm, std::string desc, int bp, double atm, double arm, int hm, int sm, bool ky) :
      name(nm), description(desc), base_price(bp), attack_mod(atm),
      armor_mod(arm), health_mod(hm), speed_mod(sm), key(ky) { }
  
  double get_armor_mod() const { return armor_mod; }
  
  double get_attack_mod() const { return attack_mod; }
  
  int get_base_price() const { return base_price; }
  
  std::string get_description() const { return description; }
  
  int get_health_mod() const { return health_mod; }
  
  std::string get_name() const { return name; }
  
  int get_speed_mod() const { return speed_mod; }
  
  bool is_key() const { return key; }
  
  bool operator==(Item& rhs) { return name == rhs.name; }
  
};

#endif /* ITEM_HPP */
