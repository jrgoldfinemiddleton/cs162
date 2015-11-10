/*********************************************************************
 ** Program Filename: Game.cpp
 ** Author: Jason Goldfine-Middleton
 ** Date: 09/29/15
 ** Description: The Game class implementation file.
 *********************************************************************/

#include "Game.hpp"

#include <iostream>     // for the print methods
#include <unistd.h>     // for usleep()
#include <vector>       // for the patterns

// cell states
#define ALIVE 1
#define DEAD 0


/*********************************************************************
 ** Function: Cell()
 ** Description: Constructs a Cell at a location.
 ** Parameters: x - abscissa (note: positive is right)
                y - ordinate (note: positive is down)
 ** Pre-Conditions: x and y are nonnegative
 ** Post-Conditions: the Cell is created with location (x, y)
 *********************************************************************/

Cell::Cell(int x, int y)
{
    this->x = x;
    this->y = y;
}


/*********************************************************************
 ** Function: Game()
 ** Description: Constructs a new Game of Life by constructing a grid,
 **              filling it with dead cells, then placing a pattern of
 **              live cells in it as an initial condition.
 ** Parameters: width - the horizontal size of the grid, incl. buffers
 **             height - the vertical size of the grid, incl. buffers
 **             pattern - a letter indicating which initial lifeform
 **                       the user wants on the grid
 **             xOffset - where the upper left corner of the bounding
 **             yOffset   box for the pattern will be (relative to
 **                       the visible grid's origin)
 **             generations - number of ticks until game ends
 **             pauseLength - duration of a tick (in microseconds)
 ** Pre-Conditions: width >= 40; height >= 20 pattern is 'o', 'g', or
 **                 'u'; xOffset and yOffset are restricted such that
 **                 entire pattern will be in visible window;
 **                 generations and pauseLength are positive
 ** Post-Conditions: all fields are initialized; grid points to a
 **                  dynamic array; grid contains an offset pattern
 *********************************************************************/

Game::Game(int width, int height, char pattern, int xOffset, int yOffset,
           int generations, int pauseLength)
{
    // hard-coded because the user shouldn't be concerned with a buffer
    buffer = 5;

    this->width = width + 2 * buffer;
    this->height = height + 2 * buffer;
    this->generations = generations;
    this->pauseLength = pauseLength;

    // build that grid
    grid = new int*[this->width];
    for (int col = 0; col < this->width; ++col)
    {
        grid[col] = new int[this->height];
    }

    // make sure everything is DEAD
    clearGrid();
    
    // on that bed of dead cells, throw a picture of life
    setPatternVector(pattern, xOffset, yOffset);
    initializePattern();

}


/*********************************************************************
 ** Function: ~Game()
 ** Description: The destructor for Game.
 ** Parameters: N/A
 ** Pre-Conditions: grid is not deallocated
 ** Post-Conditions: grid is deallocated
 *********************************************************************/

Game::~Game()
{
    // prevent that memory leak
    for (int col = 0; col < width; ++col)
    {
        delete [] grid[col];
    }
    delete [] grid;
}


/*********************************************************************
 ** Function: clearGrid()
 ** Description: Fills the entire grid with dead cells.
 ** Parameters: none
 ** Pre-Conditions: this method has not been run yet; width and height
 **                 are both positive; grid has dimensions
 **                 width x height
 ** Post-Conditions: every cell of the grid is DEAD
 *********************************************************************/

void Game::clearGrid()
{
    // col before row for no specific reason
    // doesn't matter anyway for this purpose
    // if we were printing out on the other hand...
    for (int col = 0; col < width; ++col)
    {
       for (int row = 0; row < height; ++row)
       {
           grid[col][row] = DEAD;
       }
    }
}


/*********************************************************************
 ** Function: determineFate()
 ** Description: For a cell, apply the rules of the Game of Life, and
 **              update the corresponding element of nextGrid, which
 **              is to contain the state of the world after this tick.
 ** Parameters: c - the Cell containing the location of interest
 **             nextGrid - grid used to overwrite the current world
 **                        after this tick ends
 ** Pre-Conditions: nextGrid has the same dimensions as grid; c is in
 **                 bounds; c is not located in an edge (border) row
 **                 or column
 ** Post-Conditions: the cell in nextGrid at c's coordinates is either
 **                  ALIVE or DEAD based on the rules of the Game of
 **                  applied to the corresponding cell in grid
 *********************************************************************/

