#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <stdio.h>

/***** OBJECT Types and States *****/
enum type{
	location = 0,
	item = 1,
	actor = 3
};


//enum state{
//	closed = 0, open = 1,
//	not_obtained = 2, obtained = 3,
//	normal = 4
//};


/***** OBJECT Structure *****/
typedef struct object{
	const char *description;
	const char *tag;
	enum type;
	struct object *location;
} OBJECT_t;

OBJECT_t objs[];


/***** Object Descriptions *****/
OBJECT_t objs[] = {
	/***** stage1 *****/
	{"a bright white room", "stage1", location, NULL},		// stages aren't part of any locations
	{"an wooden table", "table", item, stage1},
	{"a dusty letter", "letter", item, stage1},
	{"a broken clock", "clock", item, stage1},
	{"yourself", "yourself", actor, stage1},

	/***** stage2 *****/
	{"a dark yellow room", "stage2", location, NULL},
	
	/***** stage3 *****/
	{"a crimson red room", "stage3", location, NULL}
};


#endif