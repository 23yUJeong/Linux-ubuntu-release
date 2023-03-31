#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	DIR *dirp;
	struct dirent *dentry;
	int cnt = 0;

	if((dirp = opendir(".")) == NULL) {
		exit(1);
	}

	while(dentry = readdir(dirp)) {
		if(dentry->d_ino != 0) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	closedir(dirp);
}
