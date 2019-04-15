#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int _strprnt (char *str);
int _strlen (const char *str);
char **tokenize (char *line, const char *delim);
char find_delim(const char c, const char *delim);
size_t token_count(const char *line, const char *delim);
int exec_cmd(char **argv, char **envp);
int _strcmp(char *s1, const char *s2, int n);
void _strcpy(char *dest, const char *src, size_t n);
char *_strdup(const char *s);
char *_getenv(char **env, char *key);
char *find_cmd(char *cmd, char **env);
void print_tokenizestr(char **arrstr);
int _strcmp(char *s1, char *s2);

#endif
