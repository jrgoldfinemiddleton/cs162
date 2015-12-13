/*********************************************************************
 ** Program Filename: Game.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Game class. The game
 **              class controls the logic for the gameplay.
 *********************************************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include "Item.hpp"
#include "Map.hpp"
#include "Pilot.hpp"
#include "utilities.hpp"

#include <iostream>
#include <string>
#include <vector>


class Game
{
private:
  static const int MAX_TICKS = 75;
  
  std::vector<Item> reg_items;
  
  std::vector<Item> key_items;
  
  Pilot* player;
  
  Map* universe;
  
  int cur_tick;
  
  // index of next key item
  int next_key;
  
  // name of System with next key item
  std::string key_loc;
  
  void hide_next_key_item();
  
  void move_next_key_item();
  
public:
  Game();
  
  ~Game() { delete player; delete universe; }
  
  void init_items();
  
  void play();
  
  static void hints();
  
  static void story();
};

#endif /* GAME_HPP */