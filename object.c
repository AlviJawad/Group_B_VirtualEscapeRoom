#include <stdio.h>
#include "object.h"

/***** Object Descriptions *****/
OBJECT_t objs[] = {
	/***** stages *****/
	{"a bright white room", "stage1", location, NULL, NULL},		// NULL: stages aren't part of any location
	{"a dark yellow room", "stage2", location, NULL, NULL},
	{"a crimson red room", "stage3", location, NULL, NULL},
	/***** The player *****/
	{"yourself", "yourself", actor, NULL, stage1},				// player starts in stage 1
	
	/***** stage 1 objects *****/
	{"a wooden table", "table", item, 
	"The table looks strudy at first\n"
	"But you see that one of the front legs is rather unstable\n"
	"There is also a letter on the table\n"
	"You might be able to read the contents\n", stage1},
	
	{"a dusty letter", "letter", item, NULL , stage1},
	{"a broken clock", "clock", item, NULL , stage1}
	
	/***** stage 2 objects *****/
	
	/***** stage 3 objects *****/
	
	
	
};