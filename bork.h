
/*
 * 
 * bork.h
 *
 * Holds all the prototypes and constants for bork.
 *
 * Colin J. Mills and Greg Ward
 *
 * 2015/08/05
 *
 */
#ifndef __BORK_H__
#define __BORK_H__
#include <stdio.h>


/*
 * Constants
 */

/* Global Constants */
#define            true   0  // Truthy values are 0
#define            false -1  // Falsy values are  -1
#define BLOCK_SIZE 81        // The block size is a kilobyte.
#define BORK_DIR ".bork"     // The directory that bork uses for configuration.
#define BORK_FILE "log.bork" // The filename of the log file.


/* character.c Constants */


/* 
 * Types
 */

/* character.c */
struct skill
{
    int attack;  // The amount of health  a character has.
    int defence; // The amount of defence a character has.
    int courage; // The amount of courage a character has.
};


struct character
{
    char* race; // The characters race.
    char* name; // The characters name.
    int health; // The characters health.
    struct skill skillSet; // The skillset of a character
};






/*
 * Prototypes
 */

/* bork.c */
void initLog(FILE**); 

/* character.c */
void initCharacter(struct character*); 


/* util.c */
void* allocateBlock     (size_t); 
void  buildBorkDirPath  (char**);
void  makeBorkDirectory (char*);

#endif











