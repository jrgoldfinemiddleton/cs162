/*********************************************************************
 ** Program Filename: Voltsweeper.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Voltsweeper class.  A
 **              Voltsweeper is a weak, fast Fighter ship.
 *********************************************************************/


#ifndef VOLTSWEEPER_HPP
#define VOLTSWEEPER_HPP

#include "Fighter.hpp"


class Voltsweeper : public Fighter
{
public:
  Voltsweeper() : Fighter("Voltsweeper", 150, 6, 200, 3)
  {
    weapon = new Weapon("Trail Gun", 20, 1.0, false);
    set_description();
  }
  
  virtual ~Voltsweeper() { delete weapon; }
};

#endif /* VOLTSWEEPER_HPP */