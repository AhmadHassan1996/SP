#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	if (argc!=2)
	{
		printf("Invalid number of arguments.\n");
		exit(0);
	}

	if (access(argv[1], R_OK)==0)
	{
		printf("This file has read permission.\n");
	}
	else
	{
		printf("This file does not have read permission.\n");
	}
	if (access(argv[1], W_OK)==0)
	{
		printf("This file has write permission.\n");
	}
	else
	{
		printf("This file does not have write permission.\n");
	}
	if (access(argv[1], X_OK)==0)
	{
		printf("This file has execute permission.\n");
	}
	else
	{
		printf("This file does not have execute permission.\n");
	}

	return 0;
}
