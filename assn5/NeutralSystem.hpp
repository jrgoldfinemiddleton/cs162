/*********************************************************************
 ** Program Filename: NeutralSystem.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the NeutralSystem class.
 **              A NeutralSystem contains fewer enemies and more allies
 **              than an EnemySystem as well as a planet to land on.
 *********************************************************************/


#ifndef NEUTRAL_SYSTEM_HPP
#define NEUTRAL_SYSTEM_HPP

#include <string>

#include "System.hpp"
#include "Pilot.hpp"


class NeutralSystem : public System
{
private:
  
public:
  NeutralSystem(std::string nm, const std::vector<Item>& items, Pilot* p, Map* m) :
          System(nm, items, NEUTRAL)
  {
    player = p;
    map = m;
  }
  
  virtual void special();
};

#endif /* NEUTRAL_SYSTEM_HPP */
