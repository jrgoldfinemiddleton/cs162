/*********************************************************************
 ** Program Filename: Die.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/26/15
 ** Description: The Die class implementation file.
 ** Input: N/A
 ** Output: N/A
 *********************************************************************/

#include "Die.hpp"

#include <cstdlib>  // for rand()


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
    numSides = sides;
}


/*********************************************************************
 ** Function: getRoll()
 ** Description: Rolls the Die, returning a value between 1 and the
 **              number of sides.
 ** Parameters: none
 ** Pre-Conditions: srand() must have already been run
 ** Post-Conditions: an integer value between 1 and the number of sides
 **                  is returned
 *********************************************************************/

int Die::getRoll()
{
    return rand() % numSides + 1;
}
    
