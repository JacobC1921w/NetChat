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

int printHelp(char *argv0, int returnValue) {
    fprintf(stdout, "NetChat client usage:\n\n");
    fprintf(stdout, "\t%s [options]\n\n", argv0);
    fprintf(stdout, "Options:\n\n");
    fprintf(stdout, "\t--help, -h\t\t\tPrints this help menu\n");
    fprintf(stdout, "\t--token=TOKEN, -t\t\tLogs in with the specified TOKEN\n");
    fprintf(stdout, "\t--port=PORT, -p\t\t\tConnects to server using PORT (1-25565)\n");
    fprintf(stdout, "\t--server=SERVER, -s\t\tConnects to the server using SERVER as the IP\n\n");
    fprintf(stdout, "Report bugs to \"<https://github.com/JacobC1921w/NetChat/issues>\"\n");
    return returnValue;
}

int match(const char *restrict regexString, const char *inputText) {
  regex_t regex;
  int returnInt = regcomp(&regex, regexString, REG_EXTENDED);

  if(returnInt) {
    regfree(&regex);
    return 2;
  }

  returnInt = regexec(&regex, inputText, 0, NULL, 0);
  regfree(&regex);

  if(!returnInt) {
    return 0;

  } else {
    return 1;
  }
}

bool validateIP(char *IPAddress) {
  char *splitToken = strtok(IPAddress, ".");
  int currentIPSegment;
  int IPIterations = 0;
  while (splitToken != NULL) {
    currentIPSegment = atoi(splitToken);

    if (currentIPSegment < 0 || currentIPSegment > 255) {
      return false;
    }
    IPIterations++;
    splitToken = strtok(NULL, ".");
  }
  if (IPIterations == 4) {
    return true;
  } else {
    return false;
  }
}
