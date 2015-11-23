/*********************************************************************
** Program Filename: Barbarian.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the derived Barbarian class definition and
**              member declarations.
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian :
    public Creature
{
public:
    Barbarian();
    virtual int attack();
    virtual int defend();
    virtual void revive();
};

#endif

