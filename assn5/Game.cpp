/*********************************************************************
 ** Program Filename: Game.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              Game class.
 *********************************************************************/


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

#include "Game.hpp"
#include "Finale.hpp"
#include "HiScore.hpp"
#include "KeyItemEvent.hpp"
#include "DrunkEvent.hpp"


/*********************************************************************
 ** Function: Game::Game()
 ** Description: Constructs a new Game and allows the user to enter
 **              his/her name.  The universe is built and all Items
 **              are configured.  The first key item is hidden and
 **              the user's starting location is determined.
 ** Parameters: none
 ** Post-Conditions: srand() has been run
 *********************************************************************/

Game::Game() : cur_tick(0), next_key(0)
{
  // seed the random number generator
  srand(static_cast<unsigned int>(time(0)));
  rand();
  
  std::cout << "Welcome to the quest for the Chronicles of Sharnia.\nPlease enter your name: ";
  std::string name;
  std::getline(std::cin, name);
  std::cout << '\n';
  
  // the user
  player = new Pilot(name);
  
  std::cout << "Your ship is a " << player->get_ship()->get_name() << ".  A sage has blessed your " <<
               "noble quest and given you " << player->get_money() << " ducats.  Good luck!\n\n";
  
  utilities::wait_for_user();
  
  // create all regular and key items
  init_items();
  
  // build game universe
  universe = new Map(reg_items, player);
  
  // choose random starting location
  player->set_cur_system(universe->get_random_friendly());
  
  // hide the first key item
  move_next_key_item();
  
  // don't let the player find the first key item on the first turn
  while (key_loc == player->get_cur_system()->get_name())
    move_next_key_item();
  
  // make sure current system knows what key item user is seeking
  player->get_cur_system()->set_next_key(key_items.at(next_key).get_name());
}


/*********************************************************************
 ** Function: Game::init_items()
 ** Description: Creates all the key and regular Items the Game will
 **              use and sets their stats.
 ** Parameters: none
 *********************************************************************/

void Game::init_items()
{
  // generate key items
  key_items.push_back(Item("Electron MipMap", "A map of the universe that shows visited star systems.",
                           0, 0.0, 0.0, 0, 0, true));
  key_items.push_back(Item("Eye of the Hack", "Allows a pilot to relax at times.",
                           0, 0.0, 0.0, 0, 0, true));
  key_items.push_back(Item("Decoder of Doom", "Makes it possible to decode the Chronicles of Sharnia.",
                           0, 0.0, 0.0, 0, 0, true));
  key_items.push_back(Item("Chronicles of Sharnia", "Stores the ancient wisdom of humanity.",
                           0, 0.0, 0.0, 0, 0, true));
  
  // generate reg items
  
  // speed
  reg_items.push_back(Item("Troll Booster", "Minimally increases a ship's speed.",
                           50, 0.0, 0.0, 0, 6, false));
  reg_items.push_back(Item("Neutron Booster", "Moderately increases a ship's speed.",
                           150, 0.0, 0.0, 0, 13, false));
  reg_items.push_back(Item("Hyper Booster", "Drastically increases a ship's speed.",
                           350, 0.0, 0.0, 0, 28, false));
  reg_items.push_back(Item("Quantum Booster", "Increases a ship's speed by an unbelievable amount.",
                           800, 0.0, 0.0, 0, 49, false));
  
  // attack
  reg_items.push_back(Item("Bum Gun", "Minimally increases a ship's firepower.",
                           60, 1.05, 0.0, 0, 0, false));
  reg_items.push_back(Item("Maestro Gun", "Moderately increases a ship's firepower.",
                           200, 1.1, 0.0, 0, 0, false));
  reg_items.push_back(Item("Dream Gun", "Drastically increases a ship's firepower.",
                           460, 1.2, 0.0, 0, 0, false));
  reg_items.push_back(Item("Ultraplex Gun", "Increases a ship's firepower by a massive amount.",
                           1000, 1.5, 0.0, 0, 0, false));
  
  // armor
  reg_items.push_back(Item("Sad Sack Shield", "Minimally increases a ship's armor.",
                           70, 0.0, 1.05, 0, 0, false));
  reg_items.push_back(Item("Onto Shield", "Moderately increases a ship's armor.",
                           180, 0.0, 1.2, 0, 0, false));
  reg_items.push_back(Item("Santo Shield", "Drastically increases a ship's armor.",
                           390, 0.0, 1.3, 0, 0, false));
  reg_items.push_back(Item("Mondo Shield", "Increases a ship's armor by a massive amount.",
                           820, 0.0, 1.4, 0, 0, false));
  
  // health
  reg_items.push_back(Item("Small HP Boost", "Minimally increases a ship's health points.",
                           70, 0.0, 0.0, 5, 0, false));
  reg_items.push_back(Item("Medium HP Boost", "Moderately increases a ship's health points.",
                           340, 0.0, 0.0, 20, 0, false));
  reg_items.push_back(Item("Large HP Boost", "Drastically increases a ship's health points.",
                           560, 0.0, 0.0, 50, 0, false));
  reg_items.push_back(Item("Mega HP Boost", "Increases a ship's health points by a massive amount.",
                           1200, 0.0, 0.0, 80, 0, false));
}


