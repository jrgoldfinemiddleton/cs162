/*********************************************************************
 ** Program Filename: Item.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: Contains the Item class function declarations and
 **              a friend function to overload the << and ==
 **              operators.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#include "Item.hpp"

#include <iostream>     // for input and output
#include <iomanip>      // for manipulating the output stream


/*********************************************************************
 ** Function: Item::Item()
 ** Description: This constructor initializes an Item with a name,
 **              a unit type, a quantity, and a unit price.
 ** Parameters: name    the name of the item
 **             unit    the type of unit
 **             qty     the quantity of the unit
 **             price   the unit price
 ** Pre-Conditions: qty > 1 and price >= 0.00.
 ** Post-Conditions: An Item with the given information is initialized.
 *********************************************************************/

Item::Item(std::string name, std::string unit, int qty, double price) :
    item_name(name), unit(unit), quantity(qty), unit_price(price)
{
    return;
}


/*********************************************************************
 ** Function: Item::get_item_name()
 ** Description: Returns this Item's name.
 ** Parameters: none
 ** Pre-Conditions: item_name has been initialized.
 ** Post-Conditions: Returns the name.  This Item is not modified.
 *********************************************************************/

std::string Item::get_item_name() const
{
    return this->item_name;
}


/*********************************************************************
 ** Function: Item::get_unit()
 ** Description: Returns this Item's unit type.
 ** Parameters: none
 ** Pre-Conditions: unit has been initialized.
 ** Post-Conditions: Returns the unit type.  This Item is not
 **                  modified.
 *********************************************************************/

std::string Item::get_unit() const
{
    return this->unit;
}


/*********************************************************************
 ** Function: Item::get_quantity()
 ** Description: Returns this Item's quantity.
 ** Parameters: none
 ** Pre-Conditions: quantity has been initialized.
 ** Post-Conditions: Returns the quantity.  This Item is not
 **                  modified.
 *********************************************************************/

int Item::get_quantity() const
{
    return this->quantity;
}


/*********************************************************************
 ** Function: Item::get_unit_price()
 ** Description: Returns this Item's unit price.
 ** Parameters: none
 ** Pre-Conditions: unit_price has been initialized.
 ** Post-Conditions: Returns the unit price.  This Item is not
 **                  modified.
 *********************************************************************/

double Item::get_unit_price() const
{
    return this->unit_price;
}


/*********************************************************************
 ** Function: Item::get_total_price()
 ** Description: Returns this Item's total price, taking into accout
 **              its quantity and unit price.
 ** Parameters: none
 ** Pre-Conditions: quantity and unit_price have been initialized.
 ** Post-Conditions: Returns this Item's total price.  This Item is not
 **                  modified.
 *********************************************************************/

double Item::get_total_price() const
{
    return this->quantity * this->unit_price;
}


/*********************************************************************
 ** Function: Item::set_quantity()
 ** Description: Updates the quantity of this Item to a new value.
 ** Parameters: qty     the new quantity
 ** Pre-Conditions: qty > 0.
 ** Post-Conditions: quantity is updated to the value of qty.
 *********************************************************************/

void Item::set_quantity(const int qty)
{
    this->quantity = qty;
}


/*********************************************************************
 ** Function: Item::set_unit_price()
 ** Description: Updates the unit price  of this Item to a new value.
 ** Parameters: price   the new unit price
 ** Pre-Conditions: price >= 0.00.
 ** Post-Conditions: unit_price is updated to the value of price.
 *********************************************************************/

void Item::set_unit_price(const double price)
{
    this->unit_price = price;
}


/*********************************************************************
 ** Function: operator<<()
 ** Description: Allows the operator << to be used for sending a
 **              set of information about an Item to an object of type
 **              std::ostream.  This operator may be chained.
 ** Parameters: out     the output stream 
 **             it     the Item object
 ** Pre-Conditions: none
 ** Post-Conditions: A description of it is sent to outstream out.
 *********************************************************************/

std::ostream& operator<<(std::ostream &out, const Item& it)
{
    // save original precision
    std::streamsize ss = std::cout.precision();

    // add info to stream
    out << std::setw(50) << std::left <<
        it.item_name << '\n' << '\t' <<
        "unit: " << std::setw(10) << it.unit << "  " <<
        "quantity: " << std::setw(5) << it.quantity << "  " << 
        std::fixed << std::showpoint << std::setprecision(2) <<
        "unit price: $" << it.unit_price << '\n' << '\t' << 
        "total price: $" << it.get_total_price() << "\n\n" <<
        std::noshowpoint;

    // restore original ios flags and precision
    std::resetiosflags(std::ios::fixed);
    out.precision(ss);

    return out;
}


/*********************************************************************
 ** Function: operator==()
 ** Description: Allows the operator == to be used for determining
 **             whether two Item objects are equivalent.  Note that
 **             the quantity property of each Item is irrelevant.
 ** Parameters: it1     the left-hand Item 
 **             it2     the right-hand Item
 ** Pre-Conditions: The properties of each Item are fully initialized.
 ** Post-Conditions: Returns true if the Items are equivalent and false
 **                  otherwise.
 *********************************************************************/

bool operator==(const Item &it1, const Item &it2)
{
    // true if all properties are the same except quantity
    return it1.item_name == it2.item_name &&
           it1.unit == it2.unit &&
           it1.unit_price == it2.unit_price;
}

