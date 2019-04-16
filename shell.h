#ifndef _SHELL_H_
#define _SHELL_H_


/* C LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* TOKENIZING FUNCTIONS */
char **tokenize(char *line, const char *delim);
char find_delim(const char c, const char *delim);
size_t token_count(const char *line, const char *delim);

/* EXECUTE COMMAND FUNCTIONS */
int exec_cmd(char **argv, char **envp);
char *_getenv(char **env, char *key);
char *find_cmd(char *cmd, char **env);

/* STRING FUNCTIONS */
int _strcmp(char *s1, char *s2);
char *_strdup(const char *s);
int _strncmp(char *s1, const char *s2, int n);
void _strcpy(char *dest, const char *src, size_t n);
int _strlen(const char *str);
int _strprnt(char *str);

#endif
