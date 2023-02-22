#include "main.h"
/**
 * _cd - changes the current directoru
 * @args: arguments
 * Return: 0
 */
int _cd(char **args)
{
	char *home = NULL, *oldpwd = NULL, *pwd = NULL, *newpwd = NULL, *newoldpwd = NULL, *newpwd_value = NULL, *newoldpwd_value = NULL, *cwd = NULL;
	int i = 0, j = 0, len = 0;

	if (args[1] == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
			return (-1);
		if (chdir(home) != 0)
			return (-1);
		/*Update PWD Environment variable*/
		pwd = getenv("PWD");
		if (pwd == NULL)
			return (-1);
		newpwd = _strcat("PWD=", pwd);
		if (newpwd == NULL)
			return (-1);
		_setenv("PWD", newpwd, 1);
		/*Update OLDPWD environment variable*/
		oldpwd = getenv("OLDPWD");
		if (oldpwd == NULL)
			return (-1);
		newoldpwd = _strcat("OLDPWD=", oldpwd);
		if (newoldpwd == NULL)
			return (-1);
		_setenv("OLDPWD", newoldpwd, 1);
		return (0);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			return (-1);
		}
		/*Update PWD environment variable*/
		cwd = getcwd(NULL, 0);
		if (cwd == NULL)
			return (-1);
		len = _strlen(cwd) + 5;
		/*extra 5 are for /PWD\0*/
		newpwd_value = malloc(sizeof(char) * len);
		if (newpwd_value == NULL)
			return (-1);
		while (cwd[i] != '\0')
		{
			newpwd_value[i] = cwd[i];
			i++;
		}
		newpwd_value[i] = '/';
		i++;
		newpwd_value[i] = 'P';
		i++;
		newpwd_value[i] = 'W';
		i++;
		newpwd_value[i] = 'D';
		i++;
		newpwd_value[i] = '\0';
		_setenv("PWD", newpwd_value, 1);
		oldpwd = getenv("OLDPWD");
		if (oldpwd == NULL)
			return (-1);
		len = _strlen(oldpwd) + 8;
		newoldpwd_value = malloc(sizeof(char) * len);
		if (newoldpwd_value == NULL)
			return (-1);
		while (oldpwd[j] != '\0')
		{
			newoldpwd_value[j] = oldpwd[j];
			j++;
		}
		newoldpwd_value[j] = '/';
		j++;
		newoldpwd_value[j] = 'O';
		j++;
		newoldpwd_value[j] = 'L';
		j++;
		newoldpwd_value[j] = 'D';
		j++;
		newoldpwd_value[j] = 'P';
		j++;
		newoldpwd_value[j] = 'W';
		j++;
		newoldpwd_value[j] = 'D';
		j++;
		newoldpwd_value[j] = '\0';
		_setenv("OLDPWD", newoldpwd_value, 1);
		return (0);
	}
}
