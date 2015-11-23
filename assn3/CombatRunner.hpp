/*********************************************************************
** Program Filename: CombatRunner.hpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: Contains the CombatRunner class definition and
**              member declarations.  The CombatRunner class provides
**              a means to run repeated simulations of a combat game
**              using two pointers to objects derived from the
**              abstract Creature class.
*********************************************************************/

#ifndef COMBAT_RUNNER_HPP
#define COMBAT_RUNNER_HPP

#include "Creature.hpp"
#include "Goblin.hpp"

class CombatRunner
{
private:
    static const bool P1_WON = true;
    static const bool P2_WON = false;

    // players
    Creature *p1;
    Creature *p2;

    // total number of simulations
    int total_sims;

    // current simulation number
    int cur_sim;

public:
    CombatRunner(Creature *p1, Creature *p2, int num_sims);
    bool run_simulation();
    int get_result();

};

#endif
