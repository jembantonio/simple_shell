#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct cmd
{
	char **args;
	int (*f)(char **args);
} builtin_cmd;


int _strprnt (char *str);
int _strlen (const char *str);
char **tokenize (char *line);
char find_delim(const char c);
size_t token_count(const char *line);
int exec_cmd(char **argv, char **envp);
int _strcmp(char *s1, const char *s2, int n);
void _strcpy(char *dest, const char *src, size_t n);
char *_strdup(const char *s);

// Functions added 
int builtin_struct(char **args, int *status);
void exit_builtin(char **argv);
void env_builtin();


#endif
