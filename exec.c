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
	extern char **environ;

	if (argv)
	{
		command = argv[0];
		/**
		if (_strcmp(command, "exit") == 0)
		{
			__exit(argv);
		}
		**/
		if (_strcmp(command, "env") == 0)
		{
			for (env = environ; *env != NULL; env++)
				printf("%s\n", *env);
		}

		actual_command = get_location(command);

		if (execve(actual_command, argv, NULL ) == -1)
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory \n", argv[0]);
		}
	}
}
