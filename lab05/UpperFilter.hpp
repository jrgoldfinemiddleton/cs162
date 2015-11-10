/*********************************************************************
 ** Program Filename: UpperFilter.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the definition for the
 **              UpperFilter class.  An UpperFilter is derived from
 **              the FileFilter class and filters input by
 **              capitalizing all alphabetic characters.
 ** Input: std::ifstream, char
 ** Output: std::ofstream
 *********************************************************************/

#ifndef UPPER_FILTER_HPP
#define UPPER_FILTER_HPP

#include "FileFilter.hpp"


class UpperFilter : public FileFilter
{
    public:
        // returns a copy of ch made uppercase or else a copy of ch
        virtual char transform(char ch);
};

#endif
