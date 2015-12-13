/*********************************************************************
 ** Program Filename: Event.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Event class.  An
 **              Event represents an occurrence that the user may
 **              experience while in a System.
 *********************************************************************/


#ifndef EVENT_HPP
#define EVENT_HPP

#include "Pilot.hpp"


class Event
{
protected:
  Pilot* player;
  bool complete;
  
  Event(Pilot* p) : player(p), complete(false) { }
  
public:
  bool done() const { return complete; }
  
  virtual void run() = 0;
};

#endif /* EVENT_HPP */
