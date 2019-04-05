#include "shell.h"

int main ()
{
	char *line;
	size_t size;

	while (1)
	{
		/* fork process */
		_strprnt("$ ");

		line = NULL;
		size = 0;

		getline(&line, &size, stdin);
		tokenize(line);
		_strprnt(line);
		_strprnt("\n");
		free(line);
	}

	return (EXIT_SUCCESS);
}
