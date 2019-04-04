#include "shell.h"

int main ()
{
	char *line;
	size_t size;

	while (1)
	{
		_strprnt("$ ");
		getline(&line, &size, stdin);
		_strprnt(line);
	}

	return (EXIT_SUCCESS);
}

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