
/*
 *
 * character.c
 *
 * Holds all the logic that deals with characters.
 * 
 *
 * Colin J. Mills & Greg Ward
 * 
 * 2015/08/12
 *
 */

#include "bork.h"
#include <stdio.h>
#include <string.h>

/*
 *
 * initCharacter(struct character*)
 *
 * Initalizes a character struct to a "clean slate". NULL all the way around.
 *
 * struct character* character: The struct pointer to the character struct.
 *
 * void
 */

void 
initCharacter(struct character* character)
{
    character->name             = NULL;
    character->race             = NULL;
    character->health           = 0;
    character->skillSet.attack  = 0;
    character->skillSet.defence = 0;
    character->skillSet.courage = 0;
}


/*
 * Dwarf 
 */





