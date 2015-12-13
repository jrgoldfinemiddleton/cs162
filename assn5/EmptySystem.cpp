/*********************************************************************
 ** Program Filename: EmptySystem.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              EmptySystem class.
 *********************************************************************/


#include "EmptySystem.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: EmptySystem::special()
 ** Description: Plays out the occurrences that happen to the user
 **              on this EmptySystem this turn.  If the user's ship
 **              has fuel, it is possible to jump to a new System.
 ** Parameters: none
 *********************************************************************/

void EmptySystem::special()
{
  System::special();
  
  utilities::clear_display();
  
  // user's ship has no fuel, see if help comes
  if (player->get_fuel() == 0)
  {
    AidEvent ae(player);
    ae.run();
    
    utilities::wait_for_user();
  }
  
  // user had or got fuel
  if (player->get_fuel() > 0)
  {
    // finished with the menu
    bool done = false;
    
    // display menu
    while (!done)
    {
      utilities::clear_display();
      
      System::special();
      
      system_menu.display();
      
      int num_ops = static_cast<int>(system_menu.get_num_options());
      
      std::cout << "What would you like to do?\n";
      int choice = utilities::get_valid_int_in_range(1, num_ops);
      
      utilities::clear_display();
      
      std::string map_header = std::string("========== Map - Current System: ") + player->get_cur_system()->get_name() + " ==========\n\n";
      
      switch (choice)
      {
        case 1: done = true; break;
        case 2: player->print_status("========== Status ==========\n\n"); break;
        case 3: std::cout << map_header; view_map(); break;
        default: jump_to(choice); done = true; // wants to jump
      }
      
      utilities::wait_for_user();
    }
  }
  
  // user out of fuel
  else
    std::cout << "You will have to wait a bit for help.\n";
}