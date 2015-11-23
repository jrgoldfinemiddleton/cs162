/*********************************************************************
** Program Filename: Goblin.cpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the implementation of the Goblin class
**              member functions.
*********************************************************************/

#include "Goblin.hpp"


/*********************************************************************
** Function: Goblin::Goblin()
** Description: Constructs a Goblin object, intializing all member
**              variables inherited from the Creature class and
**              achilles_cut to false.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: all member variables are initialized
*********************************************************************/

Goblin::Goblin()
{
    // base class member variables
    armor = 3;
    strength = 8;
    name = "Goblin";

    // Goblin class member variable
    achilles_cut = false;
}


/*********************************************************************
** Function: Goblin::attack()
** Description: Determines the amount of the attack for the current
**              turn and returns it.  If the attack = 12, the Goblin
**              has slashed its enemy's Achilles tendon, so
**              achilles_cut is set to true.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: if attack = 12, achilles_cut = true; sum of dice
**                  rolls is returned
*********************************************************************/

int Goblin::attack()
{
    int dice = 2;
    int sides = 6;
    int sum = sum_dice(dice, sides);

    // the Goblin slashed the enemy's Achilles tendon
    if (sum == 12)
        achilles_cut = true;

    return sum;
}


/*********************************************************************
** Function: Goblin::defend()
** Description: Determines the amount of the defense for the current
**              turn and returns it.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the result of a die roll is returned
*********************************************************************/

int Goblin::defend()
{
    int dice = 1;
    int sides = 6;

    return sum_dice(dice, sides);
}


/*********************************************************************
** Function: Goblin::take_damage()
** Description: Calculates the damage taken in the current turn,
**              reduces strength accordingly, then returns the damage.
**              If the enemy's Achilles tendon was cut, his attack is
**              cut by 50%.
** Parameters: attack   enemy's attack for this turn
**             defense  this Creature's defense for this turn
** Pre-Conditions: attack and defense are non-negative, strength > 0
** Post-Conditions: strength reduced by damage calculated, amount of
**                  damage done returned
*********************************************************************/

int Goblin::take_damage(int attack, int defense)
{
    // cut enemy attack in half for Achilles tendon slash
    if (achilles_cut)
        attack /= 2;

    return Creature::take_damage(attack, defense);
}


/*********************************************************************
** Function: Goblin::revive()
** Description: Resets strength to its original value and sets
**              achilles_cut back to false.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: strength is restored to its original value,
**                  achilles_cut is restored to false
*********************************************************************/

void Goblin::revive()
{
    strength = 8;
    achilles_cut = false;
}


/*********************************************************************
** Function: Goblin::get_achilles()
** Description: Returns whether this Goblin has slashed its opponent's
**              Achilles tendon.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if the opponents Achilles tendon was
**                  cut and false otherwise
*********************************************************************/

bool Goblin::get_achilles()
{
    return achilles_cut;
}
