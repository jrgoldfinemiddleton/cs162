/*********************************************************************
** Program Filename: Barbarian.cpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
** Description: Contains the implementation of the Barbarian class
**              member functions.
*********************************************************************/

#include "Barbarian.hpp"


/*********************************************************************
** Function: Barbarian::Barbarian()
** Description: Constructs a Barbarian object, intializing all member
**              variables inherited from the Creature class.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

Barbarian::Barbarian()
{
    armor = 0;
    strength = 12;
    name = "Barbarian";
}


/*********************************************************************
** Function: Barbarian::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int Barbarian::attack()
{
    int dice = 2;
    int sides = 6;
    int sum = sum_dice(dice, sides);

    return sum;
}


/*********************************************************************
** Function: Barbarian::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int Barbarian::defend()
{
    int dice = 2;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: Barbarian::revive()
** Description: Restores some or potentially all health and increases
**              this Creature's points.
** Parameters: none
** Pre-Conditions: this Creature KOed an opponent
** Post-Conditions: strength is restored by a random amount
*********************************************************************/

void Barbarian::revive()
{
    int heal = rand() % 7 + 3;
    int raw_strength = strength + heal;
    if (raw_strength > 12)
        strength = 12;
    else
        strength = raw_strength;

    points += 2;
}
