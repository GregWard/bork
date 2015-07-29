#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct player_t {
    char* name;
    char* class;
    char* race;
} Player;

int main(int argc, char** argv)
{
   FILE* logFile = NULL; //log file for game cmd's
   int mkdirRet = 0;
   const char* borkDir = "~/.bork";

   // Logic //

   if ((mkdir(borkDir, 777) == -1))
   {
        fprintf(stderr, "There was an error in creating directory %s\n", borkDir);
        exit(0);
   }
   else
   {
        if (chdir(borkDir) == -1) 
        {
            fprintf(stderr, "There was an error in changing to %s\n", borkDir);
            exit(0);
        }
        else
        {
            logfile = fopen(".log.txt", w+);
            
            if ( logfile == NULL)
            {
                perror("Cannot open logfile. Will not write to logfile. Makes sense? Don't get your nuts in a grind, game will still play.");
            }
            
            getCharDetails();
            initGame();
        }
        
        
   }
   
   
	
   
   

   
   return errorLevel;	

}

