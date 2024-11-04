#include "../includes/readLine.h"
#include "../includes/splitLine.h"
#include "../includes/executeCommand.h"
#include "../includes/commandHistory.h"

char* getWorkingDirectory() {
    char *cwd = (char *) malloc(1024);
    getcwd(cwd, 1024);
    return cwd;
}

char* getPrompt() {
    char *cwd = getWorkingDirectory();
    strcat(cwd, " $: ");
    return cwd;
}

void runShell() {
    char *line;
    char **args;
    int status;
    CommandHistory *history = NULL;
    initCommandHistory(&history);
    
    char *cwd = getPrompt();
    do {
        printf("%s", cwd);
        line = readLine();
        addCommandToHistory(&history, line);

        args = splitLine(line);
        status = executeCommand(args);

        if (strcmp(args[0], "cd") == 0) {
            free(cwd);
            cwd = getPrompt();
        } else if (strcmp(args[0], "history") == 0) {
            printCommandHistory(history);
        }

        free(line);
        free(args);
        fflush(stdout);
    } while (status);

    freeCommandHistory(&history);
    free(cwd);
}
