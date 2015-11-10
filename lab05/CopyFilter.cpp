/*********************************************************************
 ** Program Filename: CopyFilter.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the member function implementation
 **              for the CopyFilter class.
 ** Input: char
 ** Output: char
 *********************************************************************/

#include "CopyFilter.hpp"


/*********************************************************************
 ** Function: CopyFilter::transform()
 ** Description: Returns a copy of the char passed in.  This function
 **              overrides FileFilter::transform().
 ** Parameters: ch  the input character
 ** Pre-Conditions: none
 ** Post-Conditions: a copy of ch is returned
 *********************************************************************/

char CopyFilter::transform(char ch)
{
    return ch;
}
