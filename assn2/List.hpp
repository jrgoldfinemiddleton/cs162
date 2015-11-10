/*********************************************************************
 ** Program Filename: List.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: The List class contains a shopping list in which Item
 **              objects may be added, removed, and modified
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"

#include <vector>       // for std::vector

class List
{
    private:
        std::vector<Item> items;
        double total_price;

        int position(const Item &it) const;  // returns -1 if not found

    public:
        List();
        
        // accessor
        double get_total_price() const;

        int length() const;
        bool add_item(const Item &it);
        bool remove_item(const int position);
        bool update_item_quantity(const int position, const int new_qty);
        bool update_item_price(const int position, const double new_price);

        // overloaded operator
        friend std::ostream& operator<<(std::ostream &out, const List &lst);
};

#endif
