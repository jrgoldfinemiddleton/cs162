/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 10/13/15
 ** Description: This program plays a Game using the Die and LoadedDie
 **              classes.
 ** Input: std::cin (use LoadedDie or Die and how many rounds)
 ** Output: std::cout (the Game output including final winner)
 *********************************************************************/

#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
    // seed
    std::srand(std::time(0));

    std::cout << "Do you want Player 1 to use a loaded die? (y/n)\n";
    char c;
    std::cin >> c;
    bool p1_loaded = (c == 'y' || c == 'Y') ? true : false;
    std::cout << "Do you want Player 2 to use a loaded die? (y/n)\n";
    std::cin >> c;
    bool p2_loaded = (c == 'y' || c == 'Y') ? true : false;

    std::cout << "How many rounds should the game last? ";
    int rounds_to_play = -1;

    // wait for valid input, clear invalid
    do
    {
        std::cin >> rounds_to_play;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(5000, '\n');
        }
    } while (rounds_to_play < 1);

    // build and run a game
    Game g(rounds_to_play, 6, p1_loaded, p2_loaded);
    g.play_game();

    return 0;
}
