#ifndef COMMAND_HISTORY_H

#define COMMAND_HISTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


typedef struct CommandHistory {
    char *command;
    struct CommandHistory *next;
} CommandHistory;

void addCommandToHistory(CommandHistory **history, char *command);

void initCommandHistory(CommandHistory **history);

void loadCommandHistory(CommandHistory **history);

void freeCommandHistory(CommandHistory **history);

void printCommandHistory(CommandHistory *history);


#endif 
