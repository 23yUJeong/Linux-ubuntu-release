#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	DIR *dirp;
	struct dirent *dentry;

	if((dirp = opendir("/user/")) == NULL) {
		printf("fali....");
		exit(1);
	}

	while(dentry = readdir(dirp)) {
		if(dentry->d_ino != 0) {
			printf("success!!");
		}

	closedir(dirp);
}
}
