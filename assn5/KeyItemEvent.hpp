/*********************************************************************
 ** Program Filename: KeyItemEvent.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the KeyItemEvent class.
 **              A KeyItemEvent represents an opportunity for the
 **              user to pick up the next key Item needed.
 *********************************************************************/


#ifndef KEY_ITEM_EVENT_HPP
#define KEY_ITEM_EVENT_HPP

#include <string>

#include "Event.hpp"

class KeyItemEvent : public Event
{
private:
  Item* key_item;
  
public:
  KeyItemEvent(Pilot* p, Item* key) : Event(p), key_item(key) { }
  
  virtual void run();
};

#endif /* KEY_ITEM_EVENT_HPP */
