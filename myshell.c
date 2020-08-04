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

int input(char*string){
	
	//scan for input until new line is uncountered, discard new line and put chars in string
	scanf("%[^\n]%*c", string);
	
	return 0;

}

void quit(){

	//say goodbye
	printf("\n\n\nGoodbye!\n\n\n");
	//wait for message to be read
	sleep(1);
	//Clean up our mess by clearing out the console
	system("clear");
	//Quit the program;
	exit(0);
	
}


int process(char*string){
	
	//Define all the commands to be used here
	const char* halt = "halt";
	const char* create = "create";
	const char* update = "update";
	const char* list = "list";
	const char* dir = "dir";
	
	//Get the user's input
	input(string);
	
	//Check if it matches the commands here	
	if(strcmp(string, halt) == 0)
		quit();
	else if(strcmp(string, dir) == 0){
		printf("\ntime to dir\n");
		return 1;}
	/*else if(strcmp(string, create) == 0){
		printf("\ntime to create\n");
		return;}
	else if(strcmp(string, update) == 0){
		printf("\ntime to update\n");
		return;}
	else if(strcmp(string, list) == 0){
		printf("\ntime to list\n");
		return;}*/
	//Does it contain these commands?
	else if(strstr(string, create)){
		printf("\ntime to create\n");
		//create a new array to store string without spaces (so we can ignore spaces)
		return 2;}
	else if(strstr(string, update)){
		printf("\ntime to update\n");
		return 3;}
	else if(strstr(string, list)	){
		printf("\ntime to list\n");
		return 4;}
	else{
		printf("\nNot a valid command please try again.\n");
		return 0;
	}


}

void removeBlank(char *c, const char *s){
	
	// I referenced stack overflow for creation of this algorithm. It basically loops through S and copies over everything that's not a space to c. This allows the new array to have
	//the same contents of string, but without spaces
	for(;*s;++s){
		if (*s != ' ') 
			*c++ = *s;
			
	}
	*c = *s;
	
	return;

}

char **sh_split_line(char *line){



	
}

int main(int argv, const char *argc[]) {
	(void) argv; // Make compile warnings go away - be sure to delete this line if you use the param
	(void) argc; // Make compile warnings go away - be sure to delete this line if you use the param
	
	
	//Initialize the shell	
	printf("\n\n\n****************************************************");
	printf("\n\n\nWelcome to Niko's Shell\n\n\n");
	printf("******************************************************\n\n\n");
	//wait a bit
	sleep(2);
	//clear the screen
	system("clear");
	printf("\nInput a command \n");
	
	//Declare the max size for the user's input string, 50 is sufficient for this shell
	char string[50];


	
	while (1){
		
					//print process
		pid_t pid1 = getpid();
		printf("\nThe current pid is:  %d", pid1);
		printf("\n");
		

		//While we aren't told to exit, keep processing the input
		int response;
		response = process(string);
		
		//debugging line
		//printf("\n%i", response);
		
		//we go into create mode
		if (response == 2){

			
			//print the child process
			pid_t cpid;
			
			if (fork()==0){
			
			
				pid_t pid2 = getpid();
				printf("\nThe current pid is: %d", pid2);
				printf("\n");
				char c[50];
				//copy string into c, but without spaces
				removeBlank(c, string);
				
				//Debugging line
				//printf("\nThe new string is %s\n", c);
				//now that we have no spaces, we know the file name starts at the 6th element of the string, limiting factor for this, is that file names cannot contain spaces
				char name[50];
				//pull the name parameter out of c, no spaces allowed in file names
				for(int i = 0; i < 50; i++) name[i] = c[i+6];		
				
				//Debugging line
				//printf("\nThe name parameter is %s\n", name);
				
				//Make sure an actual file name was provided, if not throw an error message
				if (name[0] == NULL){
						printf("\nInvalid file name\n");
						//end child
						exit(0);}
				else{
					create(name);
					printf("\nDone\n");
					//end child
					exit(0);}
			}
			else
			cpid = wait(NULL);


		}
		
		
	
	}


}


