#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char **tokenize(char *line);
int execute(char **args, char **argv);
char *get_location(char *command);
char *_getenv(const char *name);
int check_builtin(char **args, char *line, int status);

#endif /* SHELL_H */
