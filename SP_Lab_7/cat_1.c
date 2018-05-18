#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char * argv[],char * env[])
{
	if (argc<2)
	{
		printf("Invalid number of arguments.\n");
		exit(0);
	}
	
	char buffer[256];
	
	int fd1=read(0, buffer, 256);
	int fd2=open(argv[1], O_CREAT|O_WRONLY|O_TRUNC, 0600);
	int fd3=write(fd2, buffer, fd1);

	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}

