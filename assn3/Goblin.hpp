/*********************************************************************
** Program Filename: Goblin.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the derived Goblin class definition and
**              member declarations.  Unlike the other derived
**              classes derived from Creature, this class has a
**              special ability where, if it rolls a total of 12
**              during an attack, it cuts the opponent's attack by 50%
**              for the rest of the combat session.
*********************************************************************/

#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Creature.hpp"

class Goblin :
    public Creature
{
private:
    // true if the enemy's Achilles tendon has been slashed
    bool achilles_cut;

public:
    Goblin();
    virtual int attack();
    virtual int defend();
    virtual int take_damage(int attack, int defense);
    virtual void revive();
    bool get_achilles();
};

#endif
