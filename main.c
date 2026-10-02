#include "shell.h"

/**
 * main - main loop of the simple shell
 * @ac: argument count (unused)
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 0;

	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(line);
			exit(status);
		}

		if (read > 0 && line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = tokenize(line);
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (check_builtin(args, line, status))
			continue;

		status = execute(args, argv);
		free(args);
	}
	return (status);
}
 