#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

 
	//Functions for specific tasks
	int isNum(char *token);
	int countTokens (char *line);

	
int main()
{
	printf("Assignment #1-4, Kylee Webb, kawebb@sdsu.edu\n");
			
	char buffer[256];
	char token[256];
	// int numTokes = 0;
	int count = 0;
	//int total = 0;
	int t = 0;
	int quit = 0;
	int numTokens = 0;

	
	
	while(1)
	{
		numTokens = 0;  // This resets the tokens each loop
		t = 0;  	// resets the total count each loop to zero
		count = 0;	// resets the total count each loop
		
	
		printf("> ");	
		fgets(buffer, 256, stdin);
		
		numTokens = countTokens(buffer);
		
		if(numTokens == 1){
			sscanf(buffer+t," %s %n", token, &count);
			if(strcasecmp(token, "quit") == 0){
				break;
			}
		}
		t = 0;
		count = 0;
		
		while((numTokens < 1 || numTokens > 2) || strlen(buffer) > 21){
			if(strlen(buffer) > 21){
				printf("ERROR! Input string too long.\n");
			}
			
			else if(numTokens < 1 || numTokens > 2){
				printf("ERROR! Incorrect number of tokens found.\n");
			}
	
			printf("> ");	
			fgets(buffer, 256, stdin);
			numTokens = countTokens(buffer);
			if(numTokens == 1 ){
				sscanf(buffer+t," %s %n", token, &count);
				if(strcasecmp(token, "quit") == 0){
					return 0;
				}
			}
			t = 0;
			count = 0;
		}
		
		while(t != strlen(buffer)){		// t is char count != the length of buffer		
			sscanf(buffer+t," %s %n", token, &count); 	// counting the bytes read
			t = t + count;
			if(isNum(token) == 1){
				printf("STR ");
			}
			else
				printf("INT ");
		}
		
		printf("\n");
	
		
		
	}
	return 0;
}
	

//Finds out if it is a number or not
int isNum(char *token)
{
	for(int i = 0; i < strlen(token); i++)
	{
		if(!isdigit(token[i]))
			return 1;
	}
	
	return 0;
} // End of main
// Checks how many tokens there are
int countTokens (char *line)
{
	int numTokens = 0;
	char token[256];
	int count = 0;
	int t = 0;
	while(line[t] != '\0') 
	{
		if(strlen(line) - 1 == 0)
			return 0;
		sscanf(line+t," %s %n", token, &count);
		t = t + count;
		numTokens++;
	}
		return numTokens;
}











		


 



