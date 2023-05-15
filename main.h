#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_PROMPT_LENGTH 10

ssize_t my_read(int fd, void *buf, size_t count);


#endif
