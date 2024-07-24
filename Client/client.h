#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *helpArguments[] = {"--help", "-h"};
char *tokenArguments[] = {"--token", "-t"};
char *portArguments[] = {"--port", "-p"};
char *serverArguments[] = {"--server", "-s"};

char *toLower(const char *inputString) {
    int inputStringLength = strlen(inputString);
    char *outputString = (char *)malloc((inputStringLength + 1) * sizeof(char));

    if (outputString == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < inputStringLength; i++) {
        fprintf(stdout, "Iteration: %c\n", inputString[i]);
        outputString[i] = tolower(inputString[i]);
    }
    outputString[inputStringLength] = '\0';

    fprintf(stdout, "In: %s\nOut: %s\n", inputString, outputString);
    return outputString;
}

int sizeOf(char *inputArray[]) {
    int argCount = 0;
    while (inputArray[argCount] != NULL) {
        argCount++;
    }

    return argCount;
}

bool stringInArray(const char *inputString, char *inputArray[]) {
    for (int i = 0; i <= sizeOf(inputArray); i++) {
        if (toLower(inputArray[i]) == toLower(inputString)) {
            return true;
        }
    }
    return false;
}