/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/29/15
 ** Description: This program runs the Conway's Game of Life at least
 **              one time, animating the world's evolution in the
 **              console.  The user has the choice of determining which
 **              initial cells will be alive (by choosing a predefined
 **              pattern and offset), how many generations to display,
 **              and how long each generation is displayed on the
 **              screen.
 ** Input: A starting pattern, an x and y offset for the upper left
 **        corner of its bounding box, number of generations, duration
 **        of a generation, and whether to play again
 ** Output: The Game of Life, in a 40x20 grid with live cells marked
 **         'X' and dead cells marked '.', along with various
 **         instructions and prompts
 *********************************************************************/

#include "Game.hpp"

#include <iostream>     // for instructions and user input
#include <unistd.h>     // for usleep()


int main()
{
    using namespace std;

    // visible world size
    const int WIDTH = 40;
    const int HEIGHT = 20;

    // does user want to play again after the current game ends?
    bool playAgain = false;

    do
    {
        // play a round of Game of Life

        cout << "Welcome to the Game of Life.\nThe world is a 40x20 " <<
                "grid.  You may select one of the\nfollowing three " <<
                "starting patterns of living cells:\n (o)scillator, " <<
                "(g)lider, or glider g(u)n." << endl;

        // get initial pattern of live cells in world
        char pattern;
        do
        {
            cout << "Please choose a starting pattern:\n" <<
                    " (o)scillator\n (g)lider\n glider g(u)n" << endl;
            cin >> pattern;
        }
        while (pattern != 'o' && pattern != 'g' && pattern != 'u');

        cout << "Choose a location for the upper left corner of the\n" <<
                "pattern on the grid." << endl;

        // restrict allowable coords depending on pattern
        int xMin, xMax, yMin, yMax;
        xMin = yMin = 0;
        if (pattern == 'o')
        {
            // 3x3
            xMax = WIDTH - 3;
            yMax = HEIGHT - 3;
        }
        else if (pattern == 'g')
        {
            // 3x4
            xMax = WIDTH - 3;
            yMax = HEIGHT - 4;
        }
        else
        {
            //36x9
            xMax = WIDTH - 36;
            yMax = HEIGHT - 9;
        }

        // get the location of upper left corner from user
        int x, y;
        do
        {
            cout << xMin << " <= x <= " << xMax << endl;
            cout << "x = ";
            cin >> x;

            cout << yMin << " <= y <= " << yMax << endl;
            cout << "y = ";
            cin >> y;
        }
        while (x < xMin || x > xMax || y < yMin || y > yMax);

        cout << "How many generations should there be (10-1000)?" << endl;

        // get number of generations in this game
        int numGenerations;
        cin >> numGenerations;

        while(numGenerations < 10 || numGenerations > 1000)
        {
            cout << "Please choose a number between 10 and 1000 " <<
                    "for the number of generations." << endl;
            cin >> numGenerations;
        }
        
        cout << "How long should each generation last, in ms (10-1000)?" <<
                endl;

        // get wait time between display of generations
        int sleepTime;
        cin >> sleepTime;

        while(sleepTime < 10 || sleepTime > 1000)
        {
            cout << "Please choose a number between 10 and 1000 " <<
                    "for the number of ms per generation." << endl;
            cin >> sleepTime;
        }

        // convert ms to microseconds for usleep()
        sleepTime *= 1000;

        // pause for 2 seconds
        cout << "Thank you, game about to begin..." << endl;
        usleep(2000000);

        cout << "Playing one Game of Life." << endl;

        // load up game settings
        Game ofLife(WIDTH, HEIGHT, pattern, x, y, numGenerations,
                sleepTime);

        // run the simulation
        ofLife.play();

        // ask user if (s)he wants to play again
        char sel;
        do
        {
            cout << "Do you wish to play again? (y/n)" << endl;
            cin >> sel;
        }
        while(sel != 'y' && sel != 'Y' && sel != 'n' && sel != 'N');
        
        if (sel == 'y' || sel == 'Y')
            playAgain = true;

        else
            playAgain = false;

    }
    while (playAgain);
}
