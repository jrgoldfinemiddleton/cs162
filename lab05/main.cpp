/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/23/15
 ** Description: This program uses FileFilter and its derived classes
 **              to filter an input file into three output files,
 **              demonstrating the principle of polymorphism in C++.
 ** Input: std::cin, std::ifstream, "in.txt"
 ** Output: std::cout, std::ofstream, "out_copy.txt", "out_encr.txt",
 **         "out_uppr.txt"
 *********************************************************************/


#include "FileFilter.hpp"       // base abstract filter class

// derived filter classes
#include "CopyFilter.hpp"
#include "UpperFilter.hpp"
#include "EncryptFilter.hpp"

#include "utilities.hpp"        // for input validation

#include <fstream>
#include <iostream>             // for user input and error messages


int main()
{
    // attempt to open the input file
    std::ifstream in("in.txt");

    // attempt to open an output file for each filter
    std::ofstream out_copy("out_copy.txt");
    std::ofstream out_encr("out_encr.txt");
    std::ofstream out_uppr("out_uppr.txt");

    // get a key for EncryptFilter
    std::cout << "Please enter a non-negative integer key:\n";
    const int MIN_KEY = 0;
    const int MAX_KEY = 300;
    int key = utilities::get_valid_int_in_range(MIN_KEY, MAX_KEY);

    // use pointers to FileFilter objects for polymorphism
    FileFilter *ff_copy = new CopyFilter;
    FileFilter *ff_encr = new EncryptFilter(key);
    FileFilter *ff_uppr = new UpperFilter;

    if (!in)    // couldn't open input file
        std::cout << "Could not open file for input.\n";
    else if ( !(out_copy && out_encr && out_uppr) )
                // couldn't open an output file
        std::cout << "Could not open file for output.\n";
    else        // everything looks good
    {
        // filter by simply copying chars
        ff_copy->do_filter(in, out_copy);
        // clear fail flag and go back to beginning of stream
        in.clear();
        in.seekg(0, std::ios::beg);

        // filter by encrypting via key
        ff_encr->do_filter(in, out_encr);
        // clear fail flag and go back to beginning of stream
        in.clear();
        in.seekg(0, std::ios::beg);

        // filter by making letters uppercase
        ff_uppr->do_filter(in, out_uppr);
    }

    // close all the streams
    in.close();
    out_copy.close();
    out_encr.close();
    out_uppr.close();

    // deallocate the heap memory and null out those pointers!
    // nothing dangling here
    delete ff_copy;
    delete ff_encr;
    delete ff_uppr;
    ff_copy = ff_encr = ff_uppr = NULL;

    return 0;
}
