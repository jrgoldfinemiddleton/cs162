/*********************************************************************
** Program Filename: BlueMen.cpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the implementation of the BlueMen class
**              member functions.
*********************************************************************/

#include "BlueMen.hpp"


/*********************************************************************
** Function: BlueMen::BlueMen()
** Description: Constructs a BlueMen object, intializing all member
**              variables inherited from the Creature class.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

BlueMen::BlueMen()
{
    armor = 3;
    strength = 12;
    name = "Blue Men";
}


/*********************************************************************
** Function: BlueMen::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int BlueMen::attack()
{
    int dice = 2;
    int sides = 10;
    int sum = sum_dice(dice, sides);

    return sum;
}


/*********************************************************************
** Function: BlueMen::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int BlueMen::defend()
{
    int dice = 3;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: BlueMen::revive()
** Description: Resets strength to its original value.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: strength is restored to its original value
*********************************************************************/

void BlueMen::revive()
{
    strength = 12;
}
