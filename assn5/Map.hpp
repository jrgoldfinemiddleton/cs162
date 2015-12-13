/*********************************************************************
 ** Program Filename: Map.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Map class.  A Map
 **              represents the universe of the Game.  It sets up all
 **              Systems and relates them to each other.
 *********************************************************************/


#ifndef MAP_HPP
#define MAP_HPP

#include "System.hpp"
#include "EmptySystem.hpp"
#include "EnemySystem.hpp"
#include "FriendlySystem.hpp"
#include "NeutralSystem.hpp"
#include "utilities.hpp"

#include <cstdlib>
#include <vector>
#include <string>

class Map
{
private:
  static const int HEIGHT = 5;
  static const int WIDTH = 5;
  
  System* grid[WIDTH * HEIGHT];
  
  std::vector<Item> avail_items;
  
  Pilot* player;
  
  std::string key_loc;
  
  System* get_upper(int pos);
  System* get_right(int pos);
  System* get_lower(int pos);
  System* get_left(int pos);
  
  void print_empty_square(int i);
  
  void print_named_square(int sys, int i);
  
public:
  Map(const std::vector<Item>& reg_items, Pilot* p) : avail_items(reg_items), player(p)
  {
    set_up_universe();
  }
  
  ~Map();
  
  std::string get_key_loc() const { return key_loc; }
  
  std::vector<std::string> get_all_visited();
  
  System* get_random_nonempty();
  
  System* get_random_friendly();
  
  void print_universe(bool all);
  
  void set_key_loc(std::string sys) { key_loc = sys; }
  
  void set_up_universe();
};

#endif /* MAP_HPP */
