/*********************************************************************
 ** Program Filename: QueueIter.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/13/15
 ** Description: This file contains the definition of the QueueIter
 **              class.  A QueueIter is able to iterate through a Queue
 **              and print its elements in an efficient fashion.
 ** Input: none
 ** Output: std::cout
 *********************************************************************/


#ifndef QUEUE_ITER_HPP
#define QUEUE_ITER_HPP

#include "Queue.hpp"


class QueueIter
{
    private:
        Queue::QueueNode *start_pos;
        Queue::QueueNode *cur_pos;
    public:
        QueueIter(Queue& q) : start_pos(q.front), cur_pos(q.front) {  }

        // print the Queue
        void print_elements();
};

#endif
