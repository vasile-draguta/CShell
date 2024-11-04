
#include "../includes/builtins.h"
#include "../includes/constants.h"

int changeDirectory(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("Error");
        }
    }
    return EXECUTION_STATUS;
}

int help(char **args) {
    printf("For information use command 'man + instruction that you want to run!'\n");
    return EXECUTION_STATUS;
}

int history(char **args) {
    return EXECUTION_STATUS;
}

int exitShell(char **args) {
    return EXIT_STATUS;
}
