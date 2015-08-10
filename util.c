/*
 *
 * util.c
 *
 * Holds all the utility functions for bork.
 *
 * Colin J. Mills
 *
 * 2015/07/30
 *
 */
#include "bork.h"
#include <err.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <malloc.h>
#include <unistd.h>

/*
 *
 * allocateBlock(size_t)
 *
 * Allocates a block of a specific size with error checking.
 *
 * size_t blockSize: The size of the block we are mallocing
 *
 * Returns a void pointer. Make sure you cast the return type.
 */

void* 
allocateBlock(size_t blockSize)
{
    /* Variable Definition */
    void* block = NULL;

    /* Logic */
    block = malloc(blockSize);

    if (NULL == block)
    {
        /* errx(3) is a function included from err.h. (man errx) */
        errx(false, "There was an error in allocating the block of memory");
    }

    return block ;
}


void 
buildBorkDirPath(char** pathBuffer)
{
    /* Variable Definition */
    int usersUID = 0;                       // The current users UID
    struct password* pw             = {0}; // This is for incase the getenv(3) call fails.
    char* homeDirectory             = NULL; // THe home directory of the current user

    /* Logic */
    usersUID = getuid();

    /* Get the home directory */
    homeDirectory = allocateBlock(BLOCK_SIZE);

    /* 
     * This bit of code uses the getenv(3) call which is documented using "man getenv". It gets an environment variable
     * in our case the HOME variable. If that fails then we get the current user identification number and within the password
     * struct there is a home directory element.
     */
    homeDirectory = getenv("HOME");

    if (homeDirectory == NULL)
    {
        homeDirectory = getpwuid(getuid())->pw_dir;
    }

    strncat(*pathBuffer, homeDirectory, BLOCK_SIZE);

    sprintf(*pathBuffer, "%s/%s", homeDirectory, BORK_DIR);
}


void 
makeBorkDirectory(char* path)
{
    /* Variable Definition */
    const int MKDIR_FAIL            = -1;  // The error code for mkdir(3)
    const int DIRECTORY_PERMISSIONS = (S_IRWXU | S_IRWXG); // The directory permissions for the directory
    int mkdirRet = 0;                     // The return status from make directory.


    /* Logic */
    mkdirRet = mkdir(path, DIRECTORY_PERMISSIONS);

    if (mkdirRet == MKDIR_FAIL)
    {
        errx(MKDIR_FAIL, "There was an error in creating %s\n", path);
    }
}


