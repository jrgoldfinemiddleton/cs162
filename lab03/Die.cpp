/*********************************************************************
 ** Program Filename: Die.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/13/15
 ** Description: The Die class implementation file.  Some members have
 **              had their names changed to work with LoadedDie.
 ** Input: N/A
 ** Output: N/A
 *********************************************************************/

#include "Die.h"

#include <cstdlib>  // for rand()
#include <iostream> // for std::cout


/*********************************************************************
 ** Function: Die()
 ** Description: Constructs a balanced Die.
 ** Parameters: sides - number of sides
 ** Pre-Conditions: sides must be positive
 ** Post-Conditions: the Die is created and its number of sides is
 **                  determined
 *********************************************************************/

Die::Die(int sides)
{
    num_sides = sides;
}


/*********************************************************************
 ** Function: ~Die()
 ** Description: Destructs this Die.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: the Die is created
 *********************************************************************/

Die::~Die()
{
    // nothing to do
}

/*********************************************************************
 ** Function: die_roll()
 ** Description: Rolls the Die, returning a value between 1 and the
 **              number of sides.
 ** Parameters: none
 ** Pre-Conditions: srand() must have already been run
 ** Post-Conditions: an integer value between 1 and the number of sides
 **                  is returned
 *********************************************************************/

int Die::die_roll()
{
    int roll = rand() % num_sides + 1;
    std::cout << "the die roll was " << roll << '\n';
    return roll;
}
    
