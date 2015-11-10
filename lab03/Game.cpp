/*********************************************************************
 ** Program Filename: Game.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/13/15
 ** Description: This is the Game class implementation file.
 ** Input: std::cin
 ** Output: std::cout
 *********************************************************************/


#include "Game.h"
#include "Die.h"
#include "LoadedDie.h"


/*********************************************************************
 ** Function: Game::Game()
 ** Description: The constructor for a new Game.
 ** Parameters: rounds_to_play  number of rounds
 **             num_dice_sides  number of sides per Die
 **             p1_loaded       true if Player 1 uses a LoadedDie
 **             p2_loaded       true if Player 2 uses a LoadedDie
 ** Pre-Conditions: rounds_to_play > 0, num_dice_sides > 0
 ** Post-Conditions: A new game is created with rounds_to_play rounds,
 **                  each player has a Die object (loaded or regular),
 **                  current round is 1.
 *********************************************************************/

Game::Game(int rounds_to_play, int num_dice_sides,
        bool p1_loaded, bool p2_loaded) :
    max_rounds(rounds_to_play)
{
    round = 1;
    score_p1 = score_p2 = 0;

    p1 = p1_loaded ? new LoadedDie(num_dice_sides) : 
                     new Die(num_dice_sides);
    p2 = p2_loaded ? new LoadedDie(num_dice_sides) :
                     new Die(num_dice_sides);

}


/*********************************************************************
 ** Function: Game::~Game()
 ** Description: Destructs the game, freeing the memory used by the Die
 **              pointers.
 ** Parameters: none
 ** Pre-Conditions: p1 and p2 have not been deleted yet.
 ** Post-Conditions: p1 and p2's memory has been deallocated.
 *********************************************************************/

Game::~Game()
{
    delete p1;
    delete p2;
}


/*********************************************************************
 ** Function: Game::play_round()
 ** Description: Plays a single round of the Game, printing out the
 **              value of each player's roll and the new scores of the
 **              two players.
 ** Parameters: none
 ** Pre-Conditions: round <= max_rounds, srand() has been run.
 ** Post-Conditions: round is incremented, each player's score is
 **                  printed.
 *********************************************************************/

void Game::play_round()
{
    std::cout << "Round " << round << ":\n\tPlayer 1: ";

    int roll_p1 = p1->die_roll();
    std::cout << "\tPlayer 2: ";
    int roll_p2 = p2->die_roll();

    std::cout << "\n";

    if (roll_p1 > roll_p2)
        ++score_p1;
    else if (roll_p1 < roll_p2)
        ++score_p2;

    std::cout << "Player 1 score: " << score_p1 << '\t' <<
                 "Player 2 score: " << score_p2 << '\n';

    ++round;
}


/*********************************************************************
 ** Function: Game::play_game()
 ** Description: Plays an entire game with max_round rounds, printing
 **              the resulting scores of each player every round, and
 **              noting the winner after all rounds are done.
 ** Parameters: none
 ** Pre-Conditions: srand() has been run.
 ** Post-Conditions: The entire game is played and the user is
 **                  presented with the winner.
 *********************************************************************/

void Game::play_game()
{
    std::cout << "Starting new game.\n\n";

    while (round <= max_rounds)
        play_round();

    print_game_result();
}


/*********************************************************************
 ** Function: Game::print_game_result()
 ** Description: Prints the final result of this Game.
 ** Parameters: none
 ** Pre-Conditions: round = max_rounds + 1
 ** Post-Conditions: The result is printed whether win or draw.
 *********************************************************************/

void Game::print_game_result()
{
    std::cout << "Result: ";
    if (score_p1 > score_p2)
        std::cout << "Player 1 wins!\n";
    else if (score_p1 < score_p2)
        std::cout << "Player 2 wins!\n";
    else
        std::cout << "It's a draw!\n";
}

