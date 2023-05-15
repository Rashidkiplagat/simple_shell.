#include "main.h"

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[MAX_PROMPT_LENGTH] = "#cisfun$ ";
	ssize_t promptLength = sizeof(prompt) - 1; /*Subtract 1 to exclude the null terminator*/

    while (1)
    {
	    write(STDOUT_FILENO, prompt, promptLength);
	    ssize_t commandLength = read(STDIN_FILENO, command, sizeof(command));

	    if (commandLength < 0)
	    {
		    perror("Error reading command");
		    exit(EXIT_FAILURE);
        } else if (commandLength == 0)
	{
		/*End of file condition (Ctrl+D)*/
            break;
        }

        /*Remove trailing newline character*/
        if (command[commandLength - 1] == '\n')
	{
            command[commandLength - 1] = '\0';
            commandLength--; /*Decrease length by 1*/
        }

	if (commandLength == 0)
	{
            const char* error_message = "No command provided\n";
            ssize_t errorLength = sizeof("No command provided\n") - 1;
            write(STDERR_FILENO, error_message, errorLength);
            continue;
        }

	pid_t pid = fork();
        if (pid < 0)
	{
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0)
	{
            /* Child process*/
	char* args[] = {command, NULL};
        execve(command, args, NULL);

	/*If execve returns, an error occurred*/
	const char* error_message = ": command not found\n";
            ssize_t commandNameLength = commandLength;
            ssize_t errorLength = commandNameLength + sizeof(": command not found\n") - 1;
            write(STDERR_FILENO, command, commandNameLength);
            write(STDERR_FILENO, error_message, errorLength);
	    exit(EXIT_FAILURE);
	    } else
	    {
            /*Parent process*/
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid failed");
                exit(EXIT_FAILURE);
            }
	    }
	}
	return(0);
}
