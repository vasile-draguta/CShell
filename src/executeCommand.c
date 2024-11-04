
#include "../includes/constants.h"
#include "../includes/executeCommand.h"
#include "../includes/builtins.h"
#include "../includes/commandHistory.h"

char *builtinsString[] = {
    "cd",
    "exit",
    "help",
    "history",
};

int (*builtinsCommands[]) (char **) = {
    &changeDirectory,
    &exitShell,
    &help,
    &history
};

int numOfBuiltins() {
    return sizeof(builtinsString) / sizeof(char *);
}

int launchCommand(char **args) {
    pid_t childPid, waitPid;
    int status;

    childPid = fork();
    if(childPid == -1) {
        perror("$: Fork error\n");
        exit(EXIT_FAILURE);
    }
    else if(childPid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("$: Execution error\n");
        }
        exit(EXIT_FAILURE);
    }
    else {
        do {
            waitPid = waitpid(childPid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return EXECUTION_STATUS;
}


int executeCommand(char **args) {
    if(args[0] == NULL) {
        return EXECUTION_STATUS;
    }

    for(int i = 0; i < numOfBuiltins(); i++) {
        if(strcmp(args[0], builtinsString[i]) == 0) {
            return (*builtinsCommands[i])(args);
        }
    }

    return launchCommand(args);
    
}