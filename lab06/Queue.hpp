/*********************************************************************
 ** Program Filename: Queue.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/29/15
 ** Description: Contains the definition of the Queue class and its
 **              helper QueueNode struct.  The Queue class provides
 **              a queue-like data structure for ints.
 *********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP


class Queue
{
    private:
        struct QueueNode
        {
            public:
                int item;
                // node that will come off queue before this one, or NULL
                QueueNode *next;
                // node that will come of queue after this one, or NULL
                QueueNode *prev;
        };
        
        QueueNode *front;
        QueueNode *back;
        
    public:
        Queue();
        ~Queue();
        void add(const int item);
        int remove();
};

#endif
