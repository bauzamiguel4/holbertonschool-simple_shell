#include "shell.h"

/**
 * execute - executes a command
 * @args: array of arguments
 * @argv: array of arguments from main
 *
 * Return: exit status
 */
int execute(char **args, char **argv)
{
	pid_t pid;
	int status;
	char *command_path;

	command_path = get_location(args[0]);
	if (command_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		return (127);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
			perror(argv[0]);
		exit(127);
	}
	else if (pid < 0)
	{
		perror(argv[0]);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	if (command_path != args[0])
		free(command_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (status);
}
