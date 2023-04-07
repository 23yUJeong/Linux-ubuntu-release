#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filedes;
void func1(void);

int main() {
	ssize_t nread;
	char buffer[1024];

	atexit(func1);

	filedes = open("data.txt", O_RDONLY);
	while((nread = read(filedes, buffer, 1024)) > 0) {
		printf("%s", buffer); // contents of file
	}

	// exit(1); // }, return too OK
}

void func1(void)
{
	printf("close!");
	close(filedes);
}
