// This file contains the main function of the program. It acts as the file which uses all other modules and required functions. 
// Game is run as following: "./gol <dim> <pos1> <pos2> <pos3> ..." where <dim> is dimension of the game board, which must be a positive integer, between 16 and 256, and <pos> is coordinates of initial alive cells
// Coordinates provided as other arguments, where <posn> is (x,y)

#include <stdio.h> 
#include <stdlib.h> 

#include "main.h"

// ***************************************************************************

Pair tiles_alive_state[];  
Pair tiles_neear_alive_state[];

GameState game_state;

int main(int argc, char **argv) {
	
	// First, we check if there are exactly two command-line arguments
	if (argc - 1 < 2) {
		printf("Invalid usage.\nUse /gol <dim> <pos>\n"); 
		exit(EXIT_FAILURE); 
	}

	// Correct number of arguments, convert <dim> to integer
	char *end_ptr; 
	int dim = strtol(argv[1], &end_ptr, 10); 
	if (*end_ptr != '\0' || end_ptr == argv[1]) {
		printf("Invalid usage.\n<dim> must be an integer.\n");
		exit(EXIT_FAILURE); 
	}

	// <dim> is indeed a number, check if it is in the range
	if (dim < 16 || dim > 255) {
		printf("Invalid usage.\n<dim> is not in valid range.\n"); 
		exit(EXIT_FAILURE); 
	} 

	// <dim> has been processed, move on to processing <pos>
	Pair *initial_alive_cells = malloc(sizeof(Pair) * argc - 2);
	for (int i = 0; i < argc - 2; i++) {
		int x; 
		int y; 

		if (!read_coordinate(&x, &y, argv[i + 2])) {
			printf("Invalid usage.\nOne of the coordinates was not correctly entered.\n"); 
			exit(EXIT_FAILURE); 
		}

		Pair new = {.x = x, .y = y}; 
		initial_alive_cells[i] = new; 
	} 

	// Gamestate is defined globally, so everything is already initialised to 0 
}

// ***************************************************************************
// Implementations of the public functions of the main module

// ***************************************************************************