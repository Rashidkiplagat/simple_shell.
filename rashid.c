#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cd(char *path) {
    if (chdir(path) != 0) {
        perror("cd");
    }
}

int main(int argc, char **argv) {
    // Get the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }

    // Change to the directory specified in the first argument
    if (argc > 1) {
        cd(argv[1]);
    } else {
        // No argument was passed, so go to the home directory
        cd(getenv("HOME"));
    }

    // Print the new working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd() error");
        return EXIT_FAILURE;
    }
    printf("%s\n", cwd);

    return EXIT_SUCCESS;
}
