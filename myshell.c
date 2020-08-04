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
#include<readline/readline.h> 
#include<readline/history.h> 

#define MAXINPUT 100 // max number of input characters
#define MAXCMDS 5 // for this project we have 5 commands to support

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

int processInput(char* input, char** inputParsed){
    
    for (int i = 0; i< MAXCMDS; i++ ){
        inputParsed[i] = strsep(&input, " ");

        if(inputParsed[i] == NULL)
            break;
        if (strlen(inputParsed[i])==0){
            i--;
        }

    }

          printf("\n%s", inputParsed);

    
    return 0;



}

int main(int argv, const char *argc[]) {
	(void) argv; // Make compile warnings go away - be sure to delete this line if you use the param
	(void) argc; // Make compile warnings go away - be sure to delete this line if you use the param
    
    char input[MAXINPUT]; // max number of input support
    char *inputParsed[MAXCMDS]; //max number of commands

    int executeCMD = 0;

    // print the splash screen
    initialize();
    

    //loop the program
    while (1){

        //get the user input
        if(getInput(input))
            continue;

        executeCMD = processInput(input, inputParsed);
        //do i have a command to execute?

        printf("\n%d", executeCMD);
       // if (executeCMD ==1)

        

    }







    return 0;
}