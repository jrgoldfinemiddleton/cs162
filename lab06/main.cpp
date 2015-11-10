/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/29/15
 ** Description: This program runs some simple tests on the Stack and
 **              Queue classes and prints the results.
 ** Input: none
 ** Output: std::cout, results of operations on Stack and Queue objects
 *********************************************************************/

#include <iostream>

#include "Stack.hpp"
#include "Queue.hpp"

int main()
{
    int arr[] = { 0, 1, 2, 3, 4 };

    std::cout << "Testing the Stack class...\n\n";
    Stack s;

    std::cout << "Adding 0 to stack.\n";
    s.add(arr[0]);

    std::cout << "Removing 0 from stack: " << s.remove() << '\n';
    std::cout << "Trying to remove item from empty stack: " <<
                 s.remove() << '\n';
    std::cout << "Trying to remove item from empty stack again: " <<
                 s.remove() << '\n';

    
    std::cout << "Adding 0 to stack.\n";
    s.add(arr[0]);
    std::cout << "Adding 1 to stack.\n";
    s.add(arr[1]);
    std::cout << "Adding 2 to stack.\n";
    s.add(arr[2]);
    std::cout << "Adding 3 to stack.\n";
    s.add(arr[3]);
    std::cout << "Adding 4 to stack.\n";
    s.add(arr[4]);

    std::cout << "Removing 4 from stack: " << s.remove() << '\n';
    std::cout << "Adding 0 to stack.\n";
    s.add(arr[0]);
    std::cout << "Removing 0 from stack: " << s.remove() << '\n';
    std::cout << "Removing 3 from stack: " << s.remove() << '\n';
    std::cout << "Removing 2 from stack: " << s.remove() << '\n';
    std::cout << "Removing 1 from stack: " << s.remove() << '\n';
    std::cout << "Removing 0 from stack: " << s.remove() << '\n';
    std::cout << "Trying to remove item from empty stack: " <<
                 s.remove() << '\n';

    std::cout << "Testing the Queue class...\n\n";
    Queue q;

    std::cout << "Adding 0 to queue.\n";
    q.add(arr[0]);

    std::cout << "Removing 0 from queue: " << q.remove() << '\n';
    std::cout << "Trying to remove item from empty queue: " <<
                 q.remove() << '\n';
    std::cout << "Trying to remove item from empty queue again: " <<
                 q.remove() << '\n';

    
    std::cout << "Adding 0 to queue.\n";
    q.add(arr[0]);
    std::cout << "Adding 1 to queue.\n";
    q.add(arr[1]);
    std::cout << "Adding 2 to queue.\n";
    q.add(arr[2]);
    std::cout << "Adding 3 to queue.\n";
    q.add(arr[3]);
    std::cout << "Adding 4 to queue.\n";
    q.add(arr[4]);

    std::cout << "Removing 0 from queue: " << q.remove() << '\n';
    std::cout << "Adding 0 to queue.\n";
    q.add(arr[0]);
    std::cout << "Removing 1 from queue: " << q.remove() << '\n';
    std::cout << "Removing 2 from queue: " << q.remove() << '\n';
    std::cout << "Removing 3 from queue: " << q.remove() << '\n';
    std::cout << "Removing 4 from queue: " << q.remove() << '\n';
    std::cout << "Removing 0 from queue: " << q.remove() << '\n';
    std::cout << "Trying to remove item from empty queue: " <<
                 q.remove() << "\n\n";

    return 0;
}
