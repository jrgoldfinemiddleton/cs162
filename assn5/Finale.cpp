/*********************************************************************
 ** Program Filename: Finale.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Finale class.
 *********************************************************************/


#include <algorithm>
#include <iostream>
#include <limits>
#include <unistd.h>

#include "Finale.hpp"
#include "Item.hpp"


/*********************************************************************
 ** Function: Finale::show()
 ** Description: Prints a summary of the user's game and also allows
 **              the user the option to decode the Chronicles of
 **              Sharnia.
 ** Parameters: none
 *********************************************************************/

void Finale::show()
{
  std::cout << "========== Summary ==========\n\n";
  
  std::cout << "Mission " << (player->won() ? "Successful!" : "Failed!") << "\n\n";
  
  player->print_status("");
  
  utilities::wait_for_user();
  
  std::cout << "Systems Visited: \n\n";
  
  // print map indicating visited systems
  map->print_universe(false);
  
  std::cout << "\n";
  
  utilities::wait_for_user();
  
  if (player->won())
  {
    std::cout << "The Chronicles of Sharnia contain the sum total of human wisdom.  \n" <<
    "Do you want to see what they contain? (y/n)\n";
    
    char c;
    c = std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (c == 'y' || c == 'Y')
    {
      std::cout << "Using the Decoder...\n\n";
      
      usleep(1000000);
      
      std::cout << "And the answer is...\n\n";
      
      usleep(1000000);
      
      std::cout << "1... "  << std::flush(std::cout);
      
      usleep(1000000);
      
      std::cout << "2... "  << std::flush(std::cout);
      
      usleep(2000000);
      
      std::cout << "3...\n\n" << std::flush(std::cout);
      
      usleep(3000000);
      
      // select a random proverb
      std::vector<std::string> proverbs = utilities::get_shuffled_lines_from_file("text/proverbs.txt");
      std::string msg = proverbs.at(0);
      
      // capitalize the string
      std::transform(msg.begin(), msg.end(), msg.begin(), toupper);
      
      std::cout << msg << "\n\n";
    }
    
    utilities::wait_for_user();
  }
}