#include "shell.h"

int _strprnt (char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

int _strlen (const char *str)
{
	unsigned int len;

	len = 0;

	while (str[len])
		len++;

	return (len);
}


