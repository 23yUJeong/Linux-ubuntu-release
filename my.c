#include <stdlib.h>

void file1(char *);

int main(int argc, char **argv)
{
	if(argc != 2) exit(0);

	file1(argv[1]);
}

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void file1(char *filename)
{
int cnt = 0;
	int fd = open(filename, O_RDWR | O_CREAT, 0644);
	char a[1024] = "cfghjihkjvb1234";
	write(fd, a, 1024);
	close(fd);

	fd = open(filename, O_RDWR, 0644);
	char c[1024] = {};

	for(int i = 0; i < 1024; i++){
		if(a[i] >= 65 && a[i] <= 90){
		c[i] = a[i];
		cnt++;
		}
		else if(a[i] >= 97 && a[i] <= 122){
		c[i] = a[i];
		cnt++;
		}
	}

	read(fd, c, 1024);
	close(fd);
	printf("%d\n",cnt);
}
