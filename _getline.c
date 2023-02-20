#include "main.h"
/**
 * getline - reads a line from stdin
 * Return: line
 */
char *_getline(void)
{
	char *line = NULL;
	char *buffer = NULL;
	int i = 0, j = 0, k = 0, read_size = 0, line_size = 0;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (NULL);
	read_size = read(STDIN_FILENO, buffer, 1024);
	if (read_size == -1)
		return (NULL);
	while (buffer[i] != ' ')
	{
		i++;
	}
	line_size = i;
	line = malloc(sizeof(char) * line_size);
	if (line == NULL)
		return (NULL);
	while (j < line_size)
	{
		line[j] = buffer[k];
		j++;
		k++;
	}
	free(buffer);
	return (line);
}
