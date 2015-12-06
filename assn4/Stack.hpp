/*********************************************************************
 ** Program Filename: Stack.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/09/15
 ** Description: Contains the definition of the Stack class and its
 **              helper StackNode struct.  The Stack class provides
 **              a stack-like data structure for Creature pointers.
 *********************************************************************/


#ifndef STACK_HPP
#define STACK_HPP

#include "Creature.hpp"

class Stack
{
    private:
        struct StackNode
        {
            public:
                Creature* item;
                StackNode *next;
        };

        StackNode *top;

    public:
        Stack();
        ~Stack();
        void add(Creature* item);
        Creature* remove();
};

#endif
