// This file contains implementations of the utility functions used by main module 

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#include "main.h"

// ***************************************************************************
// Implementations of the private functions of main module 

char consume_char(char **str_ptr) {

    // Get the current character pointed to
    char c = **str_ptr; 

    // Only advance if pointer doesn't point to the end of the string
    if (c != '\0') {
        (*str_ptr)++;
    }

    return c; 
}

int alive_neighbours(Pair pair) {
    int alive_count = 0; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int x = MOD(pair.x - 1 + j, dim); 
            int y = MOD(pair.y - 1 + i, dim); 

            if (x == pair.x && y == pair.y) {
                continue;
            }

            int index = y * dim + x;

            if (game_state.curr_map[index] == ALIVE) {
                alive_count++; 
            }
        }
    }

    return alive_count; 
}

// ***************************************************************************
// Implementations of the public functions of main module

bool read_coordinate(int *x, int *y, char *str) {
    if (consume_char(&str) != '(') {
        return false; 
    }

    int x_val = strtol(str, &str, 10);
    if (x_val < 0 || x_val > dim - 1) {
        return false; 
    }

    if (consume_char(&str) != ',') {
        return false; 
    }
    *x = x_val; 

    int y_val = strtol(str, &str, 10); 
    if (y_val < 0 || y_val > dim - 1) {
        return false; 
    }

    if (consume_char(&str) != ')') {
        return false; 
    }
    *y = y_val; 

    return true; 
}

void update_state() {
    game_state.generation++; 
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            Pair new = {.x = j, .y = i}; 
            int n = alive_neighbours(new); 
            int index = i * dim + j; 
            if (n < 2) {
                game_state.next_map[index] = DEAD; 
            } else if ((n == 2 || n == 3) && game_state.curr_map[index] == ALIVE) {
                game_state.next_map[index] = ALIVE; 
            } else if (n > 3 && game_state.curr_map[index] == ALIVE) {
                game_state.next_map[index] = DEAD; 
            } else if (n == 3 && game_state.curr_map[index] == DEAD) {
                game_state.next_map[index] = ALIVE; 
            } else {
                game_state.next_map[index] = DEAD; 
            }
        }
    }
    TileState *temp = game_state.curr_map; 
    game_state.curr_map = game_state.next_map;
    game_state.next_map = temp; 
}

void print_state() {
    printf("<===============================================================================>\n\n"); 
    printf("Generation: %i\n\n", game_state.generation);
    printf("<------------------------------------------------------------------------------->\n\n"); 
    
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("[%s]", game_state.curr_map[i * dim + j] == DEAD ? " " : "@"); 
        }
        printf("\n"); 
    }
}

void delay() {
    time_t curr = clock(); 
    while (1) {
        if (clock() - curr > 500000) {
            break; 
        }
    }
}

// ***************************************************************************