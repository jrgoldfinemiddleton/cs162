/*********************************************************************
 ** Program Filename: Menu.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Menu class.
 *********************************************************************/


#include <iomanip>

#include "Menu.hpp"


/*********************************************************************
 ** Function: Menu::display()
 ** Description: Prints the menu to the screen.
 ** Parameters: none
 *********************************************************************/

void Menu::display()
{
  std::cout << header << "\n\n";
  
  int pos = 1;
  
  for (std::deque<std::string>::iterator it = options.begin(); it != options.end(); ++it, ++pos)
    std::cout << std::setw(3) << pos << ". " << *it << '\n';
  
  for (int i = 0; i < 5; ++i)
    std::cout << '\n';
}
