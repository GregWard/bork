
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
#define            true   0 // Truthy values are 0
#define            false -1 // Falsy values are  -1
#define BLOCK_SIZE 1024     // The block size is a kilobyte.

/* BORK Constants */
#define BORK_DIR ".bork" // The directory that bork uses for configuration.




/*
 * Prototypes
 */

/* bork.c */
void initLog(FILE**); /* Takes a file pointer and initalizes the log file handle. */
/* util.c */
void buildBorkDirPath(char**);
void* allocateBlock(size_t blockSize);
#endif











