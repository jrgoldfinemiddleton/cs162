/*********************************************************************
 ** Program Filename: ListClient.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/10/15
 ** Description: Contains the ListClient class function definitions.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#include "ListClient.hpp"
#include "List.hpp"
#include "Item.hpp"
#include "utilities.hpp"

#include <iostream>
#include <limits>


/*********************************************************************
 ** Function: ListClient::print_list()
 ** Description: Displays the shopping list in its current state.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The shopping list appears in the console.
 *********************************************************************/

void ListClient::print_list() const
{
    std::cout << shopping_list;
}


/*********************************************************************
 ** Function: ListClient::display_menu()
 ** Description: Displays a menu listing the following options: print
 **              the shopping list, add an item to the list, remove an
 **              item from the list, update the quantity or unit price
 **              of an item, or exit.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The menu appears in the console.
 *********************************************************************/

void ListClient::display_menu() const
{
    std::cout << "Welcome to the Shopping List Builder.  What would you " <<
                 "like to do?\n\n" << 
                 "\t1) Print the shopping list\n" <<
                 "\t2) Add an item to the list\n" <<
                 "\t3) Remove an item from the list\n" <<
                 "\t4) Modify an item's quantity\n" <<
                 "\t5) Modify an item's price\n" <<
                 "\t6) Exit the program\n\n";
}


/*********************************************************************
 ** Function: ListClient::do_users_bidding()
 ** Description: Interprets the user's validated choice from the menu
 **              and carries out the correct action.
 ** Parameters: bid     the user's validated choice
 ** Pre-Conditions: bid is a value between 1 and 6.
 ** Post-Conditions: Based on the value of bid, this function will
 **                  complete the user's chosen task.  Note that this
 **                  function may exit the program.
 *********************************************************************/

void ListClient::do_users_bidding(const int bid)
{
    switch(bid)
    {
        case 1:
           print_list(); break;
        case 2:
           add_new_item(); break;
        case 3:
           remove_item(); break;
        case 4:
           update_quantity(); break;
        case 5:
           update_price(); break;
        case 6:
           exit(0);
    }
}


/*********************************************************************
 ** Function: ListClient::add_new_item()
 ** Description: Prompts the user to enter an item name, purchasing
 **              unit, quantity desired, and a unit price.  Then the
 **              function will create an Item with the validated
 **              information and add it to the List if it is not
 **              already there.  Note that this method will not be
 **              able to change the quantity of an item already in the
 **              list.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Each value requested from the user is validated,
 **                  with the user prompted repeatedly for input until
 **                  it is valid.  A new item is added to the list if
 **                  the item is not already there.  The user is
 **                  notified of either success or failure.
 *********************************************************************/

void ListClient::add_new_item()
{

    // print header and prompt for info about a single Item
    std::cout << "ADD NEW ITEM\n\nitem name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "purchasing unit: ";
    std::string unit;
    std::getline(std::cin, unit);

    std::cout << "quantity desired: ";
    int qty = utilities::get_valid_int_in_range(1,
            std::numeric_limits<int>::max());

    std::cout << "price ($): ";
    double price =
        utilities::get_valid_double_in_range(0.0,
                std::numeric_limits<double>::max());

    // create Item from the info
    Item item(name, unit, qty, price);

    // will only add Item if an equivalent one isn't there yet
    if (shopping_list.add_item(item))
        std::cout << "\nYour item has been added to the list.\n";
    else
        std::cout << "\nYour item is already in the list.\n";
}


/*********************************************************************
 ** Function: ListClient::remove_item()
 ** Description: Deletes an Item from the List.  The function displays
 **              the List to the user and prompts the user to enter
 **              the number of the item (s)he wishes to delete.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: If the List has no Items, the user is notified and
 **                  nothing is prompted for.  Otherwise, the user is
 **                  shown the List and prompted to enter the item
 **                  number to be deleted.  If the user enters a
 **                  non-existent item number, the user is notified and
 **                  nothing else is done.  If the user enters a valid
 **                  list item number, the corresponding Item is
 **                  removed from the List.
 *********************************************************************/

void ListClient::remove_item()
{
    // print header
    std::cout << "REMOVE ITEM\n\n";

    // tell user if List is empty
    if (shopping_list.length() < 1) {
        std::cout << "List is empty.  There is nothing to remove.\n";
        return;
    }

    // otherwise print List and ask user which position to remove
    print_list();
    std::cout << "\nWhich item do you want to remove? ";
    int position = utilities::get_valid_int() - 1;
    
    // only remove an Item if the user gave a valid position
    if (position >= 0 && position < shopping_list.length())
    {
        shopping_list.remove_item(position);
        std::cout << "Your item has been removed from the list.\n";
    }
    else
        std::cout << "Invalid item.  Could not remove.\n";
}


