#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s path\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) != 0) {
        perror("chdir");
        return 1;
    }

    return 0;
}
