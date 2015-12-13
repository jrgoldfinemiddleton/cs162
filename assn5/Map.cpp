/*********************************************************************
 ** Program Filename: Map.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Map class.
 *********************************************************************/


#include <iomanip>    // std::left, std::right, std::setw()

#include "Map.hpp"


/*********************************************************************
 ** Function: Map::~Map()
 ** Description: Destructs this Map and deallocates all memory storing
 **              the Systems it contains.
 ** Parameters: none
 *********************************************************************/

Map::~Map()
{
  // deallocate all systems
  for (int i = 0; i < WIDTH * HEIGHT; ++i)
    delete grid[i];
}


/*********************************************************************
 ** Function: Map::get_all_visited()
 ** Description: Returns a vector containing the names of all Systems
 **              the user has been to.
 ** Parameters: none
 *********************************************************************/

std::vector<std::string> Map::get_all_visited()
{
  std::vector<std::string> visited;
  
  for (int i = 0; i < WIDTH * HEIGHT; ++i)
  {
    if (grid[i]->has_been_visited())
      visited.push_back(grid[i]->get_name());
  }
  
  return visited;
}


/*********************************************************************
 ** Function: Map::get_upper()
 ** Description: Returns the System above the one at pos in the
 **              universe.
 ** Parameters: pos   the position of the System whose upper neighbor
 **                   is desired
 *********************************************************************/

inline System* Map::get_upper(int pos)
{
  int up_pos = pos - WIDTH;
  return (up_pos >= 0) ? grid[up_pos] : NULL;
}


/*********************************************************************
 ** Function: Map::get_right()
 ** Description: Returns the System right of the one at pos in the
 **              universe.
 ** Parameters: pos   the position of the System whose right neighbor
 **                   is desired
 *********************************************************************/

inline System* Map::get_right(int pos)
{
  int rt_pos = pos + 1;
  return ((pos % WIDTH != WIDTH - 1) && (rt_pos < WIDTH * HEIGHT)) ? grid[rt_pos] : NULL;
}


/*********************************************************************
 ** Function: Map::get_lower()
 ** Description: Returns the System below the one at pos in the
 **              universe.
 ** Parameters: pos   the position of the System whose lower neighbor
 **                   is desired
 *********************************************************************/

inline System* Map::get_lower(int pos)
{
  int dn_pos = pos + WIDTH;
  return (dn_pos < WIDTH * HEIGHT) ? grid[dn_pos] : NULL;
}


/*********************************************************************
 ** Function: Map::get_upper()
 ** Description: Returns the System left of the one at pos in the
 **              universe.
 ** Parameters: pos   the position of the System whose left neighbor
 **                   is desired
 *********************************************************************/

inline System* Map::get_left(int pos)
{
  int lt_pos = pos - 1;
  return ((pos % WIDTH != 0) && (lt_pos >= 0)) ? grid[lt_pos] : NULL;
}


/*********************************************************************
 ** Function: Map::get_random_friendly()
 ** Description: Returns a random FriendlySystem in this universe.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 ** Post-Conditions: there is at least one FriendlySystem.
 *********************************************************************/

System* Map::get_random_friendly()
{
  // store all friendly systems
  std::vector<System*> valid_systems;
  
  for (int i = 0; i < WIDTH * HEIGHT; ++i)
  {
    if (grid[i]->get_type() == FRIENDLY)
      valid_systems.push_back(grid[i]);
  }
  
  // return a random one
  return valid_systems.at(rand() % valid_systems.size());
}


/*********************************************************************
 ** Function: Map::get_random_nonempty()
 ** Description: Returns a random System that is not an EmptySystem
 **              in this universe.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 ** Pre-Conditions: there is at least one System that is not an
 **                 EmptySystem
 *********************************************************************/

System* Map::get_random_nonempty()
{
  // store all non-empty systems
  std::vector<System*> valid_systems;
  
  for (int i = 0; i < WIDTH * HEIGHT; ++i)
  {
    if (grid[i]->get_type() != EMPTY)
      valid_systems.push_back(grid[i]);
  }
  
  // return a random one
  return valid_systems.at(rand() % valid_systems.size());
}


