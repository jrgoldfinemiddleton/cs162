/*********************************************************************
 ** Program Filename: utilities.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: This file provides implementations for each function
 **              in the utilities namespace declared in utilities.hpp.
 **
 **              get_valid_int() was inspired by a post at
 **              https://stackoverflow.com/questions/15184906/
 **              can-you-stop-letters-being-entered-for-an-integer .
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#include "utilities.hpp"

#include <iostream>         // for input and output
#include <limits>           // for clearing the input buffer


/*********************************************************************
 ** Function: utilities::get_valid_int()
 ** Description: Waits for the user to enter a valid int value.
 **              Each time the user enters an invalid value, it
 **              prompts the user with an error message to try again.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input int is returned.
 *********************************************************************/

int utilities::get_valid_int()
{
    int in_val = 0;

    while (!(std::cin >> in_val))
    {
        std::cout << "Bad input!  Please enter an integer.\n";

        // clear error bits
        std::cin.clear();
        // ignore the rest of the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // clear any trailing characters in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return in_val;
}



/*********************************************************************
 ** Function: utilities::get_valid_int_in_range()
 ** Description: Waits for the user to enter a valid int value
 **              between low and high. Each time the user enters an
 **              invalid value, it prompts the user with an error
 **              message to try again.
 ** Parameters: low     the minimum value allowed
 **             high    the maximum value allowed
 ** Pre-Conditions: low is less than high.
 ** Post-Conditions: A user-input int between low and high is returned.
 *********************************************************************/

int utilities::get_valid_int_in_range(const int low, const int high)
{
    int in_val;
    bool done = false;
    do
    {
        in_val = utilities::get_valid_int();

        if (in_val < low || in_val > high)
            std::cout << "Value must be between " << low << " and " <<
                         high << ".\n";
        else
            done = true;
    }
    while (!done);

    return in_val;
}

/*********************************************************************
 ** Function: utilities::get_valid_double()
 ** Description: Waits for the user to enter a valid double value.
 **              Each time the user enters an invalid value, it
 **              prompts the user with an error message to try again.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input double is returned.
 *********************************************************************/

double utilities::get_valid_double()
{
    double in_val = 0.0;

    while (!(std::cin >> in_val))
    {
        std::cout << "Bad input!  Please enter a number.\n";

        // clear error bits
        std::cin.clear();
        
        // ignore the rest of the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // clear any trailing characters in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return in_val;
}


/*********************************************************************
 ** Function: utilities::get_valid_double_in_range()
 ** Description:  Waits for the user to enter a valid double value
 **              between low and high. Each time the user enters an
 **              invalid value, it prompts the user with an error
 **              message to try again.
 ** Parameters: low     the minimum value allowed
 **             high    the maximum value allowed
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input double is returned.
 *********************************************************************/

double utilities::get_valid_double_in_range(
        const double low, const double high)
{
    double in_val;
    bool done = false;
    do
    {
        in_val = utilities::get_valid_double();

        if (in_val < low || in_val > high)
            std::cout << "Value must be between " << low << " and " <<
                         high << ".\n";
        else
            done = true;
    }
    while (!done);

    return in_val;
}
