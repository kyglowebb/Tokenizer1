#include <stdio.h>
#include <string.h>
#include <ctype.h>

	
	int isNum(char *token);

	int count = 0;
	int total = 0;

	int main(int argc, char **argv)
{
	printf("Assignment #1-2, Kylee Webb, kawebb@sdsu.edu\n");	

	char buffer[256];
	char token[256];

	printf("> ");
		
	fgets(buffer,66,stdin);   
	
	// takes input and decides to print STR or INT
	char choices[66];
	int t = 0, flag = 1;

	// Takes the input from buffer and stores it into choices
	sscanf(buffer, "%s", choices);

	while(buffer[t] != '\0') {
	sscanf(buffer+t," %s %n", token, &count);
	t = t + count;
	if(isNum(token) == 0) {
	printf("INT ");
	}
	else {
	printf("STR ");
	}	

	}

	return 0;

}


int isNum(char *token)
{
	for(int i = 0; i < strlen(token); i++)
	{
		if(!isdigit(token[i]))
			return 1;
	}
	return 0;



}



	


