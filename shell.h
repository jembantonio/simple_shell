#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int _strprnt (char *str);
int _strlen (const char *str);
int _printstring (char *str);
char **tokenize (char *line);
char find_delim(const char c);
size_t token_count(const char *line);
void print_tokenizestr(char **arrstr);

#endif
