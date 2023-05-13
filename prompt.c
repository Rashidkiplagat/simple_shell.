#include "shell.h"

/**
 * main - Entry point for the shell
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
	print_prompt();
	line = read_line();
	args = split_line(line);
	status = execute(args);

	free(line);
	free(args);
} while (status);

	return (0);
}

/**
 * print_prompt - Prints the prompt for the shell
 */
void print_prompt(void)
{
	struct passwd *pw = getpwuid(getuid());
	char *username = pw->pw_name;
	char hostname[HOST_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);

	printf("\033[1;32m%s@%s$ \033[0m", username, hostname);
}

/**
 * read_line - Reads a line of input from stdin
 *
 * Return: The line read from input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
{
	if (feof(stdin))
{
	exit(EXIT_SUCCESS);
}
	else
{
	perror("read_line");
	exit(EXIT_FAILURE);
}
}

	return (line);
}
