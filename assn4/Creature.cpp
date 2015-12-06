/*********************************************************************
** Program Filename: Creature.cpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the implementation of the Creature class
**              member functions.
*********************************************************************/

#include "Creature.hpp"
#include <cstdlib>
#include <ctime>


/*********************************************************************
** Function: Creature::Creature()
** Description: Constructs a Creature object but does not initialize
**              any data members.  This is left to the constructors in
**              the derived classes.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: a random seed is generated
*********************************************************************/

Creature::Creature() : points(0)
{
    rand();
}


/*********************************************************************
** Function: Creature::take_damage()
** Description: Calculates the damage taken in the current turn,
**              reduces strength accordingly, then returns the damage.
** Parameters: attack   enemy's attack for this turn
**             defense  this Creature's defense for this turn
** Pre-Conditions: attack and defense are non-negative, strength > 0
** Post-Conditions: strength reduced by damage calculated, amount of
**                  damage done returned
*********************************************************************/

int Creature::take_damage(int attack, int defense)
{
    attack -= armor;
    int damage = attack - defense;

    if (damage > 0)
    {
        strength -= damage;
        return damage;
    }

    return 0;
}


/*********************************************************************
** Function: Creature::is_dead()
** Description: Returns true if strength <= 0, false otherwise.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns true if dead, false if still alive
*********************************************************************/

bool Creature::is_dead()
{
    return strength <= 0;
}


/*********************************************************************
** Function: Creature::sum_dice()
** Description: Rolls num_dice dice with specified sides each, and
**              returns their sum.
** Parameters: num_dice     number of dice to roll
**             sides        number of sides per die
** Pre-Conditions: num_dice and sides are both positive
** Post-Conditions: returns a positive integer equal to the sum of the
**                  dice rolls
*********************************************************************/

int Creature::sum_dice(int num_dice, int sides)
{
    int sum(0);
    for (int die = 0; die < num_dice; ++die)
        sum += rand() % sides + 1;

    return sum;
}


/*********************************************************************
** Function: Creature::get_name()
** Description: Returns the name of this Creature's type.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: the name of this type is returned
*********************************************************************/

std::string Creature::get_name()
{
    return name;
}
