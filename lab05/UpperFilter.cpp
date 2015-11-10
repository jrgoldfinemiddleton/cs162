/*********************************************************************
 ** Program Filename: UpperFilter.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the member function implementation
 **              for the UpperFilter class.
 ** Input: std::ifstream, char
 ** Output: std::ofstream
 *********************************************************************/

#include "UpperFilter.hpp"


/*********************************************************************
 ** Function: UpperFilter::transform()
 ** Description: Returns the uppercase form of ch if ch is a letter or
 **              else just returns ch.
 ** Parameters: ch  the input character
 ** Pre-Conditions: none
 ** Post-Conditions: if ch is a lowercase letter, returns the
 **                  uppercase equivalent; otherwise returns a copy of
 **                  ch
 *********************************************************************/

char UpperFilter::transform(char ch)
{
    // difference between a capital and a lowercase letter
    // static so it's only calculated once
    static const int diff = static_cast<int>('A' - 'a');

    // only capitalize lowercase letters
    if (ch >= 'a' && ch <= 'z')
        ch += diff;

    return ch;
}


