/*********************************************************************
 ** Program Filename: FightEvent.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 12/03/15
 ** Description: Contains the member function definitions for the
 **              FightEvent class.
 *********************************************************************/


#include <algorithm>    // std::sort
#include <cstdlib>      // rand()
#include <unistd.h>     // usleep()

#include "FightEvent.hpp"
#include "utilities.hpp"


/*********************************************************************
 ** Function: FightEvent::FightEvent()
 ** Description: Constructs a new FightEvent for the user with
 **              a pre-chosen number of ally and enemy ships.
 ** Parameters: p       the user
 **             allies  number of ally ships
 **             enemies number of enemy ships
 ** Post-Conditions: random allies and enemies will be selected and
 **                  displayed to the user
 *********************************************************************/

FightEvent::FightEvent(Pilot* p, int allies, int enemies) : Event(p)
{
  std::cout << "Ack!  It's an ambush!!\n\n";
  
  // determine allies and enemies
  find_allies(allies);
  find_enemies(enemies);
  
  print_enemies();
  print_allies();
}


/*********************************************************************
 ** Function: FightEvent::attack_area()
 ** Description: Plays out a single area-wide attack.
 ** Parameters: attacker      the attacking ship
 **             side          role of the attacker
 **             attk          strength of the attack
 **             opponents     vector containing all ships on the
 **                           opposite team aside from, perhaps,
 **                           the user's ship
 *********************************************************************/

void FightEvent::attack_area(Fighter* attacker, Role side, int attk, std::vector<Fighter*>& opponents)
{
  std::string opponent;
  std::string desc;
  
  switch (side)
  {
    case PLAYER: opponent = "Enemy "; desc = "You"; break;
    case AL: opponent = "Enemy "; desc = "Ally "; break;
    case EN: opponent = "Ally "; desc = "Enemy "; break;
  }
  
  // attack all opponents
  for (int k = 0; k < static_cast<int>(opponents.size()); ++k)
  {
    Fighter *cur_opponent = opponents.at(k);
    
    int damage = attk - cur_opponent->get_base_armor();
    if (damage < 0) damage = 0;
    
    std::cout << opponent << cur_opponent->get_name() << " took " << damage << " damage.\n";
    
    // take damage
    cur_opponent->defend(damage);
    
    // remove opponent if destroyed
    if (cur_opponent->get_cur_health() <= 0)
    {
      std::cout << (side != EN ? "Success!  " : "Shoot!  ") << desc << (side == PLAYER ? "" : attacker->get_name()) << " destroyed " <<
      opponent << cur_opponent->get_name() << "!\n";
      
      opponents.erase(opponents.begin() + k);
      k--;
    }
  }
  
  // attack the player
  if (side == EN)
  {
    int damage = attk - get_modified_armor();
    if (damage < 0) damage = 0;
    
    std::cout << "You took " << damage << " damage.\n";
    
    // take damage
    player->get_ship()->defend(damage);
  }
}


/*********************************************************************
 ** Function: FightEvent::attack_one()
 ** Description: Plays out a single targeted attack.
 ** Parameters: attacker      the attacking ship
 **             side          role of the attacker
 **             attk          strength of the attack
 **             defender      the defending ship
 **             opp_team      vector containing defender
 **             opp_pos       position of defender in opp_team, -1 is
 **                           a dummy value for user's ship
 *********************************************************************/

void FightEvent::attack_one(Fighter* attacker, Role side, int attk, Fighter* defender, std::vector<Fighter*>& opp_team, int opp_pos)
{
  std::string opponent;
  std::string desc;
  
  switch (side)
  {
    case PLAYER: opponent = "Enemy "; desc = "You "; break;
    case AL: opponent = "Enemy "; desc = "Ally "; break;
    case EN: opponent = "Ally "; desc = "Enemy "; break;
  }
  
  int damage;
  
  // user's ship is being attacked
  if (defender == player->get_ship())
    damage = attk - get_modified_armor();
  
  else
    damage = attk - defender->get_base_armor();
  
  if (damage < 0) damage = 0;
  
  std::cout << (defender == player->get_ship() ? "You" : opponent + defender->get_name()) << " took " << damage << " damage.\n";
  
  // take damage
  defender->defend(damage);
  
  // remove defeated ship from its list
  if (defender != player->get_ship() && defender->get_cur_health() <= 0)
  {
    std::cout << (side != EN ? "Success!  " : "Shoot!  ") << (side == PLAYER ? "You" : desc + attacker->get_name()) << " destroyed " << opponent <<
    defender->get_name() << "!\n";
    
    opp_team.erase(opp_team.begin() + opp_pos);
  }
}


