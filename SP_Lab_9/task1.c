#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGFPE, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	sleep(2);

	printf("SIGINT\n");
	printf("SIGFPE\n");
	printf("SIGQUIT\n");
	printf("SIGSTOP\n");
	printf("SIGHUP\n");

	return 0;
}
