/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: This program allows the user to create and modify a
 **              shopping list with quantity and price information for
 **              for each item.  The situation is a cross between a
 **              shopping list, an inventory, and a receipt.
 ** Input: std::cin, user's menu selections and item information
 ** Output: std::cout, the list and information about the items on it
 *********************************************************************/

#include "ListClient.hpp"


int main()
{
    ListClient lc;
    lc.run();

    return 0;
}
