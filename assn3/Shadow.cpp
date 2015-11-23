/*********************************************************************
** Program Filename: Shadow.cpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the implementation of the Shadow class
**              member functions.
*********************************************************************/

#include "Shadow.hpp"


/*********************************************************************
** Function: Shadow::Shadow()
** Description: Constructs a Shadow object, intializing all member
**              variables inherited from the Creature class.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

Shadow::Shadow()
{
    armor = 0;
    strength = 12;
    name = "The Shadow";
}


/*********************************************************************
** Function: Shadow::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: sum of dice rolls is returned
*********************************************************************/

int Shadow::attack()
{
    int dice = 2;
    int sides = 10;
    int sum = sum_dice(dice, sides);

    return sum;
}


/*********************************************************************
** Function: Shadow::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the result of a die roll is returned
*********************************************************************/

int Shadow::defend()
{
    int dice = 1;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: Shadow::take_damage()
** Description: Calculates the damage taken in the current turn,
**              reduces strength accordingly, then returns the damage.
**              50% of the time no damage is done.
** Parameters: attack   enemy's attack for this turn
**             defense  this Creature's defense for this turn
** Pre-Conditions: attack and defense are non-negative, strength > 0
** Post-Conditions: strength reduced by damage calculated, amount of
**                  damage done returned
*********************************************************************/

int Shadow::take_damage(int attack, int defense)
{
    // if Shadow avoids the attack, apply no damage and return 0
    if (rand() % 2)
        return 0;

    return Creature::take_damage(attack, defense);
}


/*********************************************************************
** Function: Shadow::revive()
** Description: Resets strength to its original value.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: strength is restored to its original value
*********************************************************************/

void Shadow::revive()
{
    strength = 18;
}

