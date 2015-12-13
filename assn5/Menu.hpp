/*********************************************************************
 ** Program Filename: Menu.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Menu class.  The Menu
 **              is a utility class for generating printable menus.
 *********************************************************************/


#include <deque>
#include <iostream>
#include <string>

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
  std::string header;
  
  std::deque<std::string> options;
  
public:
  Menu() { }
  
  void add_option(int position, std::string option) { options.insert(options.begin() + position, option); }
  
  void display();
  
  long get_num_options() const { return options.size(); }
  
  void remove_option(int position) { options.erase(options.begin() + position); }
  
  void set_header(std::string title) { header = "=========== " + title + " ==========="; }
};

#endif /* MENU_HPP */