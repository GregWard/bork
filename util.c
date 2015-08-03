/*
 *
 * util.c
 *
 * Holds all the utility functions for bork.
 *
 * 2015/07/30
 *
 *
 * Colin J. Mills
 *
 * BSD Licensed
 *
 */

#define NON_ZERO -1

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>


void* allocateBlock(size_t blockSize);

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

void* allocateBlock(size_t blockSize)
{
    /* Variable Definition */
    void* block = NULL;

    /* Logic */
    block = malloc(blockSize);

    if (NULL == block)
    {
        /* errx(3) is a function included from err.h. (man errx) */
        errx(NON_ZERO, "There was an error in allocating the block of memory");
    }

    return block ;
}


/* Testing Harness for allocate block at the moment 
 *
 * TODO: Remove later.
 */
int main(void)
{
    int i = 0;

    char* block = NULL;

    block = allocateBlock(1024);
    strcpy(block, "hello");
    printf("%s\n", block);



   return i;
}



