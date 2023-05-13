#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

/* Function Prototypes */
void display_prompt(void);
char *read_input(void);
void execute_command(char *command);
void handle_signal(int signal);

#endif /* SHELL_H */
