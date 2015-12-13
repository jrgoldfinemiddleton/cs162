/*********************************************************************
 ** Program Filename: Suxel.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Suxel class.  A Suxel
 **              is a moderately powerful, somewhat slow Fighter ship.
 *********************************************************************/


#ifndef SUXEL_HPP
#define SUXEL_HPP

#include "Fighter.hpp"


class Suxel : public Fighter
{
public:
  Suxel() : Fighter("003SI Suxel", 270, 15, 140, 5)
  {
    weapon = new Weapon("Doom Snappers", 45, 0.3, true);
    set_description();
  }
  
  virtual ~Suxel() { delete weapon; }
};

#endif /* SUXEL_HPP */
