#include "../includes/constants.h"
#include "../includes/splitLine.h"


char** splitLine(char *line) {
    int bufferSize = TOKEN_SIZE, pos = 0;
    char **tokens = malloc(sizeof(char*) * bufferSize);
    char *token;

    if(!tokens) {
        perror("$: Token allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIM);
    while(token != NULL) {
        tokens[pos] = token;
        pos++;

        if (pos >= bufferSize) {
            bufferSize += TOKEN_SIZE;
            tokens = realloc(tokens, bufferSize * sizeof(char*));

            if (!tokens) {
                perror("$: Token reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIM);
    }

    tokens[pos] = NULL;

    return tokens;
}