/*********************************************************************
 ** Program Filename: HiScore.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the HiScore class. This
 **              class updates or displays the name of the player
 **              who most quickly beat the game and how many turns it
 **              it took.
 *********************************************************************/


#ifndef HI_SCORE_HPP
#define HI_SCORE_HPP

#include <fstream>
#include <iostream>
#include <string>


class HiScore
{
private:
  const std::string filename;
  std::fstream file;
  
public:
  HiScore() : filename("text/score.txt") { }
  
  void add(const std::string& name, int turns);
  
  void clear_all() { file.open(filename, std::ios::out | std::ios::trunc); file.close(); }
  
  void print_best();
};

#endif /* HI_SCORE_HPP */
