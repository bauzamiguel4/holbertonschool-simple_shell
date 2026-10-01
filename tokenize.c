#include "shell.h"

/**
 * tokenize - splits a string into tokens
 * @line: string to split
 *
 * Return: array of pointers to tokens
 */
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 128);
	if (!tokens)
		return (NULL);

	token = strtok(line, " \n\t\r");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \n\t\r");
	}
	tokens[i] = NULL;

	return (tokens);
}
