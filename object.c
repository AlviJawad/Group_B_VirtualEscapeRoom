#include <stdio.h>
#include "object.h"

/************************* Object Descriptions *************************/
OBJECT_t objs[] = {
	/***** stages *****/
	{"a bright white room", "stage1", location, NULL, NULL},	// NULL: stages aren't visible and part of any location
	{"a dark yellow room", "stage2", location, NULL, NULL},
	{"a crimson red room", "stage3", location, NULL, NULL},
	/***** The player *****/
	{"yourself", "yourself", actor, NULL, stage1},				// player starts in stage 1
	
	/******************** stage 1 objects ********************/
	/** Table with a letter **/
	{"a wooden table", "table", visible_object, 
	"The table seems strudy at first glance\n"
	"Upon further examination, you find that one of the front legs is rather unstable\n"
	"There is also a letter on the table\n"
	"You might be able to read the contents\n", stage1},
	/** A letter **/
	{"a dusty letter", "letter", hidden_object, NULL , stage1},
	/** A clock **/
	{"a broken clock", "clock", visible_object, NULL , stage1},
	{"a silver key", "key1", usable_object, NULL, stage1},
	{"a silver door", "door1", visible_object, NULL, stage1},
	
	/******************** stage 2 objects ********************/
	{"a gold key", "key2", usable_object, NULL, stage2},
	{"a gold door", "door2", visible_object, NULL, stage2},
	
	/******************** stage 3 objects ********************/
	{"a ruby key", "key3", usable_object, NULL, stage3},
	{"a ruby door", "door3", visible_object, NULL, stage3}
};