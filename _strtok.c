#include "main.h"
/**
 * _strtok - tokenize a string
 * @str: string to tokenize
 * @delim: delimiter
 *
 * Return: token
 */
char *_strtok(char *str, char *delim)
{
	static char *last;
	char *token;
	int i = 0, j = 0;

	if (str == NULL)
		str = last;
	while (str[i] != '\0')
	{
		while (delim[j] != '\0')
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';
				token = str;
				last = str + i + 1;
				return (token);
			}
			j++;
		}
		j = 0;
		i++;
	}
	last = NULL;
	return (str);
}