/*********************************************************************
 ** Function: Game::hide_next_key_item()
 ** Description: Hides the next key Item and updates what key Item
 **              the user is looking for.
 ** Parameters: none
 ** Pre-Conditions: the user just found a key item
 *********************************************************************/

inline void Game::hide_next_key_item()
{
  ++next_key;
  move_next_key_item();
}


/*********************************************************************
 ** Function: Game::hints()
 ** Description: Prints some hints for playing the game.
 ** Parameters: none
 *********************************************************************/

void Game::hints()
{
  std::cout << "*  There are four key items you must obtain in order to complete your quest, the last " <<
  "of which is the Chronicles of Sharnia.\n\n";
  
  std::cout << "*  Only press ENTER when prompted, or you will miss valuable information.\n\n";
  
  std::cout << "*  The maximum number of items you may keep with you at any time is 7.  This includes " <<
  "your key items.\n\n";
  
  std::cout << "*  Buying a new ship will give you full health, a full fuel tank, and you will still " <<
  "keep all items you have bought.\n\n";
  
  std::cout << "*  If you are out of money, stick around in your current star system.  Sometimes you " <<
  "will come upon random sums of money.\n\n";
  
  std::cout << "*  You never know which star system you'll start in nor where it will be.  Asking for " <<
  "information is a good way to learn about star systems you may want to be on the lookout " <<
  "for.\n\n";
  
  std::cout << "*  Not all characters providing information know what they're talking about.\n\n";
  
  utilities::wait_for_user();
  utilities::clear_display();
  
  std::cout << "*  Be careful about trying to save up money.  Although it will help you buy powerful " <<
  "ships and pay for needed repairs and refuelings, it could easily be taxed away from " <<
  "you.\n\n";
  
  std::cout << "*  Speed is only helpful if you and the remaining enemies have very low health and you " <<
  "want to be sure you will strike first.\n\n";
  
  std::cout << "*  Running out of time to complete your quest isn't something to worry about until you " <<
  "find the second key item, the Eye of the Hack.  You tend to get a bit more distracted " <<
  "once you have that item.\n\n";
  
  std::cout << "*  Try to remember which nearby star systems are friendly.  They are much more " <<
  "affordable and there's no risk of being ambushed by enemy ships.\n\n";
  
  std::cout << "*  Perhaps the best bargains are the HP-boosting items.\n\n";
  
  utilities::wait_for_user();
}


