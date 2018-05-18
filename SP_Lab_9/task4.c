#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char * argv[])
{
	if (argc<2)
	{
		printf("Invalid number of arguments.\n");
		exit(0);
	}

	struct stat buffer;
	time_t mytime;
	char content[20];

	for (int i=1;i<argc;i++)
	{
		if(lstat(argv[i], &buffer)<0)
		{
			printf("Error\n");
		}
		else
		{
			if (S_ISREG(buffer.st_mode))
			{
				printf("%s is a file.\n", argv[i]);
				printf("inode number : %d \n", buffer.st_ino);

				mytime=buffer.st_atime;
				strftime(content, 21, "%d-%m-%Y %H:%M:%S\n", localtime(&mytime));
				printf("access time : %s", content);

				mytime=buffer.st_mtime;
				strftime(content, 21, "%d-%m-%Y %H:%M:%S\n", localtime(&mytime));
				printf("modifies time : %s", content);

				printf("size : %d \n", buffer.st_size);
			}
			else if (S_ISDIR(buffer.st_mode))
			{
				printf("%s is a directory.\n", argv[i]);
				printf("user ID : %d \n", buffer.st_uid);
			}
		}
		printf("\n");
	}

	return 0;
}
