/*********************************************************************
 ** Program Filename: FriendlySystem.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the FriendlySystem class.
 **              A FriendlySystem contains no enemies as well as a
 **              planet to land on.  Things cost less here.
 *********************************************************************/


#ifndef FRIENDLY_SYSTEM_HPP
#define FRIENDLY_SYSTEM_HPP

#include "System.hpp"
#include "Pilot.hpp"


class FriendlySystem : public System
{
public:
  FriendlySystem(std::string nm, const std::vector<Item>& items, Pilot* p, Map* m) :
          System(nm, items, FRIENDLY)
  {
    player = p;
    map = m;
  }
  
  virtual void special();
};

#endif /* FRIENDLY_SYSTEM_HPP */
