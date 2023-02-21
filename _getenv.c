#include "main.h"
/**
 * _getenv - gets the value of an environment variable
 * @name: name of variable
 * Return: value of variable
 */
char *_getenv(char *name)
{
	int i = 0, j = 0;
	extern char **environ;

	if (name == NULL)
		return (NULL);
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
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}
