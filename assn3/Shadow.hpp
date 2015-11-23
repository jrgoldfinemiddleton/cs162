/*********************************************************************
** Program Filename: Shadow.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the derived Shadow class definition and
**              member declarations.  Unlike the other derived
**              classes derived from Creature, this class has a
**              special ability that allows it to dodge attacks 50% of
**              the time.
*********************************************************************/

#ifndef SHADOW_HPP
#define SHADOW_HPP

#include "Creature.hpp"

class Shadow :
    public Creature
{
public:
    Shadow();
    virtual int attack();
    virtual int defend();
    virtual int take_damage(int attack, int defense);
    virtual void revive();
};

#endif