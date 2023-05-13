#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() 
{
	printf("Hello, world!\n");
	return 0;
}
void print_prompt(void)
{
	char host[HOST_NAME_MAX];
	char *user = getlogin();
	if (gethostname(host, HOST_NAME_MAX) == -1)
	perror("gethostname");
	printf("%s@%s $ ", user, host);
}
