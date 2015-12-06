/*********************************************************************
** Program Filename: CombatRunner.cpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
** Description: Contains the implementation of the CombatRunner class
**              member functions.
*********************************************************************/

#include "CombatRunner.hpp"

#include <cstdlib>      // for srand()
#include <ctime>        // for time()
#include <iostream>     // for std::cout


/*********************************************************************
** Function: CombatRunner::CombatRunner()
** Description: Constructs a CombatRunner from two pointers to
**              Queue objects, each containing a number of Creature
**              pointers.
** Parameters: s1   player 1's team
**             s2   player 2's team
** Pre-Conditions: s1 and s2 contain no NULL pointers
** Post-Conditions: all instance fields initialized, including three
**                  Stacks on the heap
*********************************************************************/

CombatRunner::CombatRunner(Queue* s1, Queue* s2)
{
    // set random seed
    srand(time(0));
    side1 = s1;
    side2 = s2;

    losers1 = new Stack;
    losers2 = new Stack;
    losers = new Stack;

    cur_sim = 0;
    side1pts = 0;
    side2pts = 0;
}


/*********************************************************************
** Function: CombatRunner::~CombatRunner()
** Description: Destructs this CombatRunner and frees all heap memory.
** Parameters: none
** Pre-Conditions: the Stacks have not been deallocated yet
** Post-Conditions: the Stacks have been deallocated
*********************************************************************/

CombatRunner::~CombatRunner()
{
    delete losers1;
    delete losers2;
    delete losers;
}


/*********************************************************************
** Function: CombatRunner::run_tournament()
** Description: Plays a tournament battle between the two teams,
**              matching up two Creatures and letting them duke it out
**              until one is KOed.  After a Creature defeats an
**              opponent, he is placed at the back of his lineup to
**              fight another day.  The opponent is placed into a loser
**              pile to rest in infamy.
** Parameters: none
** Pre-Conditions: there must be a total of at least 3 fighting
**                 Creatures in side1 and side2
** Post-Conditions: if Player 1's team wins, returns true; otherwise
**                  returns false
*********************************************************************/

bool CombatRunner::run_tournament()
{
    // current fighters
    Creature *p1;
    Creature *p2;

    // run tournament until one team is entirely KOed
    while (true)
    {
        // if no more Creatures on team 1
        if (!(p1 = side1->remove()))
        {
            // clear out all the remaining Creatures on team 2
            // and sum up their points
            while ((p2 = side2->remove()))
            {
                losers2->add(p2);
                losers->add(p2);
                side2pts += (p2->get_points());

                // keep track of order Creatures were added to losers Stack
                defeat_sides.push_back(2);
            }

            // team 1 was defeated!
            return P2_WON;
        }

        // otherwise if no more Creatures on team 2
        else if (!(p2 = side2->remove()))
        {
            // clear out all the remaining Creatures on team 1
            // and sum up their points
            while ((p1 = side1->remove()))
            {
                losers1->add(p1);
                losers->add(p1);
                side1pts += (p1->get_points());

                // keep track of order Creatures were added to losers Stack
                defeat_sides.push_back(1);
            }

            // team 2 was defeated!
            return P1_WON;
        }

        else    // still fighters left from each side
        {
            // play one match between current fighters
            bool result = play_match(p1, p2);

            if (result == P1_WON)
            {
                // restore some health to the victor
                p1->revive();

                // put winner at end of queue
                side1->add(p1);

                losers2->add(p2);
                losers->add(p2);
                side2pts += (p2->get_points());

                // keep track of order Creatures were added to losers Stack
                defeat_sides.push_back(2);
            }
            else // P2_WON
            {
                // restore some health to the victor
                p2->revive();

                // put winner at end of queue
                side2->add(p2);

                losers1->add(p1);
                losers->add(p1);
                side1pts += (p1->get_points());

                // keep track of order Creatures were added to losers Stack
                defeat_sides.push_back(1);
            }
        }
    }
}


