/*********************************************************************
** Program Filename: CombatRunner.hpp
** Author: Jason Goldfine-Middleton
** Date: 11/09/15
** Description: Contains the CombatRunner class definition and
**              member declarations.  The CombatRunner class provides
**              a means to run a tournament consisting of matchups
**              between two teams of Creatures lined up in Queues.  It
**              has a means for determining a winning side and other
**              useful information after the tournament ends.
*********************************************************************/

#ifndef COMBAT_RUNNER_HPP
#define COMBAT_RUNNER_HPP

#include "Creature.hpp"
#include "Goblin.hpp"

#include "Queue.hpp"
#include "Stack.hpp"
#include <vector>

class CombatRunner
{
private:
    static const bool P1_WON = true;
    static const bool P2_WON = false;

    // players
    Queue *side1;
    Queue *side2;
    
    // loser pile for each side
    Stack *losers1;
    Stack *losers2;

    // total KO points earned by Creatures from each side
    int side1pts;
    int side2pts;

    // general loser pile
    Stack *losers;

    // each defeat is reported here as a 1 or 2
    // to be used when looking back through the losers stack
    std::vector<int> defeat_sides;

    // current simulation number
    int cur_sim;

public:
    CombatRunner(Queue* s1, Queue* s2);
    ~CombatRunner();
    bool run_tournament();
    bool play_match(Creature* p1, Creature* p2);
    void print_outcome();
    void print_top_three();
};

#endif
