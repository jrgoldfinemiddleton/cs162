/*********************************************************************
 ** Program Filename: Queue.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/29/15
 ** Description: Contains the implementation for the Queue class
 **              member functions.
 *********************************************************************/

#include <limits>   // for std::numeric_limits
#include <cstdlib>  // for NULL

#include "Queue.hpp"


/*********************************************************************
 ** Function: Queue::Queue()
 ** Description: Constructs a new Queue object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: front and back are null pointers
 *********************************************************************/

Queue::Queue() : front(NULL), back(NULL) {  }


/*********************************************************************
 ** Function: Queue::~Queue()
 ** Description: Destructor for a Queue object.
 ** Parameters: none
 ** Pre-Conditions: front has not been deleted yet
 ** Post-Conditions: front and all other nodes have been deleted
 *********************************************************************/

Queue::~Queue()
{
    // start at first node
    QueueNode *cur = front;

    // destroy all the QueueNodes until we reach NULL
    while (cur)
    {
        QueueNode *rmv = cur;
        cur = cur->next;
        delete rmv;
    }
}


/*********************************************************************
 ** Function: Queue::add()
 ** Description: Adds a new QueueNode containing "item" to the front
 **              of the Stack.
 ** Parameters: item    the integer to add to the Stack
 ** Pre-Conditions: none
 ** Post-Conditions: back points to a new node containing "item",
 **                  the new node points to the old back node, front
 **                  and back are not null pointers
 *********************************************************************/

void Queue::add(const int item)
{
    // create a new node containing the item
    QueueNode *node = new QueueNode;
    node->item = item;

    // make the node before it be the old back
    node->next = back;

    // this is the last node
    node->prev = NULL;

    // now it's in back
    back = node;

    // if there were no nodes before, it's now the front node too
    if (node->next == NULL)
        front = node;

    // otherwise make the old back node point to the new back node
    else
        node->next->prev = node;
    
    // null out the temporary pointer variable
    node = NULL;
}


/*********************************************************************
 ** Function: Queue::remove()
 ** Description: Returns the int stored in the front node of the
 **              Queue.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no front node, returns a large
 **                  negative int; otherwise returns the int stored in
 **                  the front node
 *********************************************************************/

int Queue::remove()
{
    // if there are no nodes, return the most negative int
    if (front == NULL)
        return std::numeric_limits<int>::min();

    // store the current front
    QueueNode *old_front = front;

    // front points to the node after old_front
    front = old_front->prev;

    // new front has no nodes in front of it
    if (front != NULL)
        front->next = NULL;

    // front is NULL so back is NULL
    else
        back = NULL;
    
    // get the item from old front node
    int removed = old_front->item;
    
    // free the memory pointed to by old_front
    delete old_front;
    old_front = NULL;

    // return the item
    return removed;
}
