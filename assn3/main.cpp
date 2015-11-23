/*********************************************************************
** Program Filename: main.cpp
** Author: Jason Goldfine-Middleton
** Date: 10/28/15
** Description: This program serves as a testing driver for the
**              Creature and derived classes as well as the gameplay
**              functionality provided by the CombatRunner class.
*********************************************************************/

#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Goblin.hpp"
#include "Reptile.hpp"
#include "Shadow.hpp"
#include "CombatRunner.hpp"

#include <iostream>     // for std::cout

int main()
{
    // how many derived creature types there are
    const int NUM_CREATURES = 5;

    // each matchup will have this many simulations
    const int NUM_SIMULATIONS = 5000;

    // we need two arrays so that a type of Creature can battle another of the same type
    Creature *set1[NUM_CREATURES] = { new Goblin(), new Barbarian(), new Reptile(), new BlueMen(), new Shadow() };
    Creature *set2[NUM_CREATURES] = { new Goblin(), new Barbarian(), new Reptile(), new BlueMen(), new Shadow() };

    // pair up the types and duke it out, NUM_SIMULATIONS times
    for (int i = 0; i < NUM_CREATURES; ++i)
    {
        for (int j = 0; j < NUM_CREATURES; ++j)
        {
            Creature *p1 = set1[j];
            Creature *p2 = set2[i];
            CombatRunner cr(p1, p2, NUM_SIMULATIONS);

            std::cout << "Player 1: " << p1->get_name() << ", Player 2: " << p2->get_name() << '\n';

            // how many times did Player 1 win?
            int p1_wins = cr.get_result();

            double p1_win_ratio = static_cast<double>(p1_wins) / NUM_SIMULATIONS;

            std::cout << "Player 1 won " << (p1_win_ratio * 100) << "% of games.\n";
            std::cout << "Press a key to continue...\n";

            // pause after each matchup, waiting for a keypress
            std::cin.get();
        }
    }
    
    // free the heap memory
    for (int i = 0; i < NUM_CREATURES; ++i)
    {
        delete set1[i];
        set1[i] = 0;
        delete set2[i];
        set2[i] = 0;
    }

    // thatsallfolqs.jpg
    return 0;
}