/*********************************************************************
 ** Program Filename: KeyItemEvent.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              KeyItemEvent class.
 *********************************************************************/


#include <iostream>

#include "KeyItemEvent.hpp"


/*********************************************************************
 ** Function: KeyItemEvent::run()
 ** Description: Adds the next key Item to the user's collection if
 **              there is room.
 ** Parameters: none
 *********************************************************************/

void KeyItemEvent::run()
{
  if (!(player->has_room()))
    std::cout << "You've found " << key_item->get_name() << ".  Unfortunately you don't have room for it" <<
                 " right now.  Come back after you have removed an item.\n\n";
  
  else
  {
    std::cout << "You've found " << key_item->get_name() << " at long last!!\n\n";
    player->gain_item(*key_item);
    complete = true;
  }
}