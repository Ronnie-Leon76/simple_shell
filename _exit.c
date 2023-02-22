#include "main.h"
/**
 * _exit - exits the shell and returns status code or (0)
 * @args: arguments
 * Return: status code or (0) if no status code
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
