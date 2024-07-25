#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Arguments {
    const char *longHand;
    const char *shortHand;
};

const struct Arguments arguments[] =  {
    { "--help", "-h" },
    { "--token", "-t" },
    { "--port", "-p" },
    { "--server", "-s" }
};

const int argumentsSize = 3;

char *stringToLower(const char *inputString) {
    int inputStringLength = strlen(inputString);
    char *outputString = (char *)malloc((inputStringLength + 1) * sizeof(char));

    if (outputString == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }

    for (int i = 0; i < inputStringLength; i++) {
        outputString[i] = tolower(inputString[i]);
    }
    outputString[inputStringLength] = '\0';

    return outputString;
}

int sizeOf(char *inputArray[]) {
    int argCount = 0;
    while (inputArray[argCount] != NULL) {
        argCount++;
    }

    return argCount;
}

bool stringInStruct(const char *inputString, struct Arguments argument) {
    for(int i = 0; i <= 1; i++) {
        if(strcmp(inputString, argument.shortHand) == 0 || strcmp(inputString, argument.longHand) == 0) {
            return true;
        }
    }
    return false;
}