#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int cpid=-1;

	cpid=fork();

	if (cpid==-1)
	{
		printf("Fork Failed.\n");
		exit(1);
	}
	if (cpid==0)
	{
		printf("Child PID : %d\n", getpid());
		printf("Child PPID : %d\n", getppid());
	}
	else
	{
		wait();
		printf("Parent PID : %d\n", getpid());
		printf("Parent PPID : %d\n", getppid());		
	}

	return 0;
}
