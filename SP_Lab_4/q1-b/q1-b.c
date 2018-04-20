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
}
