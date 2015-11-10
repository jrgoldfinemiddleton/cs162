/*********************************************************************
 ** Program Filename: FileFilter.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the definition for the FileFilter
 **              class.  FileFilter is an abstract class and thus
 **              must be inherited by another class.  It defines a
 **              pure virtual function for transforming a char to
 **              another char and a function that filters an
 **              std::ifstream and passes it to an std::ofstream.
 ** Input: std::ifstream, char 
 ** Output: std::ofstream
 *********************************************************************/


#ifndef FILE_FILTER_HPP
#define FILE_FILTER_HPP

#include <fstream>

class FileFilter
{
    public:
        // pure virtual function meant to convert a char to a new char
        virtual char transform(char ch) = 0;
        
        // filters file input stream and sends to file output stream
        void do_filter(std::ifstream &in, std::ofstream &out);
};

#endif
