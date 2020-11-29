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
		} else if (obj->type != item){
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

//void execute_move(const char *arg){
//	OBJECT *obj = getVisible("where you want to go", arg);
//	if (obj == NULL){
//		// Empty block
//	}
//	else if (	obj->location == NULL &&			// You can only go to a valid location
//			obj != player->location){			// player isn't trying to go where he already is
//		printf("Moving...\n");
//		printf("... ... ...\n");
//		player->location = obj;					// player is in a new location now, update his location
//		execute_look("around");
//	}
//	else {
//		printf("You're really don't want to go %s right now, it's dangerous!\n", arg);
//	}
//}