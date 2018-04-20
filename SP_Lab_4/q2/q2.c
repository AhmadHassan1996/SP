#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	uid_t ruid, euid, suid;
	gid_t rgid, egid, sgid;

	getresuid(&ruid, &euid, &suid);
	getresgid(&rgid, &egid, &sgid);

	printf("Real user id : %d\n", ruid);
	printf("Effective user id : %d\n", euid);
	printf("Saved user id : %d\n", suid);
	printf("Real group id : %d\n", rgid);
	printf("Effective group id : %d\n", egid);
	printf("Saved group id : %d\n", sgid);

	int rv=setuid(501);

	if (rv!=-1)
	{
		getresuid(&ruid, &euid, &suid);
		getresgid(&rgid, &egid, &sgid);

		printf("ID's after setting effective uid : \n");
		printf("Effective user id : %d\n", euid);
		printf("Saved user id : %d\n", suid);
		printf("Effective group id : %d\n", egid);
		printf("Saved group id : %d\n", sgid);
	}
	else
	{
		printf("Error in setting ID.\n");
	}
}
