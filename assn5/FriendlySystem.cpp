/*********************************************************************
 ** Program Filename: FriendlySystem.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              FriendlySystem class.
 *********************************************************************/


#include "FriendlySystem.hpp"
#include "MonetaryEvent.hpp"
#include "TaxEvent.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: FriendlySystem::special()
 ** Description: Plays out the occurrences that happen to the user
 **              on this FriendlySystem this turn.  If the user's ship
 **              has fuel, it is possible to jump to a new System.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 *********************************************************************/

void FriendlySystem::special()
{
  System::special();
  
  utilities::clear_display();
  
  // 20% chance of finding money
  if (rand() % 100 < 20)
  {
    MonetaryEvent me(player);
    me.run();
    
    utilities::wait_for_user();
    utilities::clear_display();
  }
  
  // 10% chance of getting taxed
  if (rand() % 100 < 10)
  {
    TaxEvent te(player);
    te.run();
    
    utilities::wait_for_user();
  }
  
  // done with menu
  bool done = false;
  
  // already asked for info?
  bool asked = false;
  
  
  while (!done)
  {
    utilities::clear_display();
    
    make_menu();
    
    int num_ops = static_cast<int>(system_menu.get_num_options());
    
    system_menu.display();
    
    // get user choice
    std::cout << "What would you like to do?\n";
    int choice = utilities::get_valid_int_in_range(1, num_ops);
    
    utilities::clear_display();
    
    std::string map_header = std::string("========== Map - Current System: ") + player->get_cur_system()->get_name() + " ==========\n\n";
    
    switch (choice)
    {
      case 1: done = true; break;
      case 2: player->print_status("========== Status ==========\n\n"); break;
      case 3: std::cout << map_header; view_map(); break;
      case 4: open_store(); break;
      case 5: sell(); break;
      case 6: refuel(); break;
      case 7: repair(); break;
      case 8: buy_ship(); break;
      case 9:
      {
        if (!asked)
        {
          ask_info();
          asked = true;
        }
        else
          std::cout << "You have already gotten all the information you can get right now!\n\n";
        
        break;
      }
      default: jump_to(choice); done = true; // wants to jump
    }
    
    utilities::wait_for_user();
  }
}