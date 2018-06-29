#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[256];
	int fd=open("f1", O_RDONLY);
	int fd2=open("f1", O_WRONLY);
	dup2(fd, 0);
	dup2(fd2, 1);
	dup2(1, 2);

	if (fd!=-1)
	{
		int fd1=read(0, buffer, 256);
		write(1, buffer, fd1);
		close(fd1);
	}
	
	close(fd);
	return 0;
}
