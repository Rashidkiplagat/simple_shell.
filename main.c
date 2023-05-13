#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *line;
	char **args;
	int status;

	do 
{
	printf("$ "); // Display the shell prompt
	line = read_line(); // Read input from the user
	args = split_line(line); // Parse the input into arguments
	status = execute(args); // Execute the command and get the status
	free(line);
	free(args);
}
	while (status);
	return EXIT_SUCCESS;
}
