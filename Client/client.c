#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Command line argument count: %d\n", argc);
    printf("Command line args:\n");
    for(int i = 0; i < argc; i++) {
        printf("\t[%d] %s\n", i, argv[i]);
    }

    return 0;
}