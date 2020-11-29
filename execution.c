#include <stdio.h>
#include <string.h>
#include "arghandling.h"
#include "object.h"
#include "helper.h"


void execute_look(const char *arg){
	if ((arg != NULL) && (strcmp(arg, "around") == 0)){
		printf("You are in %s.\n", player->location->description);
		list_objects_at_location(player->location);
	}
	else {
		/* Another witty message dictating what the user sees when he tries to look at something weird */
		printf("Even you're not sure what you want to see.\n");
	}
}

void execute_examine(const char *arg){
	if ((arg != NULL)){
		OBJECT_t *obj = get_object(arg);
		if (obj == NULL){
			/* When the examination target doesn't match any object */
			printf("Unfortunately, you couldn't find anything new\n");
		} else if (!(obj->type == visible_object || obj->type == hidden_object || obj->type == usable_object)){
			/* When the examination is not possible because of type restrictions */
			printf("Maybe you should try to examine something different\n");
		} else {
			/* Show detailed description of the object */
			printf("You carefully examine the %s\n", obj->tag);
			printf("%s\n", obj->detailed_description);
		}
	} else {
		/* When there's no examination target */
		printf("Maybe you should decide what you want to examine first\n");
	}
}

void execute_move(const char *arg){
	if (arg == NULL){
		printf("Maybe you should decide where to go first\n");	
		return;
	}
	OBJECT_t *obj = get_object(arg);
	if (obj == NULL){
		printf("%s does not exist in this world!!\n", arg);		// if no such place exists
	} else if (obj == player->location){			// player is trying to move to where he already is
		printf("You're already in %s\n", arg);	
	} else if (obj->type != location){			// trying to move to a non-location
		printf("%s is not a location\n", arg);
	} else if (obj->type == location){			// You can only go to a valid location
		printf("Moving...\n");
		printf("... ... ...\n");
		player->location = obj;					// player is in a new location now, update his location
		execute_look("around");					// look around to see the new place
	} else {
		printf("You're really don't want to move to %s right now, it's dangerous!\n", arg);
	}
}


void execute_help(){
	printf("This is a list of helpful common commands:\n");
	printf(
	"1. look around: 	look around to find interactive objects\n"
	"2. examine <object>: 	examine to get detailed information about an object\n"
	"3. move <stage>: 	move to a stage\n"
	"4. get <object>: 	put a usable object in your bag for later use\n"
	"5. use <object>: 	try to make use of an object in your bag\n"
	"6. open <door>: 	try to open a door\n"
	"7. hint: 		get a hint if you are stuck\n"
	"8. help: 		get a list of helpful common commands\n");
}