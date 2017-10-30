#include <stdio.h>
#include <string.h>
#include <ctype.h>

	// Global Functions
	int isNum(char *token);
	int countTokens (char *line);
	

int main()
{
	// Header
	printf("Assignment #1-3, Kylee Webb, kawebb@sdsu.edu\n");
			

	char buffer[256];
	char token[256];
	int numTokes = 0;
	int count = 0;
	int total = 0;
	int t = 0;
	
	do 
	{
		printf("> ");
		fgets(buffer,66,stdin);   
		if(countTokens(buffer)!= 2 && countTokens(buffer)!= 1){
			printf("ERROR! Incorrect number of tokens found.\n");
		}
	}
	while(countTokens(buffer)!= 2 && countTokens(buffer)!= 1);

	while(buffer[t] != '\0') 
	{
		
		sscanf(buffer+t," %s %n", token, &count);
		t = t + count;
	
		if(countTokens(buffer) <= 2 && isNum(token) == 0) 
		{
			printf("INT ");

		}	
	
		else if(countTokens(buffer) <= 2 && countTokens(buffer) != 0 )
		{
			printf("STR ");
		}

	}
	printf("\n");
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
