/*********************************************************************
 ** Program Filename: Queue.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/12/15
 ** Description: Contains the implementation for the Queue class
 **              member functions.
 *********************************************************************/

#include <cstdlib>  // for NULL
#include <string>   // for std::string

#include <iostream> // for debug and output

#include "Queue.hpp"


/*********************************************************************
 ** Function: Queue::Queue()
 ** Description: Constructs a new Queue object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: front and back both point to a new element, which
 **                  points to itself, the new element is empty
 *********************************************************************/

Queue::Queue()
{  
    // create first node here to simplify logic
    QueueNode *fst = new QueueNode();
    // set it to empty
    fst->item = EMPTY;
    fst->next = fst;
    fst->prev = fst;

    front = fst;
    back = fst;
}


/*********************************************************************
 ** Function: Queue::~Queue()
 ** Description: Destructor for a Queue object.
 ** Parameters: none
 ** Pre-Conditions: front has not been deleted yet, no pointers are
 **                 null
 ** Post-Conditions: front and all other nodes have been deleted
 *********************************************************************/

Queue::~Queue()
{
    // start at first node
    QueueNode *cur;
    back = front->next;

    // destroy all the QueueNodes until we reach NULL
    while (back != front)
    {
        cur = back;
        back = cur->next;

        // DEBUG
        /* std::cout << "destructor: removing node containing " <<
                      cur->item << '\n'; */
        delete cur;
    }

    // DEBUG
    /* std::cout << "destructor: removing node containing " << back->item <<
                 '\n'; */

    delete back;    // deleting the last node

    // all pretty much unnecessary but why not?
    front = NULL;
    back = NULL;
    cur = NULL;
}


/*********************************************************************
 ** Function: Queue::add_back()
 ** Description: Adds a new element to the back of the Queue.
 ** Parameters: item    the integer to add to the Queue
 ** Pre-Conditions: item is not -1 (the sentinel value)
 ** Post-Conditions: back points to a node containing "item",
 **                  the node points to the old back node, the node
 **                  points to the node back used to point to, the
 **                  Queue is not empty
 *********************************************************************/

void Queue::add_back(int item)
{
    // next node after back
    QueueNode *after = back->next;

    // if after is empty, let it hold item's value
    if (after->item == EMPTY)
    {
        after->item = item;

        // DEBUG
        //std::cout << "add_back(): no need to add new node\n";
        return;
    }

    // otherwise, make a new node and insert it between back and after
    QueueNode *cur = new QueueNode;
    cur->item = item;
    cur->prev = back;
    cur->next = after;

    // DEBUG
    //std::cout << "add_back(): had to add new node\n";

    // update back and after's pointers
    back->next = cur;
    after->prev = cur;
    back = cur;
}


/*********************************************************************
 ** Function: Queue::get_front()
 ** Description: Sets out to the int stored in the front node of the
 **              Queue and returns a string stating the status of the
 **              Queue.
 ** Parameters: none
 ** Pre-Conditions: -1 was never added to the Queue by the user
 ** Post-Conditions: if there is no front element, print empty status;
 **                  otherwise returns the value stored in the front
 **                  node
 *********************************************************************/

int Queue::get_front()
{
    int out = front->item;

    if (out == EMPTY)
        std::cout << "Queue Empty.  No front element: ";

    return out;
}


/*********************************************************************
 ** Function: Queue::remove_front()
 ** Description: Returns the int stored in the front node of the
 **              Queue and makes the old front node as empty.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no front element, returns -1; otherwise
 **                  returns the int stored in the front node, old front
 **                  is empty
 *********************************************************************/

int Queue::remove_front()
{
    int val = front->item;

    // mark old front node as empty
    front->item = EMPTY;

    // move to next queue element
    front = front->next;

    // DEBUG
    //std::cout << "remove_front(): removed " << val << '\n';

    return val;
}
