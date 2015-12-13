/*********************************************************************
 ** Program Filename: utilities.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: This header file includes the declarations for
 **              for functions in the utilities namespace which
 **              provide I/O validation.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <fstream>
#include <string>
#include <vector>

namespace utilities
{
  void clear_display();
  
  double get_valid_double();
  double get_valid_double_in_range(const double low, const double high);
  int get_valid_int();
  int get_valid_int_in_range(const int low, const int high);
  
  std::ifstream& open_in_file(std::ifstream& fs, std::string fn);
  std::ofstream& open_out_file(std::ofstream& fs, std::string fn);
  
  std::vector<std::string> get_shuffled_lines_from_file(std::string filename);
  
  // need srand()
  int random_from_frequency_map(const std::vector<int>& vals, const std::vector<int>& likelihood);
  int rng(int max);
  
  void wait_for_user();
}

#endif /* UTILITIES_HPP */