/*********************************************************************
** Function: CombatRunner::play_match()
** Description: Plays a single combat battle between p1 and p2.  If
**              P1 wins, returns true.  Otherwise, returns false.
** Parameters: p1   Creature from team 1
**             p2   Creature from the black lagoon... no, just team 2
** Pre-Conditions: p1 and p2 are not null
** Post-Conditions: a bool indicating the winner is returned,
**                  cur_sim is incremented
*********************************************************************/

bool CombatRunner::play_match(Creature* p1, Creature* p2)
{
    ++cur_sim;

    bool p1_goblin = false;
    bool p2_goblin = false;

    if (p1->get_name() == "Goblin")
        p1_goblin = true;
    if (p2->get_name() == "Goblin")
        p2_goblin = true;

    bool p1_achilles_cut = false;
    bool p2_achilles_cut = false;

    // each iteration is a turn
    while (true)
    {
        // determine whether p1 has cut opponent's Achilles tendon
        if (p1_goblin)
           p1_achilles_cut = (dynamic_cast<Goblin*>(p1))->get_achilles();

        // determine whether p2 has cut opponent's Achilles tendon
        if (p2_goblin)
           p2_achilles_cut = (dynamic_cast<Goblin*>(p2))->get_achilles(); 

        // player 1 attacks player 2
        int p1_attack = p1->attack();
        int p2_defense = p2->defend();

        // apply damage

        // if opponent is a Goblin, cancel out the Achilles tendon cut
        if (p1_goblin && p2_achilles_cut)
            p2->take_damage(p1_attack * 2, p2_defense);
        else
            p2->take_damage(p1_attack, p2_defense);

        if (p2->is_dead())
            return P1_WON;

        // player 2 attacks player 1
        int p2_attack = p2->attack();
        int p1_defense = p1->defend();

        // apply damage

        // if opponent is a Goblin, cancel out the Achilles tendon cut
        if (p2_goblin && p1_achilles_cut)
            p1->take_damage(p2_attack * 2, p1_defense);
        else
            p1->take_damage(p2_attack, p1_defense);
        
        if (p1->is_dead())
            return P2_WON;
    }
}


/*********************************************************************
** Function: CombatRunner::print_outcome()
** Description: Displays the results of the tournament to the console.
**              Relevant information presented includes which team
**              still had Creatures standing, the total KO points each
**              team accumulated, and the last 3 Creatures standing.
**              Technically the last three Creatures standing may
**              never have been KOed.
** Parameters: none
** Pre-Conditions: all Creatures must have been thrown into the loser
**                 pile, even those never KOed
** Post-Conditions: the tournament summary appears on the screen with
**                  reasonable statistics
*********************************************************************/

void CombatRunner::print_outcome()
{
    bool winner = run_tournament();
    if (winner == P1_WON)
        std::cout << "\nPlayer 1's team destroyed the opposition!\n\n";
    else
        std::cout << "\nPlayer 2's team destroyed the opposition!\n\n";

    // display team KO point total
    std::cout << "Total Points\n" <<
                 "Player 1: " << side1pts << '\n' <<
                 "Player 2: " << side2pts << "\n\n";

    // print top three finishers
    print_top_three();
}


/*********************************************************************
** Function: CombatRunner::print_top_three()
** Description: Responsible for determining the last three Creatures
**              standing at the end of the tournament.  Technically
**              the second and third place finishers may have been
**              KOed.  It prints their names and sides to the screen.
** Parameters: none
** Pre-Conditions: all Creatures must have been thrown into the loser
**                 pile, even those never KOed
** Post-Conditions: the three Creatures last added to the loser pile
**                  are printed
*********************************************************************/

void CombatRunner::print_top_three()
{
    std::cout << "The Best Finishers\n";
    int end_vec = defeat_sides.size();

    // get the top three Creatures from the loser pile
    for (int i = 1; i <= 3; ++i)
    {
        // figure out which team each was on
        int plyr_num = defeat_sides.at(end_vec - i);

        std::cout << i << ") Player " << plyr_num << "\'s " <<
                     (losers->remove())->get_name() << '\n';
    }
}
