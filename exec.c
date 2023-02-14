#include "main.h"
/**
 * exec - handles command execution
 * @argv: argument vector containing the tokens
 * Return: Always (0)
 */
void exec(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL ) == -1)
		{
			dprintf(STDERR_FILENO, "%s: No such file or directory \n", argv[0]);
		}
	}
}
