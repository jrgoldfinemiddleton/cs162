/*********************************************************************
 ** Program Filename: EnemySystem.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the EnemySystem class.
 **              An EnemySystem contains more enemies and fewer allies
 **              than a NeutralSystem as well as a planet to land on.
 **              Things cost more here.
 *********************************************************************/


#ifndef ENEMY_SYSTEM_HPP
#define ENEMY_SYSTEM_HPP

#include "Map.hpp"
#include "Pilot.hpp"
#include "System.hpp"


class EnemySystem : public System
{
public:
  EnemySystem(std::string nm, const std::vector<Item>& items, Pilot* p, Map* m) :
            System(nm, items, ENEMY)
  {
    player = p;
    map = m;
  }
  
  virtual void special();
};

#endif /* ENEMY_SYSTEM_HPP */
