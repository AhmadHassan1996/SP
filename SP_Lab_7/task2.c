#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char * argv[],char * env[])
{
	if (argc<2)
	{
		printf("Invalid number of arguments.\n");
		exit(0);
	}
	
	char buffer[256];
	int fd=open("/etc/shadow", O_RDONLY);
	int fd1=read(fd, buffer, 256);
	int fd2=open(argv[1], O_CREAT|O_WRONLY|O_TRUNC, 0600);
	int fd3=write(fd2, buffer, fd1);

	close(fd);
	close(fd1);
	close(fd2);
	close(fd3);

	return 0;
}

