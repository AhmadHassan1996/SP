#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Real user id : %d\n", getuid());
	printf("Effective user id : %d\n", geteuid());
	printf("Real group id : %d\n", getgid());
	printf("Effective group id : %d\n", getegid());
}