/*********************************************************************
 ** Function: FightEvent::print_allies()
 ** Description: Displays information about the user's allies.
 ** Parameters: none
 *********************************************************************/

void FightEvent::print_allies()
{
  if (allies.size() == 1)
    std::cout << "A " << allies.at(0)->get_name() << " has come to your aid.\n";
  
  else
  {
    long num_allies = allies.size();
    std::cout << num_allies << " ships have come to help you.  They are the following:\n";
    
    for (int i = 0; i < num_allies; ++i)
      std::cout << allies.at(i)->get_name() << '\n';
  }
  
  std::cout << '\n';
}


/*********************************************************************
 ** Function: FightEvent::print_enemies()
 ** Description: Displays information about the user's enemies.
 ** Parameters: none
 *********************************************************************/

void FightEvent::print_enemies()
{
  if (enemies.size() == 1)
    std::cout << "A " << enemies.at(0)->get_name() << " has decided to attack you!\n";
  
  else
  {
    long num_enemies = enemies.size();
    std::cout << "A fleet of " << num_enemies << " ships have arrived and they are hostile!  " <<
                 "They are the following:\n";
    
    for (int i = 0; i < num_enemies; ++i)
      std::cout << enemies.at(i)->get_name() << '\n';
  }
  
  std::cout << '\n';
}


/*********************************************************************
 ** Function: FightEvent::find_allies()
 ** Description: Choose number of random ally ships.
 ** Parameters: number    how many allies to choose
 *********************************************************************/

void FightEvent::find_allies(int number)
{
  for (int i = 0; i < number; ++i)
    allies.push_back(get_random_ship());
}


/*********************************************************************
 ** Function: FightEvent::find_enemies()
 ** Description: Choose number of random enemy ships.
 ** Parameters: number    how many enemies to choose
 *********************************************************************/

void FightEvent::find_enemies(int number)
{
  for (int i = 0; i < number; ++i)
    enemies.push_back(get_random_ship());
}


/*********************************************************************
 ** Function: FightEvent::get_random_ship()
 ** Description: Creates a new Fighter ship randomly and returns a
 **              a pointer to it.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 ** Post-Conditions: a new Fighter object is created on the heap
 *********************************************************************/

Fighter* FightEvent::get_random_ship()
{
  // the 8 types of fighter ships
  enum Ship_Type
  {
    WW, VS, TE, RA, SL, SX, LA, BQ
  };
  
  // increasing order of rarity
  std::vector<int> ship_nos;
  ship_nos.push_back(WW);
  ship_nos.push_back(VS);
  ship_nos.push_back(TE);
  ship_nos.push_back(RA);
  ship_nos.push_back(SL);
  ship_nos.push_back(SX);
  ship_nos.push_back(LA);
  ship_nos.push_back(BQ);
  
  // add up to 100%
  std::vector<int> ship_likelihoods;
  ship_likelihoods.push_back(20);
  ship_likelihoods.push_back(20);
  ship_likelihoods.push_back(20);
  ship_likelihoods.push_back(15);
  ship_likelihoods.push_back(10);
  ship_likelihoods.push_back(10);
  ship_likelihoods.push_back(4);
  ship_likelihoods.push_back(1);
  
  // choose a random ship type
  int ship_no = utilities::random_from_frequency_map(ship_nos, ship_likelihoods);
  
  switch (ship_no)
  {
    case WW: return new Windweeper;
    case VS: return new Voltsweeper;
    case TE: return new TrollE;
    case RA: return new Raw;
    case SL: return new SleazeLiner;
    case SX: return new Suxel;
    case LA: return new Lamborqini;
    case BQ: return new Bolq;
    default:
    {
      std::cerr << "FightEvent::get_random_ship() Error: invalid ship selected!\n";
      return new Windweeper;
    }
  }
}


/*********************************************************************
 ** Function: FightEvent::get_modified_attack()
 ** Description: Applies player's Item stats to calculate ship's
 **              actual attack power.
 ** Parameters: none
 *********************************************************************/

int FightEvent::get_modified_attack()
{
  double mod = 1.0;
  
  std::vector<Item> *items = player->get_items();
  long num_items = items->size();
  
  for (int i = 0; i < num_items; ++i)
    mod += items->at(i).get_attack_mod();
  
  return static_cast<int>(mod * (player->get_ship()->get_base_attack()));
}


/*********************************************************************
 ** Function: FightEvent::get_modified_armor()
 ** Description: Applies player's Item stats to calculate ship's
 **              actual armor.
 ** Parameters: none
 *********************************************************************/

