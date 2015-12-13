/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: A program to run the Chronicles of Sharnia space
 **              adventure console game.
 *********************************************************************/


#include <iostream>

#include "Game.hpp"
#include "HiScore.hpp"
#include "Menu.hpp"
#include "utilities.hpp"


void credits();


int main(int argc, const char * argv[]) {

  // main program menu
  Menu m;
  
  m.set_header("THE CHRONICLES OF SHARNIA");
  m.add_option(0, "Play Game");
  m.add_option(1, "The Story");
  m.add_option(2, "Hints");
  m.add_option(3, "Quickest Win");
  m.add_option(4, "Credits");
  m.add_option(5, "Exit");
  
  // done with program
  bool done = false;
  
  while (!done)
  {
    utilities::clear_display();
    
    m.display();
    
    std::cout << "Choice: ";
    int choice = utilities::get_valid_int_in_range(0, static_cast<int>(m.get_num_options()));
    
    utilities::clear_display();
    
    switch (choice)
    {
      case 1:
      {
        Game g;
        g.play();
        break;
      }
      case 2: Game::story(); break;
      case 3: Game::hints(); break;
      case 4:
      {
        HiScore hs;
        hs.print_best();
        break;
      }
      case 5: credits(); break;
      default: done = true; break;
    }
  }
  
  return 0;
}


/*********************************************************************
 ** Function: credits()
 ** Description: Displays the author's name and date created.
 ** Parameters: none
 *********************************************************************/

void credits()
{
  std::cout << "Created by Jason Goldfine-Middleton on 3 December, 2015.\n\n";
  utilities::wait_for_user();
}