/*********************************************************************
 ** Function: Game::move_next_key_item()
 ** Description: Chooses a system to hide the next key Item in.
 ** Parameters: none
 ** Post-Conditions: lets the Map know where the Item is hidden
 *********************************************************************/

inline void Game::move_next_key_item()
{
  // choose a random location to store next key item
  key_loc = universe->get_random_nonempty()->get_name();
  
  // let all systems know where it's hidden
  universe->set_key_loc(key_loc);
}


/*********************************************************************
 ** Function: Game::play()
 ** Description: Runs the entire Chronicles of Sharnia game and keeps
 **              track of whether the game has been won within the
 **              turn limit.
 ** Parameters: none
 *********************************************************************/

void Game::play()
{
  // game loop
  while (++cur_tick <= MAX_TICKS && !(player->is_dead()) && !(player->won()))
  {
    // keep player's tick counter in sync
    player->add_ticks(1);
    
    System *loc = player->get_cur_system();
    
    // user found the next key item
    if (loc->get_name() == key_loc)
    {
      Item cur_key = key_items.at(next_key);
      KeyItemEvent ke(player, &cur_key);
      ke.run();
      
      utilities::wait_for_user();
      
       // user got the Item
      if (ke.done() && cur_key.get_name() != "Chronicles of Sharnia")
        hide_next_key_item();
    }
    
    if (!(player->won()))
    {
      // make sure current system knows what key item user is seeking
      loc->set_next_key(key_items.at(next_key).get_name());
      
      // see what happens on this system and display menu
      loc->special();
      
      // user can get drunk once the Eye of the Hack is found
      if (!(player->is_dead()) && loc->get_type() != EMPTY && player->get_drunk())
      {
        // random number of turns are lost
        int wasted_days = rand() % 8 + 3;
        cur_tick += wasted_days;
        player->add_ticks(wasted_days);
        
        DrunkEvent de(player, wasted_days);
        de.run();
      }
    }
  }
  
  // game over, print results
  Finale fin(player, universe);
  fin.show();
  
  if (player->won())
  {
    HiScore hs;
    
    // update best score if this player won faster than any previous
    hs.add(player->get_name(), cur_tick);
  }
}


/*********************************************************************
 ** Function: Game::story()
 ** Description: Prints the premise of the game.
 ** Parameters: none
 *********************************************************************/

void Game::story()
{
  std::cout << "You are a space-farer of the future.  The ancient civilization of humanity slipped " <<
               "into decay and in-fighting ages ago.  A few wise humans left their humble home Earth " <<
               "in the Solar System and brought with them some artifacts of their once-great " <<
               "civilization.  You have heard many stories about these people and you have also learned " <<
               "recently that Earth no longer exists, having been swallowed up by its star, the Sun, " <<
               "when it ballooned into an aging red giant.\n\n";
  
  utilities::wait_for_user();
  utilities::clear_display();
  
  std::cout << "Being fascinated by ancient myths and a fan of perennial philosophy, you have decided " <<
               "to embark on a quest through the universe, visiting different star systems in search of " <<
               "the Chronicles of Sharnia, which has said by the space sages to contain the sum total " <<
               "of human wisdom.  On your journey, you will only have your trusty ship and the dark, " <<
               "black space to bring you comfort.  (Oh, and maybe some space drink too.)  Do you have " <<
               "what it takes to navigate through the perilous space-scape?  Will you be able to make " <<
               "friends where you need them?\n\n";
  
  utilities::wait_for_user();
  utilities::clear_display();
  
  std::cout << "It is said that the quest is urgent now, allowing you at most " << MAX_TICKS << " jumps between star " <<
               "systems to find the Chronicles of Sharnia before they degrade from cosmic radiation.\n\n";
  
  std::cout << "Still, there are also those who believe that, if these treasures degrade, the true " <<
               "cause will be the vindictive spirits of those the humans once perturbed in their " <<
               "ruckus.\n\n";
  
  utilities::wait_for_user();
}