#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>
#include "client.h"

int main(int argc, char *argv[]) {

    bool skipNextIteration = false;
    char *specifiedToken = (char *) malloc(sizeof(char) * 64);
    int specifiedPort = -1;
    char *specifiedServerAddress = (char *) malloc(sizeof(char) * 15);

    if (argc <= 1) {
        fprintf(stderr, "Need more arguments, use `%s -h` for more\n", argv[0]);
        return 1;
    }

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (skipNextIteration) {
            skipNextIteration = false;
        } else {
            if (stringInStruct(argv[i], arguments[0])) {
                return printHelp(argv[0], 0);
            } else if (stringInStruct(argv[i], arguments[1])) {
                specifiedToken = argv[i + 1];
                skipNextIteration = true;
            } else if (stringInStruct(argv[i], arguments[2])) {
                specifiedPort = atoi(argv[i + 1]);
                skipNextIteration = true;
            } else if (stringInStruct(argv[i], arguments[3])) {
                specifiedServerAddress = argv[i + 1];
                skipNextIteration = true;
            } else {
                fprintf(stderr, "Unrecognised argument: %s\n", argv[i]);
            }
        }
    }

    // Make sure all command line arguments are set
    if (specifiedToken[0] == '\0') {
        fprintf(stderr, "No token specified, please use `%s -h` for more information\n", argv[0]);
        return 2;
    } else if (specifiedPort == -1) {
        fprintf(stderr, "No port specified, please use `%s -h` for more information\n", argv[0]);
        return 2;
    } else if (specifiedServerAddress[0] == '\0') {
        fprintf(stderr, "No server address specified, please use `%s -h` for more information\n", argv[0]);
        return 2;
    }

    // Start sanitizing 
    

    fprintf(stdout, "Token: %s\nPort: %i\nServer Address: %s\n", specifiedToken, specifiedPort, specifiedServerAddress);
    return 0;
}