/*********************************************************************
 ** Function: ListClient::update_quantity()
 ** Description: Changes the quantity of a particular Item in the List.
 **              The function displays the List to the user and prompts
 **              the user to enter the number of the item (s)he wishes
 **              to modify.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: If the List has no Items, the user is notified and
 **                  nothing is prompted for.  Otherwise, the user is
 **                  shown the List and prompted to enter the item
 **                  number to be updated.  If the user enters a
 **                  non-existent item number, the user is notified and
 **                  nothing else is done.  If the user enters a valid
 **                  list item number, the corresponding Item's
 **                  quantity property is updated.
 *********************************************************************/

void ListClient::update_quantity()
{
    // print header
    std::cout << "UPDATE ITEM QUANTITY\n\n";

    // tell user if List is empty
    if (shopping_list.length() < 1) {
        std::cout << "List is empty.  There is nothing to update.\n";
        return;
    }

    // otherwise print List and ask user which position to update
    print_list();

    std::cout << "\nWhich item do you want to change? ";
    int position = utilities::get_valid_int() - 1;

    // only update an Item if the user gave a valid position   
    if (position >= 0 && position < shopping_list.length())
    {
        // get the new quantity and update it
        std::cout << "\nNew quantity: ";
        int new_qty =
            utilities::get_valid_int_in_range(1,
                    std::numeric_limits<int>::max());

        shopping_list.update_item_quantity(position, new_qty);
        std::cout << "Your item has been updated.\n";
    }
    else
        std::cout << "Invalid item.  Could not update.\n";
}


/*********************************************************************
 ** Function: ListClient::update_price()
 ** Description: Changes the price of a particular Item in the List.
 **              The function displays the List to the user and
 **              prompts the user to enter the number of the item
 **              (s)he wishes to modify.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: If the List has no Items, the user is notified and
 **                  nothing is prompted for.  Otherwise, the user is
 **                  shown the List and prompted to enter the item
 **                  number to be updated.  If the user enters a
 **                  non-existent item number, the user is notified and
 **                  nothing else is done.  If the user enters a valid
 **                  list item number, the corresponding Item's
 **                  unit price property is updated.
 *********************************************************************/

void ListClient::update_price()
{
    // print header
    std::cout << "UPDATE ITEM PRICE\n\n";

    // tell user if List is empty
    if (shopping_list.length() < 1) {
        std::cout << "List is empty.  There is nothing to update.\n";
        return;
    }

    // otherwise print List and ask user which position to update
    print_list();

    std::cout << "\nWhich item do you want to change? ";
    int position = utilities::get_valid_int() - 1;
    
    // only update an Item if the user gave a valid position   
    if (position >= 0 && position < shopping_list.length())
    {
        // get the new quantity and update it
        std::cout << "\nNew price: ";
        double new_price =
            utilities::get_valid_double_in_range(0.0,
                    std::numeric_limits<double>::max());

        shopping_list.update_item_price(position, new_price);
        std::cout << "Your item has been updated.\n";
    }
    else
        std::cout << "Invalid item.  Could not update.\n";
}


/*********************************************************************
 ** Function: ListClient::menu_selection()
 ** Description: Displays the menu and prompts the user to choose an
 **              option from the List.  Then the function does the
 **              users bidding and waits for the user to press ENTER
 **              to continue.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The menu is displayed and the user is repeatedly
 **                  prompted for an integer between 1 and 6 until the
 **                  user makes a valid selection.  The user's choice
 **                  is obeyed.  The function ends execution only after
 **                  the user presses ENTER.
 *********************************************************************/

void ListClient::menu_selection()
{
    // clear the display and show the menu
    system("clear");
    display_menu();


    // get the user's choice
    std::cout << "User choice: ";
    int choice =  utilities::get_valid_int();
    
    // keep prompting the user until the choice is valid
    while (choice < 1 || choice > 6)
    {
        system("clear"); 
        display_menu();
        std::cout << "User choice: ";

        choice =  utilities::get_valid_int();
    }
    
    // complete the requested task
    system("clear");
    do_users_bidding(choice);

    // wait for user to press a key
    std::cout << "\nPRESS ENTER TO RETURN TO MENU...\n";
    std::cin.get();
}


/*********************************************************************
 ** Function: ListClient::run()
 ** Description: Repeatedly displays the menu and allows the user to
 **              perform operations on the List.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: The menu is displayed repeatedly until the user
 **                  opts to exit the program.
 *********************************************************************/

void ListClient::run()
{
    // repeatedly display the menu and prompt for user selection
    while (true)
        menu_selection();
}
