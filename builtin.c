#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cd(char *path) {
	if (chdir(path) == -1) {
	perror("cd");
}
}

int main() {
	char path[100];

	while (1) {
	printf("$ ");
	fgets(path, 100, stdin);

	if (strcmp(path, "cd\n") == 0) {
	cd(getenv("HOME"));
} 
	else if (strncmp(path, "cd ", 3) == 0) {
	cd(path + 3);
} 
	else if (strcmp(path, "exit\n") == 0) {
	exit(0);
}
	else
{
	printf("Invalid command\n");
}
}
	return 0;
}