void Game::determineFate(Cell c, int **nextGrid)
{
    int x = c.x;
    int y = c.y;

    // add up the neighbors (ALIVE = 1, DEAD = 0)
    // in a way this isn't the best design because we could change
    // what ALIVE and DEAD are #defined as but why would we do that?
    int totalLiveNeighbors = grid[x - 1][y - 1] + grid[x - 1][y] +
                             grid[x - 1][y + 1] + grid[x][y - 1] +
                             grid[x][y + 1] + grid[x + 1][y - 1] +
                             grid[x + 1][y] + grid[x + 1][y + 1];

    // a cell without 2 or 3 ALIVE neighbors can't live anymore
    if (totalLiveNeighbors < 2 || totalLiveNeighbors > 3)
    {
        nextGrid[x][y] = DEAD;
    }
    
    // a cell with 2 ALIVE neighbors doesn't change
    else if (totalLiveNeighbors == 2)
    {
        nextGrid[x][y] = grid[x][y];
    }

    // a cell with 3 ALIVE neighbors is ALIVE next generation
    else
    {
        nextGrid[x][y] = ALIVE;
    }
}


/*********************************************************************
 ** Function: initializePattern()
 ** Description: Sets relevant cells in grid to be ALIVE, based on the
 **              Cells found in patternCells.
 ** Parameters: none
 ** Pre-Conditions: patternCells contains only Cells with coordinates
 **                 in bounds of grid
 ** Post-Conditions: the location of each Cell in patternCells will be
 **                  marked ALIVE in grid
 *********************************************************************/

void Game::initializePattern()
{
    int len = patternCells.size();

    // for each Cell in the pattern, we want to represent its location
    // as being ALIVE
    for (int cell = 0; cell < len; ++cell)
    {
        Cell cur = patternCells[cell];
        grid[cur.x][cur.y] = ALIVE;
    }
}


/*********************************************************************
 ** Function: play()
 ** Description: Runs the Game of Life through repeated 'ticks',
 **              based on the values of the fields generations and
 **              pauseLength.  Each tick the visible world is printed.
 **              As the console's display is cleared before each new
 **              tick, the display will appear animated.
 ** Parameters: none
 ** Pre-Conditions: generations and pauseLength are positive
 ** Post-Conditions: the Game of Life is played with "generations"
 **                  ticks and a "pauseLength" microsecond break
 **                  between generations; the visible world is printed
 **                  to the console each generation; the final
 **                  generation will be left on-screen
 *********************************************************************/

void Game::play()
{
    // make sure all text is cleared so all future generational grids
    // line up with the first one
    std::cout.flush();
    system("clear");

    for (int gen = 0; gen < generations; ++gen)
    {
        // print the visible window, hiding the buffers
        printWindow();

        // pause to look at the current generation
        usleep(pauseLength);

        // clear console for next generation
        std::cout.flush();
        system("clear");

        // calculate the next generation
        tick();
    }
}


/*********************************************************************
 ** Function: printWholeGrid()
 ** Description: Prints the entire grid, including buffers, to the
 **              console, marking an ALIVE cell with an 'X' and a DEAD
 **              cell with a '.' (period).  This method is used for
 **              testing purposes only.
 ** Parameters: none
 ** Pre-Conditions: grid's dimensions are width x height
 ** Post-Conditions: the entire grid is printed to the console
 *********************************************************************/

void Game::printWholeGrid()
{
    // remember back in the clearGrid() method how it didn't matter
    // if we nested rows inside columns?
    // can't do that here because we print out one line at a time
    for (int row = 0; row < height; ++row)
    {
        for (int col = 0; col < width; ++col)
        {
            // ALIVE cell gets 'X', DEAD cell gets '.'
            char c = grid[col][row] == ALIVE ? 'X' : '.';
            std::cout << c;
        }
        std::cout << '\n';
    }
}


/*********************************************************************
 ** Function: printWindow()
 ** Description: Prints the visible grid, excluding buffers, to the
 **              console, marking an ALIVE cell with an 'X' and a DEAD
 **              cell with a '.' (period).
 ** Parameters: none
 ** Pre-Conditions: grid's dimensions are width x height; buffer >= 5
 ** Post-Conditions: the visible grid is printed to the console
 *********************************************************************/

