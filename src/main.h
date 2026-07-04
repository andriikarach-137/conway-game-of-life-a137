// This file contains main definitions and function declarations for the main module 

#include <stdbool.h> 

// <=========================================================================>
// Interface of main module

// ***************************************************************************
// Global Definitions
#define X_SIZE 64           // The width of the gameboard 
#define Y_SIZE 64           // The height of the gameboard 

// ***************************************************************************
// Structures and Types

/**
 * This structure defines a pair of coordinates in two-dimensional space
 * 
 * <int>                    x-coordinate valie
 * <int>                    y-coordinate value 
 */
typedef struct Pair {
    int x; 
    int y; 
} Pair; 

/**
 * This enum defines values, which describe whether the cell is dead or alive 
 */
typedef enum {DEAD, ALIVE} TileState; 

/**
 * <int>                    Generation count (first generation starts at 0)
 * <TileState[int][int]>    Current map of all tiles in the game, whose state can be either DEAD or ALIVE  
 * <TileState[int][int]>    Next state map of all tiles in the game, whose state can be either DEAD or ALIVE
 * <Cell *>                 Array of cells that are either alive or dead neighbours of alive cells               
 */
typedef struct GameState {
    int generation; 
    TileState curr_map[Y_SIZE][X_SIZE];
    TileState next_map[Y_SIZE][X_SIZE];
} GameState; 

// ***************************************************************************
// Global Variables

extern GameState game_state;        // This variable keeps track of the state of the game, generation and tiles state

// ***************************************************************************
// Public functions of the main module 

/**
 * This function reads a command-line argument as a coordinate, and returns a boolean value signifying
 * whether the argument is given correctly
 * 
 * <int *>                  Address of the integer which will store x-coordinate
 * <int *>                  Address of the integer which will store y-coordinate
 * <char *>                 String which represents a command-line argument, that is going to be processed
 * 
 * <bool>                   true if the command-line argument was processed correctly, false otherwise    
 */
extern bool read_coordinate(int *, int *, char *);

/**
 * This function updates the game according to the predefined rules (Conway's game of life in our case)
 */
extern void update_state(); 

/**
 * This function prints the game according to its current state 
 */
extern void print_state();

// <=========================================================================>
// Internals of main module

// ***************************************************************************
// Private functions of main module

/**
 * <char **>                Address of the string which will be advanced when character gets consumed 
 * 
 * <char>                   Consumed character 
 */
extern char consume_char(char **); 

/**
 * <Pair>                   Coordinates of the cell around which we are checking 
 * 
 * <int>                    Number of alive cells in the neighbourhood       
 */
extern int alive_neighbours(Pair); 

// ***************************************************************************