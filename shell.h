#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct path
{
	char *str; 
	struct path *next;
} get_path;

int _strprnt (char *str);
int _strlen (const char *str);
char **tokenize (char *line);
char find_delim(const char c);
size_t token_count(const char *line);
void print_tokenizestr(char **arrstr);
int exec_cmd(char **argv, char **envp);
#endif

