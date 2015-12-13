/*********************************************************************
 ** Program Filename: HiScore.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              HiScore class.
 *********************************************************************/


#include <sstream>

#include "HiScore.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: HiScore::add()
 ** Description: Updates the best score if turns is at least as good
 **              as the previously stored best.
 ** Parameters: name      the name of the Pilot
 **             turns     turns taken to win the game
 ** Pre-Conditions: there must already be a score and name in the file
 *********************************************************************/

void HiScore::add(const std::string& name, int turns)
{
  file.open(filename, std::ios::in);
  
  std::string sc_str;
  getline(file, sc_str, ',');
  
  int score = std::stoi(sc_str);
  
  if (turns <= score)
  {
    file.close();
    file.open(filename, std::ios::out | std::ios::trunc);
    
    file << turns << ',' << name;
  }
  
  file.close();
}


/*********************************************************************
 ** Function: HighScore::print_best()
 ** Description: Displays the name and score of the player who has won
 **              the game quickest.
 ** Parameters: none
 *********************************************************************/

void HiScore::print_best()
{
  file.open(filename, std::ios::in);
  
  std::string sc_str;
  getline(file, sc_str, ',');
  
  int score = std::stoi(sc_str);
  
  std::stringstream ss;
  char ch;
  
  while (file.get(ch))
    ss << ch;
  
  std::string name = ss.str();

  std::cout << name << '\n' << score << " turns\n\n";
  
  utilities::wait_for_user();
  
  file.close();
}