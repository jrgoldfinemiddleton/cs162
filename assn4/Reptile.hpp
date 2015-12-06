/*********************************************************************
** Program Filename: Reptile.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the derived Reptile class definition and
**              member declarations.
*********************************************************************/

#ifndef REPTILE_HPP
#define REPTILE_HPP

#include "Creature.hpp"

class Reptile :
    public Creature
{
public:
    Reptile();
    virtual int attack();
    virtual int defend();
    virtual void revive();
};

#endif