/*********************************************************************
 ** Program Filename: Stack.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/29/15
 ** Description: Contains the implementation for the Stack class
 **              member functions.
 *********************************************************************/

#include <limits>   // for std::numeric_limits
#include <cstdlib>  // for NULL

#include "Stack.hpp"


/*********************************************************************
 ** Function: Stack::Stack()
 ** Description: Constructs a new Stack object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: top is a null pointer
 *********************************************************************/

Stack::Stack() : top(NULL) {  }


/*********************************************************************
 ** Function: Stack::~Stack()
 ** Description: Destructor for a Stack object.
 ** Parameters: none
 ** Pre-Conditions: top has not been deleted yet
 ** Post-Conditions: top and all other nodes have been deleted
 *********************************************************************/

Stack::~Stack()
{
    // start at first node
    StackNode *cur = top;

    // destroy all the StackNodes until we reach NULL
    while (cur)
    {
        StackNode *rmv = cur;
        cur = cur->next;
        delete rmv;
    }
}


/*********************************************************************
 ** Function: Stack::add()
 ** Description: Adds a new StackNode containing "item" to the top of
 **              the Stack.
 ** Parameters: item    the integer to add to the Stack
 ** Pre-Conditions: none
 ** Post-Conditions: top points to a new node containing "item",
 **                  the new node points to the old top node, top is
 **                  not a null pointer
 *********************************************************************/

void Stack::add(const int item)
{
    // create a new node containing the item
    StackNode *node = new StackNode;
    node->item = item;

    // point it to the old top node
    node->next = top;

    // now it's on top
    top = node;
}


/*********************************************************************
 ** Function: Stack::remove()
 ** Description: Returns the int stored in the top node of the Stack.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no top node, returns a large negative
 **                  int; otherwise returns the int stored in the top
 **                  node
 *********************************************************************/

int Stack::remove()
{
    // if there are no nodes, return the most negative int
    if (top == NULL)
        return std::numeric_limits<int>::min();

    // store the current top
    StackNode *old_top = top;

    // top points to the node under the old top
    top = old_top->next;

    // get the item from old top
    int removed = old_top->item;
    
    // free the memory pointed to by old_top
    delete old_top;
    old_top = NULL;

    // return the item
    return removed;
}
