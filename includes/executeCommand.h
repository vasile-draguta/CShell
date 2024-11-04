#ifndef EXECUTE_COMMAND_H

#define EXECUTE_COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int launchCommand(char **args);
int executeCommand(char **args);
int printCommandHistoryWrapper(char **args);

#endif