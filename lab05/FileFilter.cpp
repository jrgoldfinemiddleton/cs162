/*********************************************************************
 ** Program Filename: FileFilter.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This file contains the FileFilter member function
 **              implementation.
 ** Input: std::ifstream
 ** Output: std::ofstream
 *********************************************************************/

#include "FileFilter.hpp"

#include <fstream>


/*********************************************************************
 ** Function: FileFilter::do_filter()
 ** Description: Takes a reference to an std::ifstream and a reference
 **              to an std::ofstream, and filters the input, sending
 **              it to out.
 ** Parameters: in      a reference to the input file stream
 **             out     a reference to the output file stream
 ** Pre-Conditions: in and out must be successfully open with no
 **                 error flags set
 ** Post-Conditions: the filtered output is sent to out, in's fail
 **                  flag is set
 *********************************************************************/

void FileFilter::do_filter(std::ifstream &in, std::ofstream &out)
{
    // try to get the first char
    char in_ch = in.get();
    // to store each modified char
    char out_ch;

    // until a char can't be read
    while (!in.fail())
    {
        // apply the transformation defined by this's object type
        // meant to allow for polymorphism
        out_ch = this->transform(in_ch);

        // send the modified char to the output stream
        out.put(out_ch);

        // try to get the next char
        in_ch = in.get();
    }
}
