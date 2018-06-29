#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[256];
	int fd=open("file", O_RDONLY);
	int fd1=open("errorAndoutput.txt", O_CREAT|O_RDONLY);
	close(fd1);
	int fd2=open("errorAndoutput.txt", O_WRONLY);

	if (fd==-1)
	{
		dup2(fd2, 2);
	}
	else
	{
		int fd3=read(fd, buffer, 256);
		dup2(fd2, 1);
		write(1, buffer, fd3);
		close(fd3);
	}

	close(fd);
	close(fd2);
	return 0;
}
