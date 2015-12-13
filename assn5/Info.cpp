/*********************************************************************
 ** Program Filename: Info.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Info class.
 *********************************************************************/


#include <limits>

#include "Info.hpp"
#include "System.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: Info::Info()
 ** Description: Constructs an Info object with templates for the
 **              display of info on different System types.
 ** Parameters: p         the user
 **             map       the universe
 **             type      the current System's type
 **             key_item  the key Item the user seeks
 **             bool      whether the user will have to pay for info
 *********************************************************************/

Info::Info(Pilot* p, Map* map, System_Type type, std::string key_item, bool paid) :
          key_item_name(key_item), paid(paid), sys_type(type), map(map), player(p)
{
  _template0.push_back("\"");
  _template0.push_back("exclamation");
  _template0.push_back("  You just made me ");
  _template0.push_back("stupidweird");
  _template0.push_back("  Pay more attention, you ");
  _template0.push_back("insult");
  _template0.push_back(".  Seems like you need some information about the ");
  _template0.push_back("key");
  _template0.push_back(".  Pay me and I\'ll tell you about it.\"\n\n");
  
  _template1.push_back("\"");
  _template1.push_back("greeting");
  _template1.push_back("  I see you\'re not from around these parts.  Can I help you with something, ");
  _template1.push_back("fellow");
  _template1.push_back("?  Oh, I see, you want to find the ");
  _template1.push_back("key");
  _template1.push_back(".  That's located in the ");
  _template1.push_back("get_system");
  _template1.push_back(" system.  ");
  _template1.push_back("hashtag");
  _template1.push_back("\"\n\n");

  _template2.push_back("\"");
  _template2.push_back("greeting");
  _template2.push_back("  I am ");
  _template2.push_back("name");
  _template2.push_back(".  I am ");
  _template2.push_back("alliteration");
  _template2.push_back("  What?  I\'m rambling?  ");
  _template2.push_back("apology");
  _template2.push_back("  Didn\'t mean to waste your time.  So, ");
  _template2.push_back("what");
  _template2.push_back(" do you want?  Oh, I see, you wanted to know where to find the ");
  _template2.push_back("key");
  _template2.push_back(".  I've heard that it\'s in the ");
  _template2.push_back("get_system");
  _template2.push_back(" system.\"\n\n");
  
  _template3.push_back("\"Praise ");
  _template3.push_back("higherbeing");
  _template3.push_back("!  What a refreshing experience I just had.  I feel reborn in a spiritual sense. It\'s as though ");
  _template3.push_back("bizarrestate");
  _template3.push_back("  Oh, sorry, I may be one of ");
  _template3.push_back("civilization");
  _template3.push_back(" but I actually can\'t help you find the ");
  _template3.push_back("key");
  _template3.push_back(".  Unless, that is, you happen to have a few extra ducats.  ");
  _template3.push_back("hashtag");
  _template3.push_back("\"\n\n");
}


/*********************************************************************
 ** Function: Info::get_info()
 ** Description: Displays some information about where the next key
 **              Item may be found.  It is not always accurate.
 ** Parameters: key     the descriptor for this System and whether
 **                     the user will have to pay for info
 ** Pre-Conditions: the relevant text files are on the hard disk in
 **                 the correct location
 *********************************************************************/

void Info::get_info(std::string key)
{
  std::vector<std::string> temp;
  
  // choose respective template
  if (key == "enemy")
    temp = _template0;
  else if (key == "friend")
    temp = _template1;
  else if (key == "neu_free")
    temp = _template2;
  else
    temp = _template3;
  
  // go through the template
  for (int i = 0; i < static_cast<int>(temp.size()); ++i)
  {
    // even elements are strings to print
    if (i % 2 == 0)
      std::cout << temp.at(i);
    
    else // get string from text file
    {
      // key item currently sought
      if (temp.at(i) == "key")
        std::cout << key_item_name;
      
      // system the next key item might be in
      else if (temp.at(i) == "get_system")
      {
        if (key == "friend")
          // 30% chance of being wrong
          std::cout <<
          ((rand() % 100 < 30) ? map->get_random_nonempty()->get_name() : map->get_key_loc());
        
        else
          // 50% chance of being wrong
          std::cout <<
          ((rand() % 100 < 50) ? map->get_random_nonempty()->get_name() : map->get_key_loc());
      }
      
      else // get phrase from file
      {
        std::vector<std::string> g(utilities::get_shuffled_lines_from_file("text/" + temp.at(i) + ".txt"));
        std::cout << g.at(0);
      }
    }
  }
  
  // information will be correct if paid for
  if (key == "enemy" || key == "neu_paid")
  {
    int charge = 0;
    
    // how much character wants from the user for the info
    if (key == "enemy") charge = rand() % 3000 + 500;
    else charge = rand() % 1500 + 1;
    
    std::cout << "This dude wants " << charge << " ducats for the information.\n\n";
    
    if (player->get_money() < charge)
    {
      std::vector<std::string> animals = utilities::get_shuffled_lines_from_file("text/animal.txt");
      std::vector<std::string> butts = utilities::get_shuffled_lines_from_file("text/butt.txt");
      std::string bootay = butts.at(0);
      
      std::cout << "Unfortunately you're too poor for that, and you decide not to haggle.  "  <<
                   "For some reason, today just doesn't seem like the right day to get your " <<
                   bootay << " kicked by some weirdo in a" << animals.at(0) << " suit.\n\n";
      return;
    }
    
    std::cout << "Do you want to pay for help finding the " << key_item_name << "? (y/n) ";
    
    
    char c = std::cin.get();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (c == 'y' || c == 'Y')
    {
      std::cout << "\n\nHe wrote down " << map->get_key_loc() << " and as you went into your space suit " <<
                "pocket for the money, you realized that exactly " << charge <<
                " ducats were already gone.  When you looked up, you couldn't find him anywhere.\n\n";
      
      player->gain_money(-charge);
    }
    
    else
      std::cout << "\n\nWithout another word, the dude is gone, leaving you standing in a cloud of " <<
                   "space dust.\n\n";
  }
}


/*********************************************************************
 ** Function: Info::run()
 ** Description: Displays some information to the user regarding the
 **              location of the next key Item.
 ** Parameters: none
 ** Post-Conditions: the correct get_info() call is made
 *********************************************************************/

void Info::run()
{
  switch (sys_type)
  {
    case FRIENDLY: get_info("friend"); break;
    case ENEMY: get_info("enemy"); break;
    case NEUTRAL: paid ? get_info("neu_paid") : get_info("neu_free"); break;
    case EMPTY: case INVALID: return;
  }
}