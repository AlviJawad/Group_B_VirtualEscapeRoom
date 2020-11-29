#ifndef __OBJECT_H__
#define __OBJECT_H__



/***** OBJECT Types and States *****/
typedef enum type{
	location = 0,
	item = 1,
	actor = 2
} type_t;

//typedef enum state{
//	closed = 0, open = 1,
//	not_obtained = 2, obtained = 3,
//	normal = 4
//}state_t;


/***** OBJECT Structure *****/
typedef struct object{
	const char *description;
	const char *tag;
	type_t type;
	const char *detailed_description;
	struct object *location;
} OBJECT_t;
extern OBJECT_t objs[];


/***** Object References using symbolic names *****/
/* Stages */
#define stage1 	(objs + 0)
#define stage2 	(objs + 1)
#define stage3 	(objs + 2)
/* Actors */
#define player 	(objs + 3)
/* Objects */
#define table 	(objs + 4)
#define letter	(objs + 5)
#define clock 	(objs + 6)
/* End: always update this! */
#define end_of_objs (objs + 7)



#endif