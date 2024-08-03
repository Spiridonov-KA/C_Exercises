/*
* clang-15 -cc1 -ast-dump your_file.c
* https://stackoverflow.com/questions/18560019/how-to-view-clang-ast
*/

#include <stdio.h>

int main() {
	int ifa = 10;
	printf("Hello! %d\n", ifa);
	return 0;
}
