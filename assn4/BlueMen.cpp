/*********************************************************************
** Program Filename: BlueMen.cpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
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
** Description: Restores some or potentially all health and increases
**              this Creature's points.
** Parameters: none
** Pre-Conditions: this Creature KOed an opponent
** Post-Conditions: strength is restored by a random amount
*********************************************************************/

void BlueMen::revive()
{
    int heal = rand() % 5 + 2;
    int raw_strength = strength + heal;
    if (raw_strength > 12)
        strength = 12;
    else
        strength = raw_strength;

    points += 1;
}
