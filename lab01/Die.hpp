/*********************************************************************
 ** Program Filename: Die.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/26/15
 ** Description: The specification file for the Die class.  A Die is
 **              an object with an integral number of sides, which may
 **              be rolled to produce a single value from 1 up to the
 **              number of sides.  Each side value should have roughly
 **              an equal probability of occurring from a roll.
 ** Input: N/A
 ** Output: N/A
 *********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
    private:
        // number of sides on Die and also the max value
        int numSides;

    public:
        // constructor that takes the number of sides as a parameter
        Die(int sides);

        // returns a value between 1 and the number of sides
        int getRoll();
};

#endif
