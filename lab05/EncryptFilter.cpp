/*********************************************************************
 ** Program Filename: EncryptFilter.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the function member implementation
 **              for the EncryptFilter class.
 ** Input: std::ifstream, int key
 ** Output: std::ofstream
 *********************************************************************/

#include "EncryptFilter.hpp"


/*********************************************************************
 ** Function: EncryptFilter::EncryptFilter()
 ** Description: Constructs a new EncryptFilter object and sets the
 **              encryption key to k.
 ** Parameters: k   the value of the encryption key
 ** Pre-Conditions: k >= 0
 ** Post-Conditions: the const int key is initialized, a new object
 **                  is created
 *********************************************************************/

EncryptFilter::EncryptFilter(int k) : key(k) { }


/*********************************************************************
 ** Function: EncryptFilter::transform()
 ** Description: Returns a new character determined from applying the
 **              encryption key member constant to the input ch.  Uses
 **              a simple Caesar cypher algorithm which only applies
 **              to alphabetic characters.
 ** Parameters: ch  the character to be encrypted
 ** Pre-Conditions: none
 ** Post-Conditions: an encrypted character is returned, unless ch is
 **                  non-alphabetic, in which case ch is returned.
 *********************************************************************/

char EncryptFilter::transform(char ch)
{
    // non-alphabetic chars
    if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z')
        return ch;

    // lowercase
    if (ch >= 'a' && ch <= 'z')
    {
        // relative position in alphabet
        ch -= 'a';

        // cypher
        ch += this->key;
        ch %= 26;

        // restore position in ASCII table
        ch += 'a';
    }
    // uppercase
    else
    {
        // relative position in alphabet
        ch -= 'A';

        // cypher
        ch += this->key;
        ch %= 26;

        // restore position in ASCII table
        ch += 'A';
    }

    return ch;
}
