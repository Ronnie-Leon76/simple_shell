#include "main.h"
/**
 * exec - handles command execution
 * @argv: argument vector containing the tokens
 * Return: Always (0)
 */
void exec(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	char **env;

	if (argv)
	{
		command = argv[0];
		if (_strcmp(command, "exit") == 0)
		{
			_exit(_atoi(argv[1]));
		}
		else if (_strcmp(command, "env") == 0)
		{
			for (env = environ; *env != NULL; env++)
				printf("%s\n", *env);
		}
		else if (_strcmp(command, "setenv") == 0)
		{
			_setenv(argv[1], argv[2], _atoi(argv[3]));
		}
		else if (_strcmp(command, "unsetenv") == 0)
		{
			_unsetenv(argv[1]);
		}
		else if (_strcmp(command, "cd") == 0)
		{
			_cd(argv);
		}
		actual_command = get_location(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory \n", argv[0]);
		}
	}
}
