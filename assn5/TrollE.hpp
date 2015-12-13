/*********************************************************************
 ** Program Filename: TrollE.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the TrollE class.  A
 **              TrollE is a weak, slow Fighter ship.
 *********************************************************************/


#ifndef TROLL_E_HPP
#define TROLL_E_HPP

#include "Fighter.hpp"


class TrollE : public Fighter
{
public:
  TrollE() : Fighter("TrollE", 200, 6, 100, 10)
  {
    weapon = new Weapon("Photon Scream", 30, 0.7, false);
    set_description();
  }
  
  virtual ~TrollE() { delete weapon; }
};

#endif /* TROLL_E_HPP */