int FightEvent::get_modified_armor()
{
  double mod = 1.0;
  
  std::vector<Item> *items = player->get_items();
  long num_items = items->size();
  
  for (int i = 0; i < num_items; ++i)
    mod += items->at(i).get_armor_mod();
  
  return static_cast<int>(mod * (player->get_ship()->get_base_armor()));
}


/*********************************************************************
 ** Function: FightEvent::get_modified_speed()
 ** Description: Applies player's Item stats to calculate ship's
 **              actual speed.
 ** Parameters: none
 *********************************************************************/

int FightEvent::get_modified_speed()
{
  int mod = 0;
  
  std::vector<Item> *items = player->get_items();
  long num_items = items->size();
  
  for (int i = 0; i < num_items; ++i)
    mod += items->at(i).get_speed_mod();
  
  return mod + player->get_ship()->get_base_speed();
}


/*********************************************************************
 ** Function: FightEvent::get_modified_health()
 ** Description: Applies player's Item stats to calculate ship's
 **              actual number of hit points.
 ** Parameters: none
 *********************************************************************/

int FightEvent::get_modified_health()
{
  int mod = 0;
  
  std::vector<Item> *items = player->get_items();
  long num_items = items->size();
  
  for (int i = 0; i < num_items; ++i)
    mod += items->at(i).get_health_mod();
  
  return mod + player->get_ship()->get_cur_health();
}


/*********************************************************************
 ** Function: FightEvent::get_max_speed()
 ** Description: Returns the maximum speed found among all ships in
 **              this current FightEvent.
 ** Parameters: none
 *********************************************************************/

int FightEvent::get_max_speed()
{
  // determine user's ship's speed
  int max = get_modified_speed();
  
  long num_allies = allies.size();
  for (int i = 0; i < num_allies; ++i)
  {
    int speed = allies.at(i)->get_base_speed();
    if (speed > max)
      max = speed;
  }
  
  long num_enemies = enemies.size();
  for (int i = 0; i < num_enemies; ++i)
  {
    int speed = enemies.at(i)->get_base_speed();
    if (speed > max)
      max = speed;
  }
  
  return max;
}


/*********************************************************************
 ** Function: FightEvent::comp_speed()
 ** Description: Returns true if f1 is faster than f2 and false
 **              otherwise.
 ** Parameters: f1    first Fighter
 **             f2    second Fighter
 *********************************************************************/

bool FightEvent::comp_speed(Fighter* f1, Fighter* f2)
{
  return f1->get_base_speed() > f2->get_base_speed();
}


/*********************************************************************
 ** Function: FightEvent::is_enemy()
 ** Description: Returns true if f is the player's enemy, and false
 **              otherwise.
 ** Parameters: f     the Fighter to check
 *********************************************************************/

bool FightEvent::is_enemy(Fighter* f)
{
  for (int i = 0; i < static_cast<int>(enemies.size()); ++i)
    if (f == enemies.at(i))
      return true;
  
  return false;
}


/*********************************************************************
 ** Function: FightEvent::is_ally()
 ** Description: Returns true if f is the player's ally, and false
 **              otherwise.  The player's ship counts as an ally.
 ** Parameters: f     the Fighter to check
 *********************************************************************/

bool FightEvent::is_ally(Fighter* f)
{
  for (int i = 0; i < static_cast<int>(allies.size()); ++i)
    if (f == allies.at(i))
      return true;
  
  // for convenience, user's ship is an ally
  if (f == player->get_ship())
    return true;
  
  return false;
}


/*********************************************************************
 ** Function: FightEvent::run()
 ** Description: Plays out the actual fight, allowing each ship to
 **              in order of speed, until either all enemy ships have
 **              been destroyed or the user's ship is destroyed.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run
 ** Post-Conditions: all Fighters allocated on the heap are destroyed
 **                  except the user's
 *********************************************************************/

