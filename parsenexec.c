#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "parsenexec.h"

bool parse_and_execute(char *input){
	/* Use the space delimiter to separate the command and argument */
	char *command = strtok(input, " \n");
	char *arg = strtok (NULL, " \n");
	
	/* Act based on the command */
	if (command != NULL){
		/* User enters "quit" */
		if (strcmp(command, "quit") == 0){
			return false;
		} else if (strcmp(command, "look") == 0){			// User enters "look <arg>"
			execute_look(arg);		// Show different information based on the current stage
		} else if (strcmp(command, "examine") == 0){		// User enters "examine <arg>"
			execute_examine(arg);		// Show detailed info about the object
		} else if (strcmp(command, "move") == 0){			// User enters "move <arg>"
//			execute_move(arg);
		} else if (strcmp(command, "ask") == 0){			// User enters "ask <arg>"
			if (strcmp (arg, "hint") == 0){				// User asks for hint
//				execute_hint();
			} else if (strcmp (arg, "help") == 0){
				/* show a list of helpful common commands */
				execute_help();
			} else {
				printf("I don't know how to answer that.\n"
				"There are so many things to learn in this world!\n");
			}
		} else if (strcmp(command, "help") == 0){
			execute_help();
		} else {
			/* Add an interesting messsage if the user tries to do something absurd */
			printf("You tried to %s.\n", command);
			printf("Turns out, %sing %s is impossible right now!!\n", command, arg);
		}
	}
	return true;
}