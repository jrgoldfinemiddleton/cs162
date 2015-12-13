/*********************************************************************
 ** Program Filename: DrunkEvent.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              DrunkEvent class.
 *********************************************************************/


#include <unistd.h>       // usleep()

#include "DrunkEvent.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: DrunkEvent::run()
 ** Description: Makes the user get drunk and waste turns.
 ** Parameters: none
 *********************************************************************/

void DrunkEvent::run()
{
  std::cout << "You decided to relax and unwind...\n";
  
  usleep(700000);
  
  std::cout << "It appears that you have had a bit too much fun.  The last thing you " <<
               "remember before finding yourself in the hospital was dancing around by " <<
               "the edge of a cliff.  Good thing the planet you were on has very little gravity!  " <<
               "Point is, you were in the hospital for " << days << " turns.  :(\n\n";
  
  utilities::wait_for_user();
}