/*********************************************************************
 ** Program Filename: CopyFilter.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the definition for the CopyFilter
 **              class.  A CopyFilter is derived from the FileFilter
 **              class and filters input by simply copying chars.
 ** Input: std::ifstream, char
 ** Output: std::ofstream
 *********************************************************************/

#ifndef COPY_FILTER_HPP
#define COPY_FILTER_HPP

#include "FileFilter.hpp"


class CopyFilter : public FileFilter
{
    public:
        // returns the parameter unchanged
        virtual char transform(char ch);
};

#endif
