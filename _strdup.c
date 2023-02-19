#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string
 *
 * Return: pointer to the duplicated string, or NULL if str = NULL
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
