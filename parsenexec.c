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
		}
		/* User enters "look <arg>" */
		else if (strcmp(command, "look") == 0){
			/* Show different information based on the current stage */
			execute_look(arg);	
		}
		/* User enters "examine <arg>" */
		else if (strcmp(command, "examine") == 0){
			/* Show detailed info about the object */
			execute_examine(arg);	
		}
		/* User enters "move <arg>" */
		else if (strcmp(command, "move") == 0){
//			execute_move(arg);
		}
		/* User enters "ask <arg>" */
		else if (strcmp(command, "ask") == 0){
			if (strcmp (arg, "hint") == 0){
				/* User asks for hint */
			}
			else if (strcmp (arg, "help") == 0){
				/* show a list of helpful common commands */
			}
			else {
				printf("I don't know how to answer that.\nThere are so many things to learn in this world!\n");
			}
		}
		else {
			/* Add an interesting messsage if the user tries to do something absurd */
			printf("You tried to %s!\n", command);
			printf("Turns out %sing %s is impossible right now!!\n", command, arg);
		}
	}
	return true;
}