void Game::printWindow()
{
    for (int row = buffer; row < height - buffer; ++row)
    {
        for (int col = buffer; col < width - buffer; ++col)
        {
            // ALIVE cell gets 'X', DEAD cell gets '.'
            char c = grid[col][row] == ALIVE ? 'X' : '.';
            std::cout << c;
        }
        std::cout << '\n';
    }
}


/*********************************************************************
 ** Function: setPatternVector()
 ** Description: Produces the hard-coded base coordinate vectors for
 **              the oscillator, glider, and Gosper glider gun, setting
 **              the patternCells field to a vector with adjusted Cells
 **              based on the pattern and offsets passed as parameters.
 ** Parameters: pattern - a character indicating which initial pattern
 **                       of life will be on the grid
 **             xOffset - where the upper left corner of the bounding
 **             yOffset   box for the pattern will be (relative to
 **                       the visible grid's origin)
 ** Pre-Conditions: pattern is either 'o', 'g', or 'u'
 ** Post-Conditions: patternCells is initialized with a set of ALIVE
 **                  Cells
 *********************************************************************/

void Game::setPatternVector(char pattern,
        int xOffset, int yOffset)
{
    // populate patternCells with base locations of ALIVE cells
    switch(pattern)
    {
        case 'o':   // oscillator
            patternCells = std::vector<Cell>
            { 
                Cell(1, 0), Cell(1, 1), Cell(1, 2)
            };
            break;
        case 'g':   // glider
            patternCells = std::vector<Cell>
            {
                Cell(0, 2), Cell(1, 0), Cell(1, 2), Cell(2, 1),
                Cell(2, 2)
            };
            break;
        case 'u':   // glider gun
            patternCells = std::vector<Cell>
            {
                Cell(0, 4), Cell(0, 5), Cell(1, 4), Cell(1, 5),
                Cell(10, 4), Cell(10, 5), Cell(10, 6), Cell(11, 3),
                Cell(11, 7), Cell(12, 2), Cell(12, 8), Cell(13, 2),
                Cell(13, 8), Cell(14, 5), Cell(15, 3), Cell(15, 7),
                Cell(16, 4), Cell(16, 5), Cell(16, 6), Cell(17, 5),
                Cell(20, 2), Cell(20, 3), Cell(20, 4), Cell(21, 2),
                Cell(21, 3), Cell(21, 4), Cell(22, 1), Cell(22, 5),
                Cell(24, 0), Cell(24, 1), Cell(24, 5), Cell(24, 6),
                Cell(34, 2), Cell(34, 3), Cell(35, 2), Cell(35, 3)
            };
            break;
        default:    // for testing
            // custom vector goes here
            break;
    }
    
    // shift all the base positions
    int len = patternCells.size();
    for (int cell = 0; cell < len; ++cell)
    {
        patternCells[cell].x += buffer + xOffset;
        patternCells[cell].y += buffer + yOffset;
    }
}


/*********************************************************************
 ** Function: tick()
 ** Description: Applies the rules of the game to the current grid,
 **              stores the results in a new grid, and after updating
 **              every cell, overwrites the original grid.  This method
 **              takes care of any "collision with edge/corner" issues.
 ** Parameters: none
 ** Pre-Conditions: width and height are positive; grid's dimensions
 **                 are width x height
 ** Post-Conditions: there is no memory leak; grid contains the next
 **                  generation
 *********************************************************************/

void Game::tick()
{
    // create temp array for next grid
    // make every cell DEAD immediately
    int **nextGrid = new int*[width];
    for (int col = 0; col < width; ++col)
    {
        nextGrid[col] = new int[height];
        for (int row = 0; row < height; ++row)
        {
            nextGrid[col][row] = DEAD;
        }
    }

    // for every cell not on an edge/border, determine its status for
    // next generation
    for (int x = 1; x < width - 1; ++x)
    {
        for (int y = 1; y < height - 1; ++y)
        { 
            determineFate(Cell(x, y), nextGrid);
        }
    }

    // now that we know what ever cell is going to do...

    // overwrite all cells other than the edge cells
    // this ensure the edge cells always stay DEAD and, thanks to
    // hidden buffers, gives the user the illusion of an infinite world
    for (int x = 1; x < width - 1; ++x)
    {
        for (int y = 1; y < height - 1; ++y)
        {
            grid[x][y] = nextGrid[x][y];
        }
    }

    // deallocate that memory
    for (int col = 0; col < width; ++col)
    {
        delete [] nextGrid[col];
    }
    delete [] nextGrid;
}
