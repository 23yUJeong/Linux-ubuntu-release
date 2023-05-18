#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void handler(int signum);

int main() {
	struct sigaction act;
	pid_t pid;

	sigfillset(&(act.sa_mask));
	act.sa_handler = handler;
	sigaction(SIGINT, &act, NULL);

	if((pid = fork()) > 0) {
		printf("[parent] hello\n");
		pause();
		printf("[parent] bye!\n");
	}
	else if(pid == 0) {
		printf("[childe] hello\n");
		sleep(1);
		kill(getppid(), SIGINT);
		printf("[childe] bye\n");
	} else {
		printf("fall to fork\n");
	}
}

void handler(int signum) {
	printf("...\n");
}
