/*************************************************************************************
 * myshell - student code for Project 1 of CSCE 489 
 * Niko Petrocelli
 *
 *************************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "shellfuncts.h"

void initialize(){
	//Initialize the shell	
	printf("\n\n\n****************************************************");
	printf("\n\n\nWelcome to Niko's Shell\n\n\n");
	printf("******************************************************\n\n\n");
	//wait a bit
	sleep(2);
	//clear the screen
	system("clear");
	printf("\nInput a command \n");

    return;

}

int getInput(char* string){
    
    char* temp;

    temp = readline("\n>>> ");
    if (strlen(temp) != 0){
        add_history(temp);
        strcpy(string, temp);
        return 0;
    }
    else{
        return 1;
    }


}

int main(int argv, const char *argc[]) {
	(void) argv; // Make compile warnings go away - be sure to delete this line if you use the param
	(void) argc; // Make compile warnings go away - be sure to delete this line if you use the param
    
    char input[100]; // max number of input support
    char *inputParsed[10]; //max number of commands

    int execute = 0;

    // print the splash screen
    initialize();
    r

    //loop the program
    while (1){

        //get the user input
        if(getInput(input))
            continue;







    }









}