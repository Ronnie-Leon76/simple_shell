#include "main.h"
/**
 * _exit - exits the shell
 * @args: arguments
 * Return: 0
 */
int __exit(char **args)
{
	int status = 0;

	if (args[1] == NULL)
		exit(0);
	else
	{
		status = _atoi(args[1]);
		exit(status);
	}
	return (0);
}
