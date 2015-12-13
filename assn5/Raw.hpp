/*********************************************************************
 ** Program Filename: Raw.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Raw class.  A Raw
 **              is a moderately powerful, slow Fighter ship.
 *********************************************************************/


#ifndef RAW_HPP
#define RAW_HPP

#include "Fighter.hpp"


class Raw : public Fighter
{
public:
  Raw() : Fighter("R.A.W.", 210, 10, 105, 4)
  {
    weapon = new Weapon("Nut Blaster", 35, 0.6, true);
    set_description();
  }
  
  virtual ~Raw() { delete weapon; }
};

#endif /* RAW_HPP */
