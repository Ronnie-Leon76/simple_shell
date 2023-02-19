#include "main.h"
/**
 * main - UNIX command line interpreter
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *prompt = "#cisfun$";
	char *line = NULL, *line_copy = NULL;
	char *token = NULL;
	size_t len = 0;
	ssize_t read;
	const char *delim = " ";
	int num_tokens = 0;
	int i;
	
	(void)argc;
	while (1)
	{
		printf("%s ", prompt);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			printf("\n");
			exit(0);
		}
		line[read - 1] = '\0';
		line_copy = malloc(sizeof(char *) * read);
		if (line_copy == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
		strcpy(line_copy, line);
		token = strtok(line, delim);
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		/**
		if (command_exists(argv[0]))
		{
			pid = fork();
			if (pid == 0)
			{
				exec(argv);
				exit(127);
			} else
			{
				printf("%s: command not found\n", argv[0]);
			}
		}
		**/
		if (fork() == 0)
		{
			exec(argv);
			exit(127);
		}
		wait(NULL);
	}

	free(line_copy);
	free(line);

	return (0);
}
