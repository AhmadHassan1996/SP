#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char buffer[256];
	int fd=open("/etc/passwd", O_RDONLY);
	close(0);
	dup(fd);
	int fd1=read(fd, buffer, 256);
	write(1, buffer, fd1);

	return 0;
}
