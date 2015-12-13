/*********************************************************************
 ** Program Filename: Finale.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Finale class. This
 **              class displays a summary of the game just played.
 *********************************************************************/


#ifndef FINALE_HPP
#define FINALE_HPP

#include "Map.hpp"
#include "Pilot.hpp"


class Finale
{
private:
  Pilot* player;
  Map* map;
  
public:
  Finale(Pilot* p, Map* m) : player(p), map(m) { }
  
  void show();
};

#endif /* FINALE_HPP */
