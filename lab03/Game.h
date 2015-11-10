/*********************************************************************
 ** Program Filename: Game.h
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/13/15
 ** Description: This is the Game class definition file.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/


#ifndef GAME_H
#define GAME_H

#include "Die.h"


class Game {
    private:
        // players
        Die *p1;
        Die *p2;
        
        // number of rounds to play
        int max_rounds;
        
        // current round number
        int round;

        // scores
        int score_p1;
        int score_p2;

        // play one round
        void play_round();

        // output winner
        void print_game_result();
    public:
        Game(int rounds_to_play, int num_dice_sides, bool p1_loaded,
                bool p2_loaded);
        ~Game();

        // play entire game
        void play_game();
};

#endif
