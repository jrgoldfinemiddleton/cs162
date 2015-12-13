/*********************************************************************
 ** Program Filename: utilities.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: This file provides implementations for each function
 **              in the utilities namespace declared in utilities.hpp.
 **
 **              get_valid_int() was inspired by a post at
 **              https://stackoverflow.com/questions/15184906/
 **              can-you-stop-letters-being-entered-for-an-integer .
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/

#include "utilities.hpp"

#include <algorithm>
#include <cstdlib>          // for exit
#include <fstream>          // for file opening
#include <iostream>         // for input and output
#include <limits>           // for clearing the input buffer
#include <random>
#include <string>           // for std::string
#include <vector>           // for std::vector


/*********************************************************************
 ** Function: utilities::clear_display()
 ** Description: Clear the visible console screen.
 ** Parameters: none
 *********************************************************************/

void utilities::clear_display()
{
  for (int i = 0; i < 100; ++i)
    std::cout << '\n';
}


/*********************************************************************
 ** Function: utilities::get_shuffled_line_from_file()
 ** Description: Returns all lines from a file in random order.
 ** Parameters: filename      the name of file to get lines from
 *********************************************************************/

std::vector<std::string> utilities::get_shuffled_lines_from_file(std::string filename)
{
  std::ifstream file(filename);
  
  std::vector<std::string> vs;
  
  std::string line;
  
  std::getline(file, line);
  
  while (file)
  {
    vs.push_back(line);
    std::getline(file, line);
  }
  
  std::random_shuffle(vs.begin(), vs.end(), rng);
  
  file.close();
  
  return vs;
}


/*********************************************************************
 ** Function: utilities::get_valid_int()
 ** Description: Waits for the user to enter a valid int value.
 **              Each time the user enters an invalid value, it
 **              prompts the user with an error message to try again.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input int is returned.
 *********************************************************************/

int utilities::get_valid_int()
{
  int in_val = 0;
  
  // get input till valid int is received
  while (!(std::cin >> in_val))
  {
    std::cout << "Bad input!  Please enter an integer.\n";
    
    // clear error bits
    std::cin.clear();
    // ignore the rest of the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  // clear any trailing characters in the input buffer
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  return in_val;
}



/*********************************************************************
 ** Function: utilities::get_valid_int_in_range()
 ** Description: Waits for the user to enter a valid int value
 **              between low and high. Each time the user enters an
 **              invalid value, it prompts the user with an error
 **              message to try again.
 ** Parameters: low     the minimum value allowed
 **             high    the maximum value allowed
 ** Pre-Conditions: low is less than high.
 ** Post-Conditions: A user-input int between low and high is returned.
 *********************************************************************/

int utilities::get_valid_int_in_range(const int low, const int high)
{
  int in_val;
  bool done = false;
  do
  {
    in_val = utilities::get_valid_int();
    
    if (in_val < low || in_val > high)
      std::cout << "Value must be between " << low << " and " <<
      high << ".\n";
    else
      done = true;
  }
  while (!done);
  
  return in_val;
}

/*********************************************************************
 ** Function: utilities::get_valid_double()
 ** Description: Waits for the user to enter a valid double value.
 **              Each time the user enters an invalid value, it
 **              prompts the user with an error message to try again.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input double is returned.
 *********************************************************************/

double utilities::get_valid_double()
{
  double in_val = 0.0;
  
  // get input till valid double is received
  while (!(std::cin >> in_val))
  {
    std::cout << "Bad input!  Please enter a number.\n";
    
    // clear error bits
    std::cin.clear();
    
    // ignore the rest of the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  
  // clear any trailing characters in the input buffer
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  return in_val;
}


/*********************************************************************
 ** Function: utilities::get_valid_double_in_range()
 ** Description:  Waits for the user to enter a valid double value
 **              between low and high. Each time the user enters an
 **              invalid value, it prompts the user with an error
 **              message to try again.
 ** Parameters: low     the minimum value allowed
 **             high    the maximum value allowed
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input double is returned.
 *********************************************************************/

double utilities::get_valid_double_in_range(
                                            const double low, const double high)
{
  double in_val;
  bool done = false;
  do
  {
    in_val = utilities::get_valid_double();
    
    if (in_val < low || in_val > high)
      std::cout << "Value must be between " << low << " and " <<
      high << ".\n";
    else
      done = true;
  }
  while (!done);
  
  return in_val;
}


/*********************************************************************
 ** Function: utilities::open_in_file()
 ** Description: Given a filestream and a filename, attempts to open
 **              the file for reading and returns the stream.
 ** Parameters: fs  the filestream
 **             fn  the filename
 ** Pre-Conditions: fs must not already be bound to a file
 ** Post-Conditions: either the file "fn" is opened or an error is
 **                  printed and the program exits
 *********************************************************************/

std::ifstream& utilities::open_in_file(std::ifstream& fs, std::string fn)
{
  // attempt to open the file
  fs.open(fn.c_str());
  
  if (fs.fail())
  {
    std::cerr << "Could not open file \'" << fn << "\'.\n";
    exit(1);
  }
  
  return fs;
}


/*********************************************************************
 ** Function: utilities::open_out_file()
 ** Description: Given a filestream and a filename, attempts to open
 **              the file for writing and returns the stream.
 ** Parameters: fs  the filestream
 **             fn  the filename
 ** Pre-Conditions: fs must not already be bound to a file
 ** Post-Conditions: either the file "fn" is opened or an error is
 **                  printed and the program exits
 *********************************************************************/

std::ofstream& utilities::open_out_file(std::ofstream& fs, std::string fn)
{
  // attempt to open the file
  fs.open(fn.c_str());
  
  if (fs.fail())
  {
    std::cerr << "Could not open file \'" << fn << "\'.\n";
    exit(1);
  }
  
  return fs;
}


/*********************************************************************
 ** Function: utilities::rng()
 ** Description: Returns a random integer from 0 to max - 1.
 ** Parameters: max     the upper limit
 *********************************************************************/

int utilities::rng(int max)
{
  return rand() % max;
}


/*********************************************************************
 ** Function: utilities::random_from_frequency_map()
 ** Description: Gets a random integer value from vals based on its
 **              corresponding likelihood.
 ** Parameters: vals          the list of values to randomly choose
 **             likelihood    the percent chance that the
 **                           corresponding value will be chosen
 ** Pre-Conditions: elements of likelihood must add up to 100, vals
 **                 and likelihood have the same number of elements
 ** Post-Conditions: returns -1 if the sizes of the vectors are not
 **                  the same
 *********************************************************************/

int utilities::random_from_frequency_map(const std::vector<int>& vals, const std::vector<int>& likelihood)
{
  const int ERROR = -1;
  
  if (vals.size() != likelihood.size())
    return ERROR;
  
  int rand_val = rand() % 100 + 1;
  int sum = 0;
  long size = likelihood.size();
  
  for (int i = 0; i < size; ++i)
  {
    sum += likelihood.at(i);
    if (rand_val <= sum)
      return vals.at(i);
  }
  
  return ERROR;
}


/*********************************************************************
 ** Function: utilities::wait_for_user()
 ** Description: Waits for the user to press a key and then clears the
 **              input buffer.
 ** Parameters: none
 *********************************************************************/

void utilities::wait_for_user()
{
  std::cout << "Press Enter.\n";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
