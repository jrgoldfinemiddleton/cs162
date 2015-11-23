/*********************************************************************
 ** Program Filename: QueueIter.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/13/15
 ** Description: Contains the implementation for a method of the
 **              QueueIter class.
 ** Input: none
 ** Output: std::cout, list of numbers in queue
 *********************************************************************/

#include "QueueIter.hpp"

#include <iostream>


/*********************************************************************
 ** Function: QueueIter::print_elements()
 ** Description: Prints out the queue in order.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: each element of the queue is printed in order
 *********************************************************************/

void QueueIter::print_elements() {
    std::cout << "Printing contents of queue.\n";

    do
    {
        int cur_val = cur_pos->item;
        if (cur_val != Queue::EMPTY)
            std::cout << cur_pos->item << ' ';
        cur_pos = cur_pos->next;
    }
    while (cur_pos != start_pos);
    std::cout << '\n';
}
