/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/20/15
 ** Description: The program displays a menu allowing the user to run
 **              three different recursive functions.
 ** Input: std::cin, int, double, string
 ** Output: std::cout
 *********************************************************************/

#include <iostream>         // for IO
#include <limits>           // for setting bounds on input
#include <string>           // for std::string
#include "utilities.hpp"    // for input validation


// display the menu
void display_menu();
// apply user menu selection
void do_user_choice(const int);
// reverse a string's characters and print the result
void reverse(std::string);
// sum an array's elements
double sum_arr(const double[], const int);
// return the number of dots in a triangle with a certain number of rows
int triangular_number(const int);


int main()
{
    // select something invalid
    int choice = -1;
    std::cout << "Welcome to the recursion lab.  ";

    // repeatedly
    while (true)
    {
        // display the menu and a prompt for selection
        std::cout << "\n\n";
        std::cout << "Please enter your selection.\n\n";
        display_menu();
        // until the selection is valid, keep prompting user for a choice
        while (choice < 1 || choice > 4)
        {
            std::cout << "Choice: ";
            choice = utilities::get_valid_int();
        }

        // do the user's bidding like Darth Vader did Emperor Palpatine's
        do_user_choice(choice);
        // reset the selection to something invalid
        choice = -1;
    }
    
    // bad if the program ever gets here
    return 1;
}


/*********************************************************************
 ** Function: display_menu()
 ** Description: Presents the user with the three recursive functions
 **              and an option to close the program.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The menu is displayed.
 *********************************************************************/

void display_menu()
{
    std::cout << "1) Reverse a string.\n" <<
                 "2) Sum some numbers.\n" <<
                 "3) Calculate a triangular number.\n" <<
                 "4) Exit program\n\n";
}


/*********************************************************************
 ** Function: do_user_choice()
 ** Description: Applies the user's selection from the menu, running
 **              either one of the three recursive functions and
 **              prompting for necessary input or else exiting.
 ** Parameters: chc   the number of the user's choice from the menu
 ** Pre-Conditions: display_menu() has just been run and the user has
 **                 been prompted for a valid int
 ** Post-Conditions: The user's choice is followed.  That is, one of
 **                  the recursive functions was called or the program
 **                  has exited.
 *********************************************************************/

void do_user_choice(const int chc)
{
    switch(chc)
    {
        case 1: // user wanted to reverse a string
            {
                std::cout << "Please enter a string to reverse: ";
                std::string original;
                // capture all characters, including whitespace
                getline(std::cin, original);
                // reverse the string and print it
                reverse(original);
            }
            break;
        case 2: // user wanted to sum some numbers
            {
                std::cout << "How many numbers will you enter? ";
                // any nonnegative integer is valid
                int length = utilities::get_valid_int_in_range(0,
                        std::numeric_limits<int>::max());
                // dynamically allocate the array
                double *nums = new double[length];
                // get the numbers from the user
                for (int i = 0; i < length; ++i)
                {
                    std::cout << "Number " << (i + 1) << ": ";
                    nums[i] = 
                        utilities::get_valid_double_in_range(
                                std::numeric_limits<int>::min(),
                                std::numeric_limits<int>::max());
                }
                std::cout << "The sum is " << sum_arr(nums, length) << ".";

                // free the memory and null the pointer
                delete [] nums;
                nums = NULL;
            }
            break;
        case 3: // user wanted to calculate a triangular number
            {
                std::cout << "Which triangular number do you want?\n";
                std::cout << "n = ";
                int n = utilities::get_valid_int_in_range(0,
                        std::numeric_limits<int>::max());
                // print the nth triangular number
                std::cout << "T(" << n << ") = " << triangular_number(n) <<
                    ".";
            }
            break;
        default: // user wanted to exit or invalid choice was made
            exit(0);
    }
}


/*********************************************************************
 ** Function: reverse()
 ** Description: Reverses a string and prints it to the screen,
 **              followed by a newline.
 ** Parameters: str  the string to reverse
 ** Pre-Conditions: str is a valid string
 ** Post-Conditions: the reversed string is printed to the screen,
 **                   with a trailing '\n' char
 *********************************************************************/

void reverse(std::string str)
{
    // base case
    if (str == "")
        // last recursion, so print that newline char
        std::cout << '\n';
    else // at least 1 char left
    {
        // print the last character
        std::cout << str[str.length() - 1];
        // throw the rest back into reverse()
        reverse(str.substr(0, str.length() - 1));
    }
}


/*********************************************************************
 ** Function: sum_arr()
 ** Description: Takes an array of doubles and returns the sum of its
 **              elements.
 ** Parameters: arr     the array of doubles
 **             length  the number of elements in the array
 ** Pre-Conditions: arr is fully initialized, length >= 0
 ** Post-Conditions: returns the sum of the elements
 *********************************************************************/

double sum_arr(const double arr[], const int length)
{
    // base case
    if (length == 0)
        return 0.0;
    else
        // sum the last element with the sum of the rest of the array
        return arr[length - 1] + sum_arr(arr, length - 1);
}


/*********************************************************************
 ** Function: triangular_number()
 ** Description: Returns the nth triangular number, which is the sum
 **              0 + 1 + 2 + ... + (n - 1) + n.
 ** Parameters: n   the triangular number we seek
 ** Pre-Conditions: n >= 0
 ** Post-Conditions: the nth triangular number is returned.
 *********************************************************************/

int triangular_number(const int n)
{
    // base case
    if (n <= 0)
        return 0;
    else
        // sum n with the previous triangular number
        return n + triangular_number(n - 1);
}
