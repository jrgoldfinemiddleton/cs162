/*********************************************************************
 ** Program Filename: LoadedDie.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/26/15
 ** Description: The LoadedDie class implementation file.
 ** Input: N/A
 ** Output: N/A
 *********************************************************************/

#include "LoadedDie.hpp"

#include <cstdlib>  // for rand()


/*********************************************************************
 ** Function: LoadedDie()
 ** Description: Constructs a LoadedDie.
 ** Parameters: sides - the number of sides
 ** Pre-Conditions: sides must be positive
 ** Post-Conditions: distributionArr will point to an array on the
 **                  heap; the array will be filled with values equal
 **                  to those of the sides of the LoadedDie, with
 **                  greater values occurring more frequently
 *********************************************************************/

LoadedDie::LoadedDie(int sides)
{
    numSides = sides;

    // map a random value to a side of a loaded die
    distributionArr = new int[sumSides()];

    // where to start putting the next die value
    int startIndex = 0;

    // fill up the distribution array such that the higher the side
    // of the die is, the more random values (indices) will match it
    for (int sideValue = 1; sideValue <= numSides; ++sideValue)
    {
        int endIndex = startIndex + sideValue;
        for (int index = startIndex; index < endIndex; ++index)
        {
           distributionArr[index] = sideValue;
        }
        startIndex = endIndex;
    } 
}


/*********************************************************************
 ** Function: ~LoadedDie()
 ** Description: The destructor for LoadedDie.
 ** Parameters: N/A
 ** Pre-Conditions: distributionArr is not deallocated
 ** Post-Conditions: distributionArr is deallocated
 *********************************************************************/

LoadedDie::~LoadedDie()
{
    delete distributionArr;
}


/*********************************************************************
 ** Function: getRoll()
 ** Description: Rolls the LoadedDie, returning a value between 1 and
 **              the number of sides. 
 ** Parameters: none
 ** Pre-Conditions: srand() must have already been run; distributionArr
 **                 must contain sumSides() elements ranging in value
 **                 from 1 to numSides
 ** Post-Conditions: an integer value between 1 and the number of sides
 **                  is returned
 *********************************************************************/

int LoadedDie::getRoll()
{
    int distributionIndex = rand() % sumSides();

    int roll = distributionArr[distributionIndex];
    
    return roll;
}


/*********************************************************************
 ** Function: sumSides()
 ** Description: Returns the sum of all values on the sides of the
 **              LoadedDie.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: the sum of all sides is returned
 *********************************************************************/

int LoadedDie::sumSides()
{
    int sum = 0;

    for (int sideValue = 1; sideValue <= numSides; ++sideValue)
    {
        sum += sideValue;
    }

    return sum;
}
