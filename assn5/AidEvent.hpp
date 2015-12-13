/*********************************************************************
 ** Program Filename: AidEvent.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the AidEvent class.  An
 **              AidEvent represents an opportunity for the user's
 **              ship to be refueled in an EmptySystem.
 *********************************************************************/


#ifndef AID_EVENT_HPP
#define AID_EVENT_HPP

#include "Event.hpp"


class AidEvent : public Event
{
private:
  static const int SHIP_ARRIVES = 60;
  static const int DONT_HELP = 0;
  static const int FREE_HELP = 1;
  static const int PAID_HELP = 2;
  
  void paid_help();
  
public:
  AidEvent(Pilot* p) : Event(p) { }
  
  virtual void run();
};

#endif /* AID_EVENT_HPP */
