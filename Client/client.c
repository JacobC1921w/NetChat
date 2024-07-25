#include <stdio.h>
#include "client.h"

/*
Command line args:
    --server -s (server IP)
    --port -p (server port)
    --token -t (client token)
    --help -h
*/

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Need more arguments, use `%s -h` for more", argv[0]);
        return 1;
    }

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (stringInStruct(argv[i], arguments[0])) {
            printf("Help!\n");
        } else if (stringInStruct(argv[i], arguments[1])) {
            printf("Token!\n");
        } else if (stringInStruct(argv[i], arguments[2])) {
            printf("Port!\n");
        } else if (stringInStruct(argv[i], arguments[3])) {
            printf("Server!\n");
        } else {
            fprintf(stderr, "Unrecognised argument: %s\n", argv[i]);
        }
    }
    return 0;
}