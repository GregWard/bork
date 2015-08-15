/*
 * bork.c
 *
 * Holds the main code for BORK a game so good you cant stop playing.
 *
 * Colin J. Mills and Greg Ward *
 * 2015/07/30
 */
#include "bork.h"
#include <err.h> // errx(3)
#include <pwd.h> // getpwuid()
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>  // mkdir()
#include <sys/types.h> // (struct password) 
#include <unistd.h>

/*
 * initLog(FILE**)
 *
 * Inits the log file at $HOME/.bork_dir for use in the rest of the program
 *
 * FILE** logFileHandle: The log file handle that we are building
 *
 * void
 */
void 
initLog(FILE** logFileHandle)
{
        /* Variable Definition */
        char* borkDirPath  = NULL; // The path for where we are making the directory and creating the configuration

        /* Logic */

        /* Allocate space for the bork path */
        borkDirPath  = (char*)allocateBlock(BLOCK_SIZE);

        /* Build the bork directory from the home directory and the bork path and the home directory */
        buildBorkDirPath(&borkDirPath);

        /* Make the actual bork directory */
        makeBorkDirectory(borkDirPath);

        chdir(borkDirPath);

        *logFileHandle = fopen(BORK_FILE, "w");
}


int 
main(int argc, char** argv)
{
   /* Variable Definition */
   FILE* logFile = NULL;    //log file for game cmd's
   struct character player; // The main player 

   /* Logic */
   logFile = (FILE*)allocateBlock(BLOCK_SIZE);
   initLog(&logFile);
   initCharacter(&player);

   printf("%d\n", player.health);
}

