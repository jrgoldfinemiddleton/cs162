/*********************************************************************
 ** Program Filename: SleazeLiner.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the SleazeLiner class.  A
 **              SleazeLiner is a moderately powerful, slow Fighter
 **              ship.
 *********************************************************************/


#ifndef SLEAZE_LINER_HPP
#define SLEAZE_LINER_HPP

#include "Fighter.hpp"


class SleazeLiner : public Fighter
{
public:
  SleazeLiner() : Fighter("Sleaze Liner", 280, 8, 100, 7)
  {
    weapon = new Weapon("Metal Wrecker", 45, 0.6, true);
    set_description();
  }

  virtual ~SleazeLiner() { delete weapon; }
};

#endif /* SLEAZE_LINER_HPP */
