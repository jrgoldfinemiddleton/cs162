/*********************************************************************
 ** Program Filename: Game.hpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/29/15
 ** Description: The specification file for the Game class.  A Game is
 **              an object capable of playing a single instance of
 **              Conway's Game of Life.  This implementation places
 **              either an oscillator, a glider, or a glider gun on
 **              the grid to begin with.  The output of each change in
 **              generation (a tick) is displayed via the console.
 **              A live cell appears as an 'X' and a dead cell appears
 **              as a '.' (period).
 *********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>   // for patternCells


/*********************************************************************
 ** Structure: Cell
 ** Description: Stores an ordered (x, y) pair in 2D coordinate space.
 *********************************************************************/

struct Cell
{
    // coordinates on grid
    int x;
    int y;

    // constructor that takes the ordered pair
    Cell(int x, int y);
};


class Game
{
    private:
        // total width of game grid, including two side buffers
        int width;

        // total height of game grid, including top and bottom buffers
        int height;

        // number of extra rows/columns off each edge of the visible grid
        int buffer;

        // number of ticks in complete game
        int generations;

        // duration of a single tick
        int pauseLength;

        // stores 2D world of cells either alive or dead
        // updated each tick according to game rules
        int **grid;

        // stores the user's chosen initial pattern of live cells in the
        // form of coordinates, adjusted with the user's chosen upper left
        // corner
        std::vector<Cell> patternCells;

    public:
        // constructor that sets world to initial state (tick 0) with shape
        // included
        Game(int width, int height, char pattern, int xOffset, int yOffset,
             int generations, int pauseLength);

        // destructor which kills the grid
        ~Game();

        // fills entire grid with dead cells - run once
        void clearGrid();
        
        // determines a cell's fate based on the rules and updates its
        // position on nextGrid
        void determineFate(Cell c, int **nextGrid);

        // sets relevant cells of grid to be alive based on patternCells
        void initializePattern();

        // runs the full game and prints each generation to screen in a
        // pretty way
        void play();

        // testing method which prints current grid, with buffers, to screen
        void printWholeGrid();
        
        // method which prints current grid, without buffers, to screen
        void printWindow();

        // store the initial live cells in patternCells
        // offset relates to the upper left corner of shape's box
        void setPatternVector(char pattern, int xOffset, int yOffset);

        // execute a single tick of gameplay, updating grid after rules
        // have been applied to each cell
        void tick();
};

#endif
