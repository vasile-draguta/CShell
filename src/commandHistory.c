#include "../includes/commandHistory.h"


void initCommandHistory(CommandHistory **history) {
    FILE* fd = fopen("../history.txt", "r");

    if (fd == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[1024];

    while (fscanf(fd, "%1023s", line) != EOF) {
        addCommandToHistory(history, line);
    }

    fclose(fd);
}

void loadCommandHistory(CommandHistory **history) {
    FILE* fd = fopen("../history.txt", "w");

    if (fd == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    CommandHistory *current = *history;
    while (current != NULL) {
        fprintf(fd, "%s\n", current->command);
        current = current->next;
    }

    fclose(fd);
}

void addCommandToHistory(CommandHistory **history, char *command) {
    CommandHistory *newCommand = (CommandHistory *) malloc(sizeof(CommandHistory));
    newCommand->command = (char *) malloc(strlen(command) + 1);
    strcpy(newCommand->command, command);
    newCommand->next = NULL;

    if (*history == NULL) {
        *history = newCommand;
    } else {
        CommandHistory *current = *history;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCommand;
    }

}


void freeCommandHistory(CommandHistory **history) {
    if (*history == NULL) {
        return;
    }

    loadCommandHistory(history);

    CommandHistory *current = *history;
    while (current != NULL) {
        CommandHistory *next = current->next;
        free(current->command);
        free(current);
        current = next;
    }
}

void printCommandHistory(CommandHistory *history) {
    CommandHistory *current = history;
    while (current != NULL) {
        printf("%s\n", current->command);
        current = current->next;
    }
}
