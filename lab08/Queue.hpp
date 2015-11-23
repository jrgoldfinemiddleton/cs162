/*********************************************************************
 ** Program Filename: Queue.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/12/15
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
        
        // first element in queue
        QueueNode *front;
        // last element in queue
        QueueNode *back;

        // indicates that a node is empty
        static const int EMPTY = -1;
        
    public:
        Queue();
        ~Queue();

        void add_back(int item);    // inserts new node with item
        int get_front();            // returns the front node
        int remove_front();         // basically just sets the node to -1
                                    // and returns the node
        friend class QueueIter;
};

#endif
