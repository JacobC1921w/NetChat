#include <stdio.h>
#include "client.h"

/*
Command line args:
    --server -s (server IP)
    --port -p (server port)
    --username -u (client username)
    --password -p (client password)
    --token -t (client token)
    --help -h
*/

int main(int argc, char *argv[]) {
    // Parse command line arguments
    for (int i = 1; i <= argc; i++) {
        if (stringInArray(toLower(argv[i]), helpArguments)) {
            fprintf(stdout, "help!");
        } else if (stringInArray(toLower(argv[i]), tokenArguments)) {
            fprintf(stdout, "token!");
        } else if (stringInArray(toLower(argv[i]), portArguments)) {
            fprintf(stdout, "port!");
        } else if (stringInArray(toLower(argv[i]), serverArguments)) {
            fprintf(stdout, "server!");
        } else {
            fprintf(stderr, "Unrecognised argument!");
        }
    }
    return 0;
}