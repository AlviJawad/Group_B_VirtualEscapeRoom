#include <stdio.h>
#include "object.h"

/***** Object Descriptions *****/
OBJECT_t objs[] = {
	/***** stages *****/
	{"a bright white room", "stage1", location, NULL},		// NULL: stages aren't part of any location
	{"a dark yellow room", "stage2", location, NULL},
	{"a crimson red room", "stage3", location, NULL},
	/***** The player *****/
	{"yourself", "yourself", actor, stage1},				// player starts in stage 1
	
	/***** stage 1 objects *****/
	{"an wooden table", "table", item, stage1},
	{"a dusty letter", "letter", item, stage1},
	{"a broken clock", "clock", item, stage1}
	
	/***** stage 2 objects *****/
	
	/***** stage 3 objects *****/
	
	
	
};