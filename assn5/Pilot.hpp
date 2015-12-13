/*********************************************************************
 ** Program Filename: Pilot.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Pilot class. A Pilot
 **              represents the player of the Game and has a Fighter
 **              ship, a name, money, and Items.
 *********************************************************************/


#ifndef PILOT_HPP
#define PILOT_HPP


#include <string>

#include "Fighter.hpp"
#include "Bolq.hpp"
#include "Voltsweeper.hpp"
#include "Item.hpp"
#include "System.hpp"

class Pilot
{
private:
  static const int MAX_ITEMS = 7;
  
  std::string name;
  
  // the ship the user is flying
  Fighter* ship;
  
  // measured in “ducats”
  int money;
  
  // Items the user has purchased or found
  std::vector<Item> items;
  
  // current System user is in
  System* cur_system;
  
  // user's ship destroyed
  bool dead;
  
  // number of battles won
  int battles;
  
  // current turn
  int tick;
  
  // true max health of ship
  int get_adjusted_max_health();
  
public:
  Pilot(std::string nm) : name(nm), money(1000), cur_system(NULL), dead(false), battles(0), tick(0)
  {
    ship = new Voltsweeper;
  }
  
  ~Pilot() { delete ship; }
  
  void add_ticks(int num_ticks) { tick += num_ticks; }
  
  void died() { dead = true; }
  
  void gain_item(const Item& item) { items.push_back(item); }
  
  std::vector<Item>* get_items() { return &items; }
  
  void gain_money(int ducats) { money += ducats;  if (money < 0) money = 0; }
  
  System* get_cur_system() const { return cur_system; }
  
  int get_current_health();
  
  bool get_drunk();
  
  int get_fuel() const { return ship->get_fuel(); }
  
  int get_money() const { return money; }
  
  std::string get_name() const { return name; }
  
  // note: do not use this pointer after calling set_ship()
  Fighter* get_ship() const { return ship; }
  
  bool has_map();
  
  bool has_room() const { return static_cast<int>(items.size()) < MAX_ITEMS; }
  
  bool is_dead() const { return dead; }
  
  void print_items();
  
  void print_status(std::string header);
  
  void remove_item(Item& i);
  
  void restore_half_fuel() { ship->restore_half_fuel(); }
  
  void restore_all_fuel() { ship->restore_all_fuel(); }
  
  void restore_all_health() { ship->restore_all_health(); }
  
  void set_cur_system(System* new_system) { cur_system = new_system; }
  
  void set_ship(Fighter* f) { delete ship; ship = f; }
  
  void set_fuel(int amount) { ship->set_fuel(amount); }
  
  bool won();
  
  void won_battle() { ++battles; }
};

#endif /* PILOT_HPP */
