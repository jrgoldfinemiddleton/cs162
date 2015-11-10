/*********************************************************************
 ** Program Filename: EncryptFilter.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the definition for the
 **              EncryptFilter class.  An EncryptFilter is derived
 **              from the FileFilter class and filters input by
 **              encrypting characters via an integer key.
 ** Input: std::ifstream, int representing the key, char
 ** Output: std::ofstream
 *********************************************************************/

#ifndef ENCRYPT_FILTER_HPP
#define ENCRYPT_FILTER_HPP

#include "FileFilter.hpp"

class EncryptFilter : public FileFilter
{
    private:
        // store the key
        const int key;
    
    public:
        // constructor, initializes the key
        EncryptFilter(int k);

        // returns a char encrypted by the key
        virtual char transform(char ch); 
};

#endif

