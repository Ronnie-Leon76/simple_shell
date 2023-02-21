#include "main.h"
/**
 * _Setenv - sets an environment variable
 * @name: name of variable
 * @value: value of variable
 * @overwrite: overwrite flag
 * Return: 0
 */
int _setenv(char *name, char *value, int overwrite)
{
	int i = 0, j = 0, k = 0, len = 0;
	char *new_env = NULL, *new_value = NULL;
	extern char **environ;

	if ((name == NULL) || (value == NULL))
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
			if (overwrite == 0)
				return (0);
			new_value = _strcat(name, value);
			environ[i] = new_value;
			return (0);
		}
		i++;
	}
	len = _strlen(name) + _strlen(value) + 2;
	new_env = malloc(sizeof(char) * len);
	if (new_env == NULL)
		return (-1);
	while (name[k] != '\0')
	{
		new_env[k] = name[k];
		k++;
	}
	new_env[k] = '=';
	k++;
	j = 0;
	while (value[j] != '\0')
	{
		new_env[k] = value[j];
		k++;
		j++;
	}
	new_env[k] = '\0';
	environ[i] = new_env;
	return (0);
}
