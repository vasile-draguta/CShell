#include "../includes/constants.h"
#include "../includes/readLine.h"


char *readLine() {
    int bufferSize = INPUT_SIZE, pos = 0;
    char *buffer = malloc(sizeof(char) * bufferSize);
    char c;

    if (!buffer) {
        perror("$: Input allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[pos] = '\0';
            return buffer;
        } else {
            buffer[pos] = c;
        }

        pos++;

        if (pos >= bufferSize) {
            bufferSize += INPUT_SIZE;
            buffer = realloc(buffer, bufferSize);

            if (!buffer) {
                perror("$: Input reallocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return buffer;
}