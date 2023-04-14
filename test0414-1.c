#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int x, y, result1 = 1, result2 = 0;
	
	scanf("%d %d", &x, &y);

	pid = -1;
	pid = fork();
	if(pid > 0) {
		for(int i = 2; i <= y; i++) {
			result1 *= x;
		}
		waitpid(pid, &result2, 0);

		printf("parent : %d\n", result1);
		result2 = result2 >> 8;
		printf("result : %d\n", result1 + result2);
	}
	else if(pid <= 0) {
		for(int i = x; i < y; i++ ){
			result2 += i;
		}

		printf("child : %d\n", result2);
		sleep(1);
		exit(result2);
	} else {
		printf("fail to fork\n");
	}
}
