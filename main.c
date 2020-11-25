#include <stdio.h>
#include <stdbool.h>
#include "parsenexec.h"

/** 
 * Maximum size of input buffer is 100
 * Initialize the array to "look around" so it can be the default command 
 * that is executed whenever we enter a new stage.
 */
static char input[100] = "look around";
 
/**
 * A static function to get user inputs from the stdin stream
 * @return whether an input was captured properly or not
 */
static bool get_input(void){
	// Prompt the user to enter a command using "> ".
	printf("\nWhat would you like to do?");
	printf("\n> ");
	bool input_captured = fgets(input, sizeof(input), stdin) != NULL;
	return input_captured;
}

/**
 * continuously calls the two major functions to keep the game going
 */
int main (){
	printf("Welcome to our VIRTUAL ESCAPE ROOM!\n");
	// The current stage, initialized to the first stage
	int stage = 1;
	
	while (parse_and_execute(input) && get_input());
	printf("\nByeBye!\n");
	
	return 0;
}