/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/06/15
 ** Description: This program displays a menu allowing the user to
 **              do linear search, binary search, or bubblesort on
 **              precompiled lists of numbers.
 ** Input: std::ifstream
 ** Output: std::ofstream
 *********************************************************************/

#include <algorithm>        // std::sort
#include <fstream>          // for file I/O
#include <iostream>         // for user I/O
#include <string>           // std::string
#include <vector>           // std::vector
#include "utilities.hpp"    // for input validation

void display_menu();
void do_user_choice(int chc);
void linear_search(int val, const std::string in_file);
void binary_search(int val, const std::string in_file); // must be sorted
void bubblesort(const std::string in_file, const std::string out_file);


int main()
{
    int choice = -1;
    std::cout << "\nWelcome to the algorithms lab.  ";

    while (true)
    {
        std::cout << "\n\n";
        std::cout << "Please enter your selection.\n\n";
        display_menu();
        while (choice < 1 || choice > 4)
        {
            std::cout << "Choice: ";
            choice = utilities::get_valid_int();
        }

        // apply the user's selection
        do_user_choice(choice);
        // prepare for next choice
        choice = -1;
    }
                    
    // bad if the program ever gets here
    return 1;
}


/*********************************************************************
 ** Function: display_menu()
 ** Description: Present the user with a menu of tasks.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/

void display_menu()
{
    std::cout << "1) Linear Search\n" <<
                 "2) Binary Search\n" <<
                 "3) Bubblesort\n" <<
                 "4) Exit\n\n"; 
}


/*********************************************************************
 ** Function: do_user_choice()
 ** Description: Takes a user choice and applies linear or
 **              binary search, bubblesort, or exits the program.
 ** Parameters: chc     the user's choice
 ** Pre-Conditions: input files exist and contain whitespace-separated
 **                 lists of integers
 ** Post-Conditions: the user's choice will be obeyed
 *********************************************************************/

void do_user_choice(int chc)
{
    switch (chc)
    {
        case 1: // linear search
            {
                std::cout << "Which input file should be used?\n";
                std::string filename;
                std::getline(std::cin, filename);

                // get search value
                std::cout << "Linear search for which integer?\n";
                int val = utilities::get_valid_int();

                // search through file for value and print result
                linear_search(val, filename);            
            }
            break;
        case 2:
            {
                std::cout << "Which sorted input file should be used?\n";
                std::string filename;
                std::getline(std::cin, filename);

                // get search value
                std::cout << "Binary search for which integer?\n";
                int val = utilities::get_valid_int();

                // search through sorted file and print results
                binary_search(val, filename);
            }
            break;
        case 3:
            {
                std::cout << "Which input file should be used?\n";
                std::string in_file;
                std::getline(std::cin, in_file);

                std::cout << "Which output file should be used?\n";
                std::string out_file;
                std::getline(std::cin, out_file);

                // sort in_file and output to out_file
                std::cout << "Bubblesort (Ascending)\n";
                bubblesort(in_file, out_file);
            }
            break;
        default:
            // exit program with success flag
            exit(0);
    }
}


/*********************************************************************
 ** Function: linear_search()
 ** Description: Searches a file of whitespace-separated integers for
 **              the given value and prints which indices, if any,
 **              contain the value.
 ** Parameters: val     the integer value to search on
 **             in_file the name of the file to search
 ** Pre-Conditions: in_file contains only whitespace-separated
 **                 integers
 ** Post-Conditions: all indices containing val are printed, the file
 **                  is closed
 *********************************************************************/

void linear_search(int val, const std::string in_file)
{
    std::cout << "Linear Search for " << val << " in \'" << in_file << 
                 "\'...\n";

    // open file handle
    std::ifstream in;
    utilities::open_in_file(in, in_file);

    // list of values
    std::vector<int> list;

    // read all values to vector
    int cur;
    while (in >> cur)
        list.push_back(cur);

    // print vector contents
    std::cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        std::cout << list[i] << ' ';
    std::cout << '\n';

    // algorithm
    bool found = false;
    for (int i = 0; i < num_vals; ++i)
        if (list[i] == val)
        {
            std::cout << "Found " << val << " at index " << i << '\n';
            found = true;
        }

    if (found == false)
        std::cout << "Did not find " << val << " in the file.\n";

    // close the file handle
    in.close();
}


/*********************************************************************
 ** Function: binary_search()
 ** Description: Searches a sorted file of whitespace-separated
 **              integers for the given value and prints an index, if
 **              any, containing the value.
 ** Parameters: val     the integer value to search on
 **             in_file the name of the file to search
 ** Pre-Conditions: in_file contains only whitespace-separated
 **                 integers sorted in ascending order
 ** Post-Conditions: an index containing val is printed, if one exists,
 **                  and the file is closed
 *********************************************************************/

void binary_search(int val, const std::string in_file)
{
    std::cout << "Binary Search for " << val << " in \'" << in_file << 
                 "\'...\n";

    // open file handle
    std::ifstream in;
    utilities::open_in_file(in, in_file);

    // list of values
    std::vector<int> list;

    // read all values to vector
    int cur;
    while (in >> cur)
        list.push_back(cur);

    // print vector contents
    std::cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        std::cout << list[i] << ' ';
    std::cout << '\n';


    // algorithm
    int begin = 0;          // first index of current search section
    int end = num_vals;     // last index of current search section
    int middle = 0;         // middle of current search section
    bool found = false;     // found matching int?
    int pos = -1;           // index of found int

    // until a value is found or end < begin
    while (!found && begin <= end)
    {
        middle = (begin + end) / 2;
        if (list[middle] == val)
        {
            // we're done
            found = true;
            pos = middle;
        }
        else if (list[middle] > val)
            end = middle - 1;
        else
            begin = middle + 1;
    }

    // print the result
    // note: sadly binary search doesn't lend itself easily to finding all
    // indices containing the value
    if (pos == -1)
        std::cout << "Did not find " << val << " in the file.\n";
    else
        std::cout << "Found " << val << " at index " << pos << '\n';

    // close the file handle
    in.close();
}


/*********************************************************************
 ** Function: bubblesort()
 ** Description: Sorts a list of whitespace-separated integers from
 **              an input file and outputs the resulting list to
 **              an output file.
 ** Parameters: in_file     the name of the input file
 **             out_file    the name of the output file
 ** Pre-Conditions: in_file contains a list of whitespace-separated
 **                 integers
 ** Post-Conditions: out_file contains a list of whitespace-separated
 **                  integers sorted in ascending order
 *********************************************************************/

void bubblesort(const std::string in_file, const std::string out_file)
{
    std::cout << "Bubblesort \'" << in_file << 
                 "\'...\n";

    // open file handle
    std::ifstream in;
    utilities::open_in_file(in, in_file);

    // list of values
    std::vector<int> list;

    // store file contents to vector
    int cur;
    while (in >> cur)
        list.push_back(cur);

    // we don't need the input file anymore
    in.close();


    // verify vector
    std::cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        std::cout << list[i] << ' ';
    std::cout << '\n';

    // algorithm
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < num_vals - 1; ++i)
            if (list[i] > list[i + 1])
            {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
    }

    // open output file handle
    std::ofstream out;
    utilities::open_out_file(out, out_file);

    // verify vector and write out
    std::cout << "Sorted contents: ";
    for (int i = 0; i < num_vals; ++i)
    {
        std::cout << list[i] << ' ';
        out << list[i] << ' ';
    }
    std::cout << '\n';

    // done with the output file
    out.close();
}
