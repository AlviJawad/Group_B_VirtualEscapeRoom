/**
 * This header file contains the core execution functions used by parse_and_execute()
 * void execute_look(): executed when the player is trying to look around the stage
 * void execute_examine(): executed when the player is trying to examine an object to get more detail
 * void execute_move(): executed when the player is trying to move to a new stage
 * void execute_help(): executed when the player needs directions for common commands
 * void execute_get(): executed when the player tries to put a usable item into their bag
 * void execute_check(): executed when the player tries to check what they currently have in their bag
 */

extern void execute_look(const char *arg);

extern void execute_examine(const char *arg);

extern void execute_move(const char *arg);

extern void execute_help();

extern void execute_check();