#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * main - Simple Shell
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the arguments passed to the program.
 *
 * Return: Always returns 0.
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	pid_t pid;
	int status;

	while (1)
{
	printf("#cisfun$ ");
characters = getline(&buffer, &bufsize, stdin);

// Check for end of file condition (Ctrl+D)
	if (characters == -1)
{
	printf("\n");
	break;
}

// Remove newline character
	buffer[strcspn(buffer, "\n")] = '\0';

// Check if command line is empty
	if (strcmp(buffer, "") == 0)
	continue;

// Create child process
	pid = fork();

// Check for fork error
	if (pid < 0)
{
	perror("Fork error");
	exit(EXIT_FAILURE);
}

// Child process
	if (pid == 0)
{
// Execute command
	if (execve(buffer, argv, NULL) == -1)
{
	perror("Execve error");

// Exit child process with failure status
	exit(EXIT_FAILURE);
}
}

// Parent process
	if (pid > 0)
{
// Wait for child process to finish
	if (waitpid(pid, &status, 0) == -1)
{
	perror("Waitpid error");
	exit(EXIT_FAILURE);
}

// Check if child process exited normally
	if (WIFEXITED(status))
{
// Get exit status of child process
	int exit_status = WEXITSTATUS(status);

// Check if child process exited with failure status
	if (exit_status != 0)
	fprintf(stderr, "Child process exited with status %d\n", exit_status);
}
}
}

// Free buffer memory
	free(buffer);

	return (0);
}
