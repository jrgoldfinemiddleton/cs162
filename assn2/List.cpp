/*********************************************************************
 ** Program Filename: List.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: Contains the List class function declarations and
 **              a friend function to overload the << operator.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/


#include "List.hpp"

#include <iostream>     // for input and output
#include <iomanip>      // for manipulation of output formatting


/*********************************************************************
 ** Function: List:List()
 ** Description: Default constructor.  Sets the total price to 0.0.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: total_price = 0.0, a List object is initialized.
 *********************************************************************/

List::List() : total_price(0.0)
{
    return;
}

/*********************************************************************
 ** Function: List::position()
 ** Description: Returns the index of an Item equivalent to that
 **              passed in as a parameter in items.  If an equivalent
 **              item is not found, returns -1.
 ** Parameters: it      the item whose equivalent Item is sought
 ** Pre-Conditions: it is a valid Item.
 ** Post-Conditions: The index of an equivalent Item in items is
 **                  returned, or else -1 is returned.  This List is
 **                  not modified.
 *********************************************************************/

int List::position(const Item &it) const
{
    // flag
    const int ITEM_NOT_FOUND(-1);

    for (int cur(0); cur < length(); ++cur)
        if (this->items.at(cur) == it) return cur;

    return ITEM_NOT_FOUND;
}


/*********************************************************************
 ** Function: List::length()
 ** Description: Returns the size of the vector items.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Returns the list size.  This List is not modified.
 *********************************************************************/

int List::length() const
{
    return this->items.size();
}


/*********************************************************************
 ** Function: List::get_total_price()
 ** Description: Returns the total price of all the Items in the List.
 ** Parameters: none
 ** Pre-Conditions: total_price has been updated each time an Item has
 **                 been added, changed, or removed from this List.
 ** Post-Conditions: Returns the total price.  This List is not
 **                  modified.
 *********************************************************************/

double List::get_total_price() const
{
    return this->total_price;
}


/*********************************************************************
 ** Function: List::add_item()
 ** Description: Appends an Item to the end of items unless the Item
 **              already exists in items.  Returns true if the Item was
 **              added successfully and false otherwise.
 ** Parameters: it  the Item to add to the list
 ** Pre-Conditions: it is a valid Item.
 ** Post-Conditions: If the Item did not already exist in this List,
 **                  it is appended and true is returned.  Otherwise
 **                  the Item is not appended and false is returned.
 *********************************************************************/

bool List::add_item(const Item &it)
{
    // item in list already
    if (position(it) >= 0) return false;

    // put the item in the list and just the total price
    items.push_back(it);
    total_price += it.get_total_price();

    return true;
}


/*********************************************************************
 ** Function: List::remove_item()
 ** Description: Deletes the Item from items at the given position
 **              unless the position is invalid.   Returns true if the
 **              Item was removed successfully and false otherwise.
 ** Parameters: position    the index of the Item to be removed
 ** Pre-Conditions: none
 ** Post-Conditions: If the position is valid, the Item located at that
 **                  index of items is erased and true is returned.
 **                  Otherwise, false is returned.
 *********************************************************************/

bool List::remove_item(const int position)
{
    // if position is valid
    if (position >= 0 && position < length())
    {
        // remove the Item at position and adjust total price
        total_price -= items.at(position).get_total_price();
        items.erase(items.begin() + position);
        return true;
    }

    return false;
}



/*********************************************************************
 ** Function: List::update_item_quantity()
 ** Description: Updates the quantity of the Item from items at the
 **              given position unless the position is invalid.
 **              Returns true if the Item was changed successfully and
 **              false otherwise.
 ** Parameters: position    the index of the Item to be modified
 **             new_qty     the new quantity for the Item to have
 ** Pre-Conditions: none
 ** Post-Conditions: If the position is valid, the Item located at that
 **                  index of items is modified and true is returned.
 **                  Otherwise, false is returned.
 *********************************************************************/

bool List::update_item_quantity(const int position, const int new_qty)
{
    // if position is valid
    if (position >= 0 && position < length())
    {
        // save the original quantity
        Item item = items.at(position);
        int old_qty = item.get_quantity();

        // set the new quantity
        items.at(position).set_quantity(new_qty);

        // adjust the total price
        this->total_price += (new_qty - old_qty) * item.get_unit_price();

        return true;
    }

    return false;
}


/*********************************************************************
 ** Function: List::update_item_price()
 ** Description: Updates the price of the Item from items at the given
 **              position unless the position is invalid.   Returns
 **              true if the Item was changed successfully and false
 **              otherwise.
 ** Parameters: position    the index of the Item to be modified
 **             new_price   the new price for the Item to have
 ** Pre-Conditions: none
 ** Post-Conditions: If the position is valid, the Item located at that
 **                  index of items is modified and true is returned.
 **                  Otherwise, false is returned.
 *********************************************************************/

bool List::update_item_price(const int position, const double new_price)
{
    // if position is valid
    if (position >= 0 && position < length())
    {
        // save the original price
        Item item = items.at(position);
        double old_price = item.get_unit_price();

        // set the new price
        items.at(position).set_unit_price(new_price);

        // adjust the total price
        this->total_price += (new_price - old_price) * item.get_quantity();

        return true;
    }

    return false;
}


/*********************************************************************
 ** Function: operator<<()
 ** Description: Allows the operator << to be used for sending a
 **              set of information about a List to an object of type
 **              std::ostream.  This operator may be chained.
 ** Parameters: out     the output stream 
 **             lst     the List object
 ** Pre-Conditions: none
 ** Post-Conditions: A description of lst is sent to outstream out.
 *********************************************************************/

std::ostream& operator<<(std::ostream &out, const List &lst)
{
    // prefix each item with an item number
    for (int item_no(1); item_no <= lst.length(); ++item_no) {
        out << std::setw(2) << item_no << '\t';
        out << lst.items.at(item_no - 1);
    }

    // append a bar
    for (int i(0); i < 60; ++i)
        out << '=';

    // save original precision
    std::streamsize ss = std::cout.precision();

    // append the total price
    out << std::fixed << std::showpoint << std::setprecision(2) <<
           "\nTotal: $" << lst.total_price << '\n';

    // restore original ios flags and precision
    std::resetiosflags(std::ios::fixed);
    out.precision(ss);

    return out;
}
