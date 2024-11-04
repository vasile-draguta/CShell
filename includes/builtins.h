#ifndef BUILTINS_H

#define BUILTINS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int changeDirectory(char **args);
int exitShell(char **args);
int help(char **args);
int history(char **args);

extern char *builtinsString[];
extern int (*builtinsCommands[]) (char **);
int numOfBuiltins();

#endif
