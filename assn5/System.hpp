/*********************************************************************
 ** Program Filename: System.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the System class.  A
 **              System represents a star system in a Map of the
 **              Game's universe.  The file also contains the
 **              definition of the System_Type enum, which helps
 **              distinguish between the System derived classes.
 *********************************************************************/


#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
#include <unistd.h>
#include <vector>

#include "Direction.hpp"
#include "Item.hpp"
#include "Menu.hpp"


enum System_Type
{
  FRIENDLY, NEUTRAL, ENEMY, EMPTY, INVALID
};


//forward declarations
class Pilot;
class Map;


class System
{
protected:
  // quick reference to which derived type the System is
  System_Type type;
  
  std::string name;
  
  // true if player has visited
  bool visited;
  
  // adjacent systems
  std::vector<System*> neighbors;
  
  // for buying items
  std::vector<Item> store;
  std::vector<int> prices;
  
  // actions user can take
  Menu system_menu;
  
  // items user can buy with prices
  Menu store_menu;
  
  // universe this System is located in
  Map* map;
  
  // menu choice of first System jump option
  int first_jump_option;
  
  // the user
  Pilot* player;
  
  // key item name to find next
  std::string next_key;
  
  // create System menu header
  std::string gen_header();
  
  void ask_info();
  
  void buy_ship();
  
  void jump_to(int menu_op);
  
  void make_menu();
  
  void open_store();
  
  void refuel();
  
  void repair();
  
  void sell();
  
  void set_first_jump_option() { first_jump_option = type == EMPTY ? 4 : 10; }
  
  void view_map();
  
  // prevent instantiation
  System(std::string nm, const std::vector<Item>& items, System_Type st = INVALID) :
      type(st), name(nm), visited(false), next_key("Electron MipMap")
  {
    set_up_store(items);
    set_first_jump_option();
  }
  
public:
  virtual ~System() { }
  
  std::string get_name() const { return name; }
  
  std::string get_next_key() const { return next_key; }
  
  System_Type get_type() const { return type; }
  
  bool has_been_visited() { return visited; }
  
  void set_next_key(const std::string& key) { next_key = key; }
  
  void set_up_neighbors(System* const up, System* const rt, System* const dn, System* const lt)
  {
    // ensure the vector is empty
    neighbors.clear();
    
    neighbors.push_back(up);
    neighbors.push_back(rt);
    neighbors.push_back(dn);
    neighbors.push_back(lt);
  }
  
  void set_up_store(const std::vector<Item>& items);
  
  virtual void special() { visited = true; make_menu(); }

  void visit() { visited = true; }
};

#endif /* SYSTEM_HPP */
