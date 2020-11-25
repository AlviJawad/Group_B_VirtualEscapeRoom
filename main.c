#include <stdio.h>
#include <stdbool.h>

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
 * continuously calls the get_input() function to keep the game going
 */
int main (){
	printf("Welcome to our VIRTUAL ESCAPE ROOM!\n");
	// The current stage, initialized to the first stage
	int stage = 1;
	
	while (get_input());
	printf("\nByeBye!\n");
	
	return 0;
}