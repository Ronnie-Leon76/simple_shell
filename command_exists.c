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
		command_length = _strlen(cmd);
		path_token = _strtok(path, ":");
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, cmd);
			_strcat(file_path, "\0");
			if (access(file_path, F_OK) == 0)
			{
				return (1);
			}
			path_token = _strtok(NULL, ":");
		}
		return (0);

	}
	return (0);
}
