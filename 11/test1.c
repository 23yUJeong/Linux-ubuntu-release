#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h> // nonono

int main() {
	pid_t pid1, pid2;
	int filedes, p1[2], p2[2];
	fd_set initset, newset;
	int nread;
	char msg[MAGSIZE];

	pipe(p1);
	pipe(p2);

	pid1 = pid2 = 0;
	pid1 = fork();

	if(pid1 > 0) {
		pid2 = fork();
	}

	if((pid = fork()) == -1) {
		printf("fail to call fork()\n");
	}
	else if(pid > 0) {
		close(filedes[0]);
		printf("filedes[0] : %d\n", filedes[0]);
	} else {
		close(filedes[1]);
		printf("filedes[0] : %d\n", filedes[0]);
	}

	return 0;
}
