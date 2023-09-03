#include "csapp.h"

int main()
{
	pid_t pid;

	if ((pid = Fork()) == 0) {
		Pause();
		printf("control should never reach here!\n");
		exit(0);
	}

	kill(pid, SIGKILL);
	exit(0);
}
