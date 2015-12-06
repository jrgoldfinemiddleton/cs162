/*********************************************************************
** Program Filename: Creature.hpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
** Description: Contains the abstract Creature class definition and
**              member declarations.
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <cstdlib>  // for rand()
#include <string>   // for std::string

class Creature
{
protected:
    int armor;
    int strength;
    std::string name;
    int points;         // keep track of success in tournament

public:
    Creature();
    virtual int attack() = 0;
    virtual int defend() = 0;
    virtual int take_damage(int attack, int defense);
    virtual void revive() = 0;
    bool is_dead();

    // helper for the attack() and defend() functions
    int sum_dice(int num_dice, int sides);

    std::string get_name();
    int get_points() { return points; }
};

#endif
