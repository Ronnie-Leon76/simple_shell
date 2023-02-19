#include "main.h"

char *get_location(char *command){
    char *path, *path_copy;
    int directory_length;
    char *file_path;
    char *path_token;
    int command_length;

    path = getenv("PATH");
    path_copy = strdup(path);

    command_length = strlen(command);

    path_token = strtok(path_copy, ":");
    directory_length = strlen(path_token);
    file_path = malloc(command_length + directory_length + 2 );

    strcpy(file_path, path_token);
    strcat(file_path, "/");
    strcat(file_path, command);
    strcat(file_path, "\0");
}