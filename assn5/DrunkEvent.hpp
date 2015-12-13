/*********************************************************************
 ** Program Filename: DrunkEvent.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the DrunkEvent class.  A
 **              DrunkEvent occurs when the user wants to relax and
 **              and unwind.
 *********************************************************************/


#ifndef DRUNK_EVENT_HPP
#define DRUNK_EVENT_HPP

#include <string>

#include "Event.hpp"

class DrunkEvent : public Event
{
private:
  std::string system_name;
  int days;
  
public:
  DrunkEvent(Pilot* p, int days) : Event(p), system_name(p->get_cur_system()->get_name()), days(days) { }
  
  virtual void run();
};

#endif /* DRUNK_EVENT_HPP */
