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
		tokenize(line);
	}

	return (EXIT_SUCCESS);
}
