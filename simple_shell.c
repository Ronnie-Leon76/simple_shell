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
	/* char *args[] = {NULL}; */
	/* char *envp[] = {NULL}; */
	
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
		argv = malloc(sizeof(char *) * 1);
		argv[0] = malloc(sizeof(char) * strlen(line));
		strcpy(argv[0], line);
		if (fork() == 0)
		{
			char *command = argv[0];
			if (execve(command, argv, NULL) == -1)
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
