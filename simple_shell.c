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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *args[] = {NULL};
	char *envp[] = {NULL};
	
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
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			printf("\n");
			exit(0);
		}
		if (fork() == 0)
		{
			if (execve(line, args, envp) == -1)
			{
				dprintf(STDERR_FILENO, "%s: No such file or directory \n", argv[0]);
				free(line);
				exit(127);
			}
		}
		wait(NULL);
	}
	return (0);
}
