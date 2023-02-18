#include "main.h"

char *get_location(char *command){
    char *path, *path_copy;

    path = getenv("PATH");
    path_copy = strdup(path);

    command_length = strlen(command);

    path_token = strtok(path_copy)
}