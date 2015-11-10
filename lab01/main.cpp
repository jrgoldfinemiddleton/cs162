/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/26/15
 ** Description: This program repeatedly rolls two dice, one regular
 **              and one loaded, with the same number of sides.  For
 **              each die, the value of each roll is printed to the
 **              screen as well as the sum of all of its rolls.
 ** Input: Number of sides per die, number of rolls per die
 ** Output: All roll values and the total of all the rolls for each
 **         die
 *********************************************************************/

#include "Die.hpp"
#include "LoadedDie.hpp"

#include <cstdlib>  // for srand()
#include <ctime>    // for time()
#include <iostream> // for I/O


// ask user for number of sides per die
int getNumSides();

// ask user for number of rolls per die
int getNumRolls();

// roll "sides"-sided dice "N" times and print the results
void rollNTimes(int N, int sides);

int main()
{
    int sides = getNumSides();
    int rolls = getNumRolls();
    
    srand(time(0));
    rollNTimes(rolls, sides);

    return 0;
}


/*********************************************************************
 ** Function: getNumSides()
 ** Description: Prompts the user for the number of sides (s)he wishes
 **              both dice to have.  Repeatedly prompts the user until
 **              a positive integer is entered.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: the number of sides is returned
 *********************************************************************/

int getNumSides()
{
    // to store number of sides on a die
    int sides;

    // prompt user for a positive number
    do
    {
        std::cout << "How many sides on a die (must be at least " <<
                 "1)?" << std::endl;
        std::cin >> sides;

        // clear invalid input, i.e. non-numbers
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(5000, '\n');
        }

    } while (sides < 1);

    return sides;
}


/*********************************************************************
 ** Function: getNumRolls()
 ** Description: Prompts the user for the number of rolls (s)he wishes
 **              to make per die.  Repeatedly prompts the user until
 **              a positive integer is entered.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: the number of rolls is returned
 *********************************************************************/

int getNumRolls()
{
    // to store number of rolls per die
    int rolls;

    // prompt user for a positive number
    do
    {
        std::cout << "How many rolls shall there be (must be at least " <<
                 "1)?" << std::endl;
        std::cin >> rolls; 

        // clear invalid input, i.e. non-numbers
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(5000, '\n');
        }
    } while (rolls < 1);

    return rolls;
}


/*********************************************************************
 ** Function: rollNTimes()
 ** Description: For two dice, one regular Die and one LoadedDie,
 **              prints the values of multiple rolls, the total of all
 **              the rolls, and the average value of a roll.
 ** Parameters: N     - the number of rolls per die
 **             sides - the number of sides per die
 ** Pre-Conditions: the number of rolls and sides must be positive
 ** Post-Conditions: a list of all roll values, a total, and an average
 **                  value is printed for each die
 *********************************************************************/

void rollNTimes(int N, int sides)
{
    std::cout << "Rolling " << sides << "-sided die " << N << " times:" <<
                 std::endl;

    // the balanced die to be rolled
    Die *die = new Die(sides);

    // to store the sum of values rolled
    int sumOfRolls = 0;

    // print roll values and accumulate them
    for (int i = 1; i <= N; ++i)
    {
        int rollValue = die -> getRoll();
        sumOfRolls += rollValue;
        std::cout << rollValue << "  ";

        // new line after each group of 10 rolls
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    std::cout << "\nTotal of " << N << " rolls: " << sumOfRolls <<
                 std::endl;
    std::cout << "Average roll: " <<
                 (static_cast<double>(sumOfRolls) / N) << std::endl;

    // deallocate heap memory
    delete die;

    std::cout << std::endl;

    std::cout << "Rolling loaded " << sides << "-sided die " << N <<
                 " times:" << std::endl;


    // the loaded die to be rolled
    LoadedDie *lDie = new LoadedDie(sides);

    // reset the sum for the new die
    sumOfRolls = 0;

    // print roll values and accumulate them
    for (int i = 1; i <= N; ++i)
    {
        int rollValue = lDie -> getRoll();
        sumOfRolls += rollValue;
        std::cout << rollValue << "  ";

        // new line after each group of 10 rolls
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    std::cout << "\nTotal of " << N << " rolls: " << sumOfRolls <<
                 std::endl;
    std::cout << "Average roll: " <<
                 (static_cast<double>(sumOfRolls) / N) << std::endl;

    // deallocate heap memory
    delete lDie;
}
