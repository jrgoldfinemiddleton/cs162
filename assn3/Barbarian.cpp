/*********************************************************************
** Program Filename: Barbarian.cpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
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
** Description: Resets strength to its original value.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: strength is restored to its original value
*********************************************************************/

void Barbarian::revive()
{
    strength = 12;
}
