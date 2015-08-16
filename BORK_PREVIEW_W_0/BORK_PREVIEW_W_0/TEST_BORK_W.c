/*
* FILE: TEST_BORK_W.c
* PURPOSE: Holds the code for a basic main/functions to run a short game to test game functionality. This does not utilize any logging utilities as it is
*          meant purely to present the simple UI for play for testing and review purposes.
*/

#define __WINDOWS__

#include "..\..\bork.h"


//FUNCTIONS FOR THIS FILE
char mainMenu();
int startBork();


int main(int argc, char** argv[])
{
	startBork();
	
	return 0;
}


/*
*
* Purpose: This function is the starting interface for bork. It creates the necessary player struct and initializes it. It then loads the menu and loops
*		   continuosly until a valid menu option is selected
*/

int startBork()
{
	struct character playerCharacter;

	int characterCreated = false;
	int gameStarted = false;
	char menuChoice = 0;

	//start logging utility to track all user 

	initCharacter(&playerCharacter);
	
	do
	{
		menuChoice = mainMenu();

		switch (menuChoice)
		{
		case 's':
			//start save file
			//load character creater
			//begin quest
			break;
		case 'l':
			//search log file
			//if save file found, load it
			//if not, alert user, go back to main, do not start new game automagically, could be a random misplaced file
			break;
		case 'q':
			return 0;
		default:
			printf("Pick a valid menu option");
			break;
		}

#ifdef __WINDOWS__
		system("cls");
#else
		system("clear");
#endif

	} while (gameStarted == false);
}


/*
*
* Purpose: This function will print the main menu and return the users selected choice.
*/
char mainMenu()
{
	char menuChoice = 0;

	printf("BORK TITLE AND GRAPHIC (OR ASCII LOGO) HERE\n\n");
	printf("Main Menu\n");
	printf("s: start new quest\n");
	printf("l: load a previous quest save\n");
	printf("q: leave the realm of bork\n");

	menuChoice = fgetc(stdin);

	return menuChoice;
}

void characterCreation(struct character* playerCharacter)
{

}