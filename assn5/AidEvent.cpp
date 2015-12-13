/*********************************************************************
 ** Program Filename: AidEvent.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              AidEvent class.
 *********************************************************************/


#include <cstdlib>    // rand()
#include <iostream>   // std::cin, std::cout
#include <vector>     // std::vector
#include <limits>     // std::numeric_limits

#include "AidEvent.hpp"
#include "utilities.hpp"


// export static const members
const int AidEvent::DONT_HELP;
const int AidEvent::FREE_HELP;
const int AidEvent::PAID_HELP;


/*********************************************************************
 ** Function: AidEvent::run()
 ** Description: Determines whether the user's Fighter will receive
 **              fuel aid this turn and whether it will have to be
 **              paid for.  Only relevant when the Fighter is out of
 **              fuel and the current System is an EmptySystem.
 ** Parameters: none
 ** Pre-Conditions: srand() has been called
 *********************************************************************/

void AidEvent::run()
{
  std::cout << "You are out of fuel.  ";
  
  // see if potential help arrives
  bool ship_arrives = rand() % 100 + 1 <= SHIP_ARRIVES;
  
  if (ship_arrives)
  {
    std::vector<int> outcomes;
    outcomes.push_back(DONT_HELP);
    outcomes.push_back(FREE_HELP);
    outcomes.push_back(PAID_HELP);
    
    std::vector<int> freq;
    freq.push_back(25);
    freq.push_back(25);
    freq.push_back(50);
    
    // figure out if the arriving ship will help the player
    int outcome = utilities::random_from_frequency_map(outcomes, freq);
    
    std::cout << "A ship has entered this sector of space and you've managed to get in contact with " <<
                 "its pilot.  ";
    
    switch (outcome)
    {
      case DONT_HELP:
      {
        std::cout << "Unfortunately, the ship's pilot is unwilling to help you.\n\n";
        
        break;
      }
      case FREE_HELP:
      {
        std::cout << "The ship's pilot is in a good mood!  He has offered to give you some fuel.  " <<
                     "You're good to go now.  Try to be more careful in the future.\n\n";
        player->restore_half_fuel();
        
        break;
      }
      case PAID_HELP:
      {
        paid_help();
        
        break;
      }
      default:
      {
        std::cerr << "Whoops!  Something inexplicable occurred!  You're SOL.\n\n";
      }
    }
  }
  
  else
    std::cout << "Unfortunately no help arrived for you.\n\n";
  
  complete = true;
}


/*********************************************************************
 ** Function: AidEvent::paid_help()
 ** Description: Allow the user a chance to pay for help refueling.
 **              The other ship will expect a random amount of money.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 *********************************************************************/

void AidEvent::paid_help()
{
  // max other pilot could hope for
  const int MAX = 3000;
  
  // how much the other pilot really wants
  int threshold = rand() % MAX + 1;
  
  std::cout << "The ship's pilot is a bit of a businessman.  Would you like to offer him some " <<
               "money in hopes of getting him to help you? (y/n)\n";
  
  char c;
  c = std::cin.get();
  
  // clear any extra chars the user may have entered
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  if (c == 'y' || c == 'Y')
  {
    std::cout << MAX << " ducats would guarantee assistance.  " <<
                 "How many ducats would you like to offer? ";
    
    // max price user allowed to pay
    int upper_limit = MAX < player->get_money() ? MAX : player->get_money();
    
    // user's offer
    int offer = utilities::get_valid_int_in_range(0, upper_limit);
    
    // cool, the other pilot has accepted the user's offer
    if (offer >= threshold)
    {
      std::cout << "\nAwesome!  He has agreed to help out.  Try to be more careful in the future.\n\n";
      player->restore_half_fuel();
      player->gain_money(-offer);
    }
    
    else
      std::cout << "\nDamnation!  He has refused your offer.  You're lucky the scumbag didn't try " <<
                   "to blow up your ship at least!\n\n";
  }
}