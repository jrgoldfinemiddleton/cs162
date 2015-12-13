/*********************************************************************
 ** Program Filename: Info.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the definition of the Info class.
 **              This class provides text templates that are used to
 **              display hints to the player about where the next key
 **              Item may be found.
 *********************************************************************/


#ifndef INFO_HPP
#define INFO_HPP

#include <string>
#include <vector>

#include "Map.hpp"
#include "Pilot.hpp"
#include "System.hpp"

class Info
{
private:
  std::vector<std::string> _template0;
  std::vector<std::string> _template1;
  std::vector<std::string> _template2;
  std::vector<std::string> _template3;
  
  std::string key_item_name;
  bool paid;
  System_Type sys_type;
  Map* map;
  Pilot* player;
  
  void get_info(std::string key);
  
public:
  Info(Pilot* p, Map* map, System_Type type, std::string key_item, bool paid = true);
  
  void run();
};

#endif /* INFO_HPP */
