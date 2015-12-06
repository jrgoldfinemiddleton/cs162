/*********************************************************************
** Program Filename: Reptile.cpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
** Description: Contains the implementation of the Reptile class
**              member functions.
*********************************************************************/

#include "Reptile.hpp"


/*********************************************************************
** Function: Reptile::Reptile()
** Description: Constructs a Reptile object, intializing all member
**              variables inherited from the Creature class.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

Reptile::Reptile()
{
    armor = 7;
    strength = 18;
    name = "Reptile Person";
}


/*********************************************************************
** Function: Reptile::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int Reptile::attack()
{
    int dice = 3;
    int sides = 6;
    int sum = sum_dice(dice, sides);

    return sum;
}


/*********************************************************************
** Function: Reptile::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the result of a die roll is returned
*********************************************************************/

int Reptile::defend()
{
    int dice = 1;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: Reptile::revive()
** Description: Restores some or potentially all health and increases
**              this Creature's points.
** Parameters: none
** Pre-Conditions: this Creature KOed an opponent
** Post-Conditions: strength is restored by a random amount
*********************************************************************/

void Reptile::revive()
{
    int heal = rand() % 7 + 6;
    int raw_strength = strength + heal;
    if (raw_strength > 18)
        strength = 18;
    else
        strength = raw_strength;

    points += 2;    
}
