#include "main.h"
/**
 * command_exists - checks if the command exists
 * command: command to be checked if it exists
 * Return: (1) if found else (0)
 */
int command_exists(char *cmd)
{
	char *path, *path_token, *file_path;
	int command_length, directory_length;

	path = getenv("PATH");

	if (path)
	{
		command_length = strlen(cmd);
		path_token = strtok(path, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (access(file_path, F_OK) == 0)
			{
				return (1);
			}
			path_token = strtok(NULL, ":");
		}
		return (0);

	}
	return (0);
}
