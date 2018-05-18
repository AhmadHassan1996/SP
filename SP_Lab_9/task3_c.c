#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char buffer[256];
	int fd=open("f1", O_RDONLY);
	int fd1=open("f2", O_WRONLY);
	dup2(fd, 0);
	dup2(fd1, 1);
	dup2(1, 2);

	if (fd!=-1)
	{
		int fd2=read(0, buffer, 256);
		write(1, buffer, fd2);
	}

	return 0;
}
