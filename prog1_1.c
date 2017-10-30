#include <stdio.h>
#include <string.h>

int main()
{

	printf("Assignment #1-1, Kylee Webb, kawebb@sdsu.edu\n");	

	char buffer[256];
	char token[256];

	int count = 0;
	int total = 0;


	fgets(buffer,66,stdin);


	while (total < strlen(buffer))
	{
		
	
		sscanf(buffer+total, " %s %n", token, &count);

		total = total + count;

		printf("=%s=\n", token);
	}



	return 0;

}
	


