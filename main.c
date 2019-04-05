#include "shell.h"

int main ()
{
	char *line;
	char **arrstr;
	size_t size;

	while (1)
	{
		/* TODO: fork process */

		line = NULL;
		size = 0;


		/* prints prompt */		
		_strprnt("$ ");
		/* gets line from user input stores it into a char * */
		getline(&line, &size, stdin);

		/* function that tokenizes the user input into seperate tokens seperated by a NULL terminating byte */
		arrstr = tokenize(line);

		/* test */
		_strprnt(line);
		_strprnt("\n");


		/* free line and arrstr */
		free(line);
		free(arrstr);
	}

	return (EXIT_SUCCESS);
}
