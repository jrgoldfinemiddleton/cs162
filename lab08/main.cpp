/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 11/12/15
 ** Description: This program runs some simple tests on the Stack and
 **              Queue classes and prints the results.  It allows the
 **              user to optionally control this testing process.
 ** Input: none
 ** Output: std::cout, results of operations on Stack and Queue objects
 *********************************************************************/

#include <iostream>
#include <string>

#include "Queue.hpp"
#include "QueueIter.hpp"
#include "utilities.hpp"


void cowabunga();
void test();

int main()
{
    int choice = -1;
    Queue q;

    while (true)
    {
        std::cout << "\nMENU\n\n"
                  << "Select an action:\n"
                  << "1) Add integer to queue\n"
                  << "2) Remove integer from queue\n"
                  << "3) Print queue contents\n"
                  << "4) Run queue debug tests\n"
                  << "5) Exit\n\n";

        choice = utilities::get_valid_int_in_range(1, 5);

        switch (choice)
        {
            case 1:
            {
                std::cout << "Add an integer to queue from "
                          << "0 through 1000: ";
                int val = utilities::get_valid_int_in_range(0, 1000);
                q.add_back(val);
                break;
            }
            case 2:
            {
                int val = q.remove_front();
                if (val == -1) 
                    std::cout << "Empty queue!\n";
                else
                    std::cout << "Removed " << val << " from queue.\n";
                break;
            }
            case 3:
            {
                QueueIter qi(q);
                qi.print_elements();
                break;
            }
            case 4:
            {
                test();
                break;
            }
            case 5:
            {
                return 0;
            }
        }

    }
}


/*********************************************************************
 ** Function: test()
 ** Description: Runs a series of automated tests on the Queue class.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: displays the results of each test
 *********************************************************************/

void test()
{
    int arr[] = { 0, 1, 2, 3, 4 };

    std::cout << "\nTesting the Queue class...\n\n";
    {
        Queue q;

        std::cout << "Adding 0 to queue.\n";
        q.add_back(arr[0]);

        std::cout << "Current front: " << q.get_front() << "\n";

        std::cout << "Removing 0 from queue: " << q.remove_front() <<
                     '\n';

        std::cout << "Queue status: " << q.get_front() << '\n';

        std::cout << "Trying to remove item from empty queue: " <<
                     q.remove_front() << '\n';
        std::cout << "Trying to remove item from empty queue: " <<
                     q.remove_front() << '\n';

        
        std::cout << "Adding 0 to queue.\n";
        q.add_back(arr[0]);
        std::cout << "Adding 1 to queue.\n";
        q.add_back(arr[1]);
        std::cout << "Adding 2 to queue.\n";
        q.add_back(arr[2]);
        std::cout << "Adding 3 to queue.\n";
        q.add_back(arr[3]);
        std::cout << "Adding 4 to queue.\n";
        q.add_back(arr[4]);

        std::cout << "Removing 0 from queue: " << q.remove_front() <<
                     '\n';
        std::cout << "Adding 0 to queue.\n";
        q.add_back(arr[0]);
        std::cout << "Removing 1 from queue: " << q.remove_front() <<
                     '\n';
        std::cout << "Removing 2 from queue: " << q.remove_front() <<
                     '\n';
        std::cout << "Removing 3 from queue: " << q.remove_front() <<
                     '\n';
        std::cout << "Removing 4 from queue: " << q.remove_front() <<
                     '\n';
        std::cout << "Removing 0 from queue: " << q.remove_front() <<
                     '\n';
        std::cout << "Trying to remove item from empty queue: " <<
                     q.remove_front() << "\n";

        q.add_back(arr[0]);
        q.add_back(arr[1]);
        q.add_back(arr[2]);
        q.add_back(arr[3]);
        q.add_back(arr[4]);
        std::cout << "Testing destructor.\n";
    }

    {
        Queue q;
        q.add_back(arr[0]);
        q.add_back(arr[1]);
        q.add_back(arr[2]);
        q.add_back(arr[3]);
        q.add_back(arr[4]);
        std::cout << "Testing destructor on new queue with 5 elements.\n";
    }

    {
        Queue q;
        q.add_back(arr[4]);
        std::cout << "Testing destructor on queue with one element.\n";
    }

    {
        Queue q;
        std::cout << "Testing destructor on empty queue.\n";
    }

    cowabunga();
}


// this function does all sorts of cool stuff but you have to
// read between the lines
void cowabunga()
{
    // hope you enjoyed this
}
