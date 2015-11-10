/*********************************************************************
 ** Program Filename: LoadedDie.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/26/15
 ** Description: The specification file for the LoadedDie class.  A
 **              LoadedDie is an object with an integral number of
 **              sides, which may be rolled to produce a single value
 **              from 1 up to the number of sides.  The greater the
 **              value on the side of the LoadedDie, the greater its
 **              chances of occurring from a roll.
 ** Input: N/A
 ** Output: N/A
 *********************************************************************/

#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

class LoadedDie
{
    private:
        // number of sides on the LoadedDie and also the max value
        int numSides;

        // array containing the different side values in imbalanced
        // proportions
        int *distributionArr;

    public:
        // constructor that takes the number of sides as a parameter
        LoadedDie(int sides);

        // destructor
        ~LoadedDie();

        // returns a value between 1 and the number of sides
        int getRoll();

        // returns the sum of all the sides of the LoadedDie
        int sumSides();
};

#endif
