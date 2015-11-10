/*********************************************************************
 ** Program Filename: Item.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: The Item class represents an item in a shopping list.
 **              Each item has a name, unit type, quantity, and unit
 **              price.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>


class Item
{
    private:
        std::string item_name;
        std::string unit;
        int quantity;
        double unit_price;

    public:
        Item(std::string name, std::string unit, int qty, double price);

        // accessors
        std::string get_item_name() const;
        std::string get_unit() const;
        int get_quantity() const;
        double get_unit_price() const;

        double get_total_price() const;

        // mutators
        void set_quantity(const int qty);
        void set_unit_price(const double price);

        // overloaded operators
        friend std::ostream& operator<<(std::ostream &out, const Item& it);
        friend bool operator==(const Item &it1, const Item &it2);
};

#endif
