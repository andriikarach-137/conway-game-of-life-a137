// This file contains implementations of the utility functions used by main module 

#include <stdlib.h> 

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

// ***************************************************************************
// Implementations of the public functions of main module

bool read_coordinate(int *x, int *y, char *str) {
    if (consume_char(&str) != '(') {
        return false; 
    }

    int x_val = strtol(str, &str, 10);
    if (consume_char(&str) != ',') {
        return false; 
    }
    *x = x_val; 

    int y_val = strtol(str, &str, 10); 
    if (consume_char(&str) != ')') {
        return false; 
    }
    *y = y_val; 

    return true; 
}

// ***************************************************************************