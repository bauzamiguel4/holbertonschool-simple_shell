#include "shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @name: character string name of environment variable to match
 *
 * Return: pointer to starting position of value string, or NULL
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ && environ[i])
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}

/**
 * get_location - resolves full absolute path of binary command from PATH
 * @command: string name or relative path of executable command
 *
 * Return: dynamically allocated full path string, or NULL if not found
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	if (!command)
		return (NULL);

	if (strchr(command, '/'))
	{
		if (stat(command, &buffer) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = _getenv("PATH");
	if (!path || *path == '\0')
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	cmd_len = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		dir_len = strlen(path_token);
		file_path = malloc(cmd_len + dir_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
} 
