#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int cpid=-1;
	int status;

	cpid=fork();

	if (cpid==-1)
	{
		printf("Fork Failed.\n");
		exit(1);
	}
	if (cpid==0)
	{
		exit(-1);
	}
	else
	{
		wait(&status);
		printf("Exit status : %d\n", WEXITSTATUS(status));
	}

	return 0;
}
