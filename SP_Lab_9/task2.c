#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	int cpid=0;

	cpid=fork();

	if (cpid==0)
	{
		while (1)
		{
			printf("Child Process.\n");
			sleep(1);
		}
	}
	else
	{
		sleep(5);
		kill(cpid, SIGINT);
		printf("Child killed by parent.\n");
	}

	return 0;
}
