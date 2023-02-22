#include "main.h"
/**
 * getline - reads the number of bytes read
 * @lineptr: pointer to memory where buffer data will be stored
 * @n: size of the buffer
 * @stream: input stream file
 * Return: number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *buffer;
	static int i = 0, bytes_read;
	int j = 0;

	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char) * 1024);
		if (buffer == NULL)
			return (-1);
	}
	if (n == NULL)
	{
		n = malloc(sizeof(size_t));
		if (n == NULL)
			return (-1);
	}
	if (stream == NULL)
	{
		if (bytes_read == 0)
		{
			bytes_read = read(STDIN_FILENO, buffer, 1024);
			if (bytes_read == -1)
				return (-1);
		}
		if (bytes_read == 0)
			return (0);
		*lineptr = malloc(sizeof(char) * 1024);
		if (*lineptr == NULL)
			return (-1);
		while (bytes_read != 0)
		{
			while (buffer[i] != ' ')
			{
				(*lineptr)[j] = buffer[i];
				i++;
				j++;
			}
			(*lineptr)[j] = '\0';
			if (buffer[i] == ' ')
				break;
		}
	}
	return ((ssize_t)bytes_read);
}
