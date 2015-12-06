/*********************************************************************
** Program Filename: BlueMen.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the derived BlueMen class definition and
**              member declarations.
*********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Creature.hpp"

class BlueMen :
    public Creature
{
public:
    BlueMen();
    virtual int attack();
    virtual int defend();
    virtual void revive();
};

#endif
