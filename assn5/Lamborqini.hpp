/*********************************************************************
 ** Program Filename: Lamborqini.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Lamborqini class.  A
 **              Lamborqini is a powerful, fast Fighter ship.
 *********************************************************************/


#ifndef LAMBORQINI_HPP
#define LAMBORQINI_HPP

#include "Fighter.hpp"


class Lamborqini : public Fighter
{
public:
  Lamborqini() : Fighter("Lamborqini", 340, 4, 250, 2)
  {
    weapon = new Weapon("Fissile Missile", 100, 0.8, false);
    set_description();
  }
  
  virtual ~Lamborqini() { delete weapon; }
};

#endif /* LAMBORQINI_HPP */
