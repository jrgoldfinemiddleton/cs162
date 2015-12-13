/*********************************************************************
 ** Program Filename: FightEvent.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the FightEvent class.  A
 **              FightEvent represents an ambush by enemy ships, the
 **              arrival of allies, and the teamfight thereafter.  A
 **              user loses the game if his/her ship is defeated here.
 *********************************************************************/


#ifndef FIGHT_EVENT_HPP
#define FIGHT_EVENT_HPP

#include <vector>

#include "Event.hpp"
#include "Fighter.hpp"
#include "Bolq.hpp"
#include "Lamborqini.hpp"
#include "Raw.hpp"
#include "SleazeLiner.hpp"
#include "Suxel.hpp"
#include "TrollE.hpp"
#include "Voltsweeper.hpp"
#include "Windweeper.hpp"
#include "Item.hpp"


enum Role { PLAYER, AL, EN };


class FightEvent : public Event
{
private:
  std::vector<Fighter*> allies;
  std::vector<Fighter*> enemies;
  
  void attack_area(Fighter* attacker, Role side, int attk, std::vector<Fighter*>& opponents);
  
  void attack_one(Fighter* attacker, Role side, int attk, Fighter* defender, std::vector<Fighter*>& opp_team, int opp_pos);
  
  int get_modified_attack();
  
  int get_modified_armor();
  
  int get_modified_health();
  
  int get_modified_speed();
  
  int get_max_speed();
  
  Fighter* get_random_ship();
  
  bool is_enemy(Fighter* f);
  
  bool is_ally(Fighter* f);
  
  void find_allies(int number);
  void find_enemies(int number);
  void print_allies();
  void print_enemies();
  
  static bool comp_speed(Fighter* f1, Fighter* f2);
  
public:
  FightEvent(Pilot* p, int allies, int enemies);
  virtual void run();
};

#endif /* FIGHT_EVENT_HPP */
