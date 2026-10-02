#include "shell.h"

/**
 * check_builtin - checks if command is a built-in
 * @args: arguments array
 * @line: original input line
 * @status: current exit status
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int check_builtin(char **args, char *line, int status)
{
	int i = 0;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(status);
	}
	if (strcmp(args[0], "env") == 0)
	{
		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
		free(args);
		return (1);
	}
	return (0);
} 
 