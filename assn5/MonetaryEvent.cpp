/*********************************************************************
 ** Program Filename: MonetaryEvent.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              MonetaryEvent class.
 *********************************************************************/


#include "MonetaryEvent.hpp"


/*********************************************************************
 ** Function: MonetaryEvent::run()
 ** Description: Gives the user a random sum of money.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 ** Post-Conditions: player has more money
 *********************************************************************/

void MonetaryEvent::run()
{
  int find = rand() % 3000 + 1;
  std::cout << "You've luckily come upon " << find << " ducat" << (find == 1 ? "!" : "s!") << "\n\n";
  
  player->gain_money(find);
  complete = true;
}