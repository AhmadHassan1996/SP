#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void mySignalHandler(int sig)
{
	switch(sig)
	{
		case 2:
			printf("I got SIGINT.\n");
			break;
		case 8:
			printf("I got SIGFPE.\n");
			break;
		case 3:
			printf("I got SIGQUIT.\n");
			break;
		case 20:
			printf("I got SIGSTOP.\n");
			break;
		case 1:
			printf("I got SIGHUP.\n");
			break;
		case 9:
			printf("I got SIGKILL.\n");
			break;
	}
}

int main()
{
	signal(SIGINT, mySignalHandler);
	signal(SIGFPE, mySignalHandler);
	signal(SIGQUIT, mySignalHandler);
	signal(SIGSTOP, mySignalHandler);
	signal(SIGHUP, mySignalHandler);
	signal(SIGKILL, mySignalHandler);

	while (1)
	{
		printf("I am in an infinite loop.\n");
		sleep(1);
	}

	return 0;
}