void FightEvent::run()
{
  // store all the fighters except the users
  std::vector<Fighter*> all_fighters;
  
  for (int i = 0; i < static_cast<int>(allies.size()); ++i)
    all_fighters.push_back(allies.at(i));
  
  for (int i = 0; i < static_cast<int>(enemies.size()); ++i)
    all_fighters.push_back(enemies.at(i));
  
  // sort from fastest to slowest
  std::sort(all_fighters.begin(), all_fighters.end(), comp_speed);
  
  // find the correct index to insert the user's ship
  int i = 0;
  for (; i < static_cast<int>(all_fighters.size()) && all_fighters.at(i)->get_base_speed() > get_modified_speed(); ++i);
  
  if (i == static_cast<int>(all_fighters.size()))
    all_fighters.push_back(player->get_ship());
  
  else
    all_fighters.insert(all_fighters.begin() + i, player->get_ship());

  int round = 1;
  
  // fight until user's ship destroyed or no more enemies left
  while (get_modified_health() > 0 && enemies.size() > 0)
  {
    usleep(3000000);
    
    utilities::clear_display();
    
    std::cout << "\n==== Fight Round " << round << " ====\n\n";
    
    // let each fighter have a chance to fight
    for (int j = 0; j < static_cast<int>(all_fighters.size()) && get_modified_health() > 0 && enemies.size() > 0; ++j)
    {
      Fighter* cur_fighter = all_fighters.at(j);
      
      // fighter is dead
      if (!is_ally(cur_fighter) && !is_enemy(cur_fighter))
      {
        all_fighters.erase(all_fighters.begin() + j);
        delete cur_fighter;
        cur_fighter = NULL;
        
        // adjust index based on the removed fighter
        j--;
      }
      
      // fighter is still alive and can attack
      else
      {
        int area_wide_attk = 0;
        int reg_attk = 0;
        
        // user gets to attack
        if (cur_fighter == player->get_ship())
        {
          // only one of these can be non-zero
          area_wide_attk = cur_fighter->is_area_wide() ? get_modified_attack() : 0;
          reg_attk = cur_fighter->is_area_wide() ? 0 : get_modified_attack();
          
          // do attack affecting all enemies
          if (area_wide_attk > 0)
            attack_area(cur_fighter, PLAYER, area_wide_attk, enemies);
          
          // do attack targeting a single enemy
          else if (reg_attk > 0)
          {
            // attack a random enemy
            int who_attacked = rand() % enemies.size();
            Fighter *attacked = enemies.at(who_attacked);

            attack_one(cur_fighter, PLAYER, reg_attk, attacked, enemies, who_attacked);
          }
        }
        
        // ally is attacking the enemies
        else if (is_ally(cur_fighter))
        {
          // only one of these can be non-zero
          area_wide_attk = cur_fighter->attack_enemies();
          reg_attk = cur_fighter->attack_enemy();
          
          // do attack affecting all enemies
          if (area_wide_attk > 0)
            attack_area(cur_fighter, AL, area_wide_attk, enemies);
          
          // do attack targeting a single enemy
          else if (reg_attk > 0)
          {
            // attack a random enemy
            int who_attacked = rand() % enemies.size();
            Fighter *attacked = enemies.at(who_attacked);
            
            attack_one(cur_fighter, AL, reg_attk, attacked, enemies, who_attacked);
          }
        }
        
        // enemy is attacking you and your allies
        else
        {
          // only one of these can be non-zero
          area_wide_attk = cur_fighter->attack_enemies();
          reg_attk = cur_fighter->attack_enemy();
          
          // do attack affecting all allies and user
          if (area_wide_attk > 0)
            attack_area(cur_fighter, EN, area_wide_attk, allies);
          
          // do attack targeting a single ally or the user
          else if (reg_attk > 0)
          {
            // attack a random ally
            int who_attacked = 0;
            
            if (allies.size() > 0)
              who_attacked = rand() % allies.size() + 1;
            
            // user's ship was attacked
            if (who_attacked == static_cast<int>(allies.size()))
            {
              const int IGNORE = -1;
              attack_one(cur_fighter, EN, reg_attk, player->get_ship(), allies, IGNORE);
            }
            
            // ally's ship was attacked
            else
            {
              Fighter *attacked = allies.at(who_attacked);
              
              attack_one(cur_fighter, EN, reg_attk, attacked, allies, who_attacked);
            }
          }
        }
      }
    }
    
    // next fight round
    ++round;
  }
  
  std::cout << std::endl;
  
  // clean up all the pointers of ships that weren't defeated
  for (int m = 0; m < static_cast<int>(all_fighters.size()); ++m)
  {
    Fighter *cur = all_fighters.at(m);
    
    if (cur != player->get_ship())
    {
      delete cur;
      cur = NULL;
    }
  }
  
  if (get_modified_health() > 0)
  {
    std::cout << "You managed to survive with " << get_modified_health() << " health!\n\n";
    
    int winnings = rand() % 400 + 1;
    std::cout << "You came up on " << winnings << " ducats!\n\n";
    
    player->gain_money(winnings);
    player->won_battle();
  }
  
  else
  {
    std::cout << "Darn!  You died.  Game over!\n\n";
    player->died();
  }
}