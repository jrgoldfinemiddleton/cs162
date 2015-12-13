/*********************************************************************
 ** Program Filename: TaxEvent.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              TaxEvent class.
 *********************************************************************/


#include "TaxEvent.hpp"


/*********************************************************************
 ** Function: TaxEvent::run()
 ** Description: Taxes the user a random sum of money.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 ** Post-Conditions: player has less money, but never less than 0.
 *********************************************************************/

void TaxEvent::run()
{
  int tax = rand() % 1000 + 1;
  std::cout << "You've unfortunately arrived at tax time.  You must pay " << tax << " ducat" <<
  (tax == 1 ? "!" : "s!") << "\n\n";
  
  player->gain_money(-tax);
  complete = true;
}