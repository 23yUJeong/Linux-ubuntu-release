#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();
	int n, child = 0, par = 0;

	scanf("%d", &n);

	if(pid == 0) {
		for(int i = 1; i <= n; i++) {
			child *= i;
		}
	}
	else if(pid > 0) {
		for(int i = 1; i <= n; i++) {
			par += i;
		}
	} else {
		printf("fail to fork\n");
	}

	printf("child : %d\n", child);
	printf("par : %d\n", par);
}
