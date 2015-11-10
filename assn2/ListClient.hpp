/*********************************************************************
 ** Program Filename: ListClient.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: The ListClient class builds a shopping list and
 **              allows a user to interact with it via a menu.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/


#ifndef LIST_CLIENT_HPP
#define LIST_CLIENT_HPP

#include "List.hpp"     // for the shopping list
#include "Item.hpp"     // for the list items
#include <string>       // for std::string

class ListClient
{
    private:
        List shopping_list;

    public:
        // most of these should be private
        void print_list() const;
        void display_menu() const;
        void menu_selection();                  // get user menu selection
        void do_users_bidding(const int bid);   // apply user menu selection
        void add_new_item();
        void remove_item();
        void update_price();
        void update_quantity();
        void run();                             // run the client
};

#endif
