/*********************************************************************
 ** Program Filename: Windweeper.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Windweeper class.  A
 **              Windweeper is a weak, fast Fighter ship.
 *********************************************************************/


#ifndef WINDWEEPER_HPP
#define WINDWEEPER_HPP

#include "Fighter.hpp"


class Windweeper : public Fighter
{
public:
  Windweeper() : Fighter("Windweeper", 120, 8, 180, 4)
  {
    weapon = new Weapon("Sail Gun", 35, 0.8, false);
    set_description();
  }
  
  virtual ~Windweeper() { delete weapon; }
};

#endif /* WINDWEEPER_HPP */
