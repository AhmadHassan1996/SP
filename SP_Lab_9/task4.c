#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t oldset, newset;

	sigemptyset(&newset);
	sigaddset(&newset, SIGINT);
	sigprocmask(SIG_SETMASK, &newset, &oldset);

	printf("SIGINT will be stopped.\n");
	sleep(5);

	sigprocmask(SIG_SETMASK, &oldset, NULL);
	printf("SIGINT will be delivered.\n");

	return 0;
}