/*********************************************************************
 ** Function: Map::print_empty_square()
 ** Description: Prints a part of an empty square in the map.
 ** Parameters: i     the position in the row of the map
 *********************************************************************/

void Map::print_empty_square(int i)
{
  std::cout << "||" << std::left << std::setw(11) << "" <<
  (i == WIDTH - 1 ? "||\n" : "") << std::right;
}


/*********************************************************************
 ** Function: Map::print_named_square()
 ** Description: Prints the name of the System in its map square.
 ** Parameters: sys   the System index in grid
 **             i     the position in the row of the map
 *********************************************************************/

void Map::print_named_square(int sys, int i)
{
  std::cout << "||" << std::left << std::setw(11) << grid[sys]->get_name().substr(0, 10) <<
  (i == WIDTH - 1 ? "||\n" : "") << std::right;
}


/*********************************************************************
 ** Function: Map::print_universe()
 ** Description: Displays a map of the universe to the user.
 ** Parameters: all   true if all names should print, false otherwise
 ** Post-Conditions: if all is false, only displays visited Systems
 *********************************************************************/

void Map::print_universe(bool all)
{
  const int CELL_WIDTH = 11;
  const int WALL_WIDTH = 3;
  const int PRINT_WIDTH = WIDTH * (CELL_WIDTH + WALL_WIDTH) - WALL_WIDTH;
  
  // used to navigate through all elements of grid
  int sys_counter = 0;
  
  for (int j = 0; j < HEIGHT; ++j)
  {
    // print upper bars
    for (int k = 0; k < PRINT_WIDTH; ++k)
      std::cout << '=';
    
    std::cout <<'\n';
    
    for (int k = 0; k < 2; ++k)
      for (int i = 0; i < WIDTH; ++i)
        std::cout << "||           " << (i == WIDTH - 1 ? "||\n" : "");
    

    for (int i = 0; i < WIDTH; ++i)
    {
      // if all true or the system has been visited system's name is displayed in the map
      (all || (grid[sys_counter]->has_been_visited())) ? print_named_square(sys_counter, i) : print_empty_square(i);
      ++sys_counter;
    }
    
    for (int k = 0; k < 2; ++k)
      for (int i = 0; i < WIDTH; ++i)
        std::cout << "||           " << (i == WIDTH - 1 ? "||\n" : "");
  }
  
  // print lower bar
  for (int k = 0; k < PRINT_WIDTH; ++k)
    std::cout << '=';
  
  std::cout << "\n\n";
}


/*********************************************************************
 ** Function: Map::set_up_universe()
 ** Description: Allocates all Systems in the universe and
 ** Parameters:
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/

void Map::set_up_universe()
{
  // set of all possible system names
  std::vector<std::string> names = utilities::get_shuffled_lines_from_file("text/system.txt");
  
  for (int i = 0; i < WIDTH * HEIGHT; ++i)
  {
    // used to determine which type each system will be
    int lucky_num = rand() % 100;
    
    // 25% chance of being empty
    if (lucky_num < 25)
      grid[i] = new EmptySystem(names.at(i), avail_items, player, this);
    
    // 25% chance of being neutral
    else if (lucky_num < 50)
      grid[i] = new NeutralSystem(names.at(i), avail_items, player, this);
    
    // 30% chance of being friendly
    else if (lucky_num < 80)
      grid[i] = new FriendlySystem(names.at(i), avail_items, player, this);
    
    // 20% chance of being enemy
    else
      grid[i] = new EnemySystem(names.at(i), avail_items, player, this);
  }
  
  // let each system know its four neighbors
  for (int i = 0; i < WIDTH * HEIGHT; ++i)
    grid[i]->set_up_neighbors(get_upper(i), get_right(i), get_lower(i), get_left(i));
}