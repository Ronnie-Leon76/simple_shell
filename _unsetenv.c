#include "main.h"
/**
 * _unsetenv - unsets an environment variable
 * @name: name of variable
 * Return: 0
 */
int _unsetenv(char *name)
{
	int i = 0, j = 0;
	extern char **environ;

	if (name == NULL)
		return (-1);
	while (environ[i])
	{
		while (name[j] != '\0')
		{
			if (environ[i][j] != name[j])
				break;
			j++;
		}
		if (environ[i][j] == '=')
		{
			environ[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}
