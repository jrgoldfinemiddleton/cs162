/*********************************************************************
 ** Program Filename: MonetaryEvent.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the MonetaryEvent class.
 **              A MonetaryEvent represents an opportunity for the
 **              user to find some money.
 *********************************************************************/


#ifndef MONETARY_EVENT_HPP
#define MONETARY_EVENT_HPP

#include <cstdlib>
#include <iostream>

#include "Event.hpp"


class MonetaryEvent : public Event
{
public:
  MonetaryEvent(Pilot* p) : Event(p) { }
  
  virtual void run();
};


#endif /* MONETARY_EVENT_HPP */
