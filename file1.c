#include <stdio.h>

int main()
{
	FILE *file;
	file = fopen("test.txt", "r");

	printf("s\n", fgetc(file));
	fclose(file);
}
