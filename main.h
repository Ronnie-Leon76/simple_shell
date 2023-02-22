#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
void exec(char **argv);
char *get_location(char *command);
int command_exists(char *cmd);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int exit_builtin();
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, char *delim);
int __exit(char **args);
int _atoi(char *s);
int _setenv(char *name, char *value, int overwrite);
int _unsetenv(char *name);
int _cd(char **args);
char *_getenv(char *name);
#endif
