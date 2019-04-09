#include "shell.h"

int main (int ac, char **av, char **env)
{
	char *line;
	char **args;
	size_t size;
	int status;

	while (1)
	{
		line = NULL;
		size = 0;


		/* prints prompt */
		_strprnt("$ ");
		/* gets line from user input stores it into a char * */

		getline(&line, &size, stdin);

		/* function that tokenizes the user input into seperate tokens
		seperated by a NULL terminating byte */
		args = tokenize(line);

		if (args != NULL)
		{
			status = exec_cmd(args, env);
		}
		/* free line and arrstr */
		free(line);
		free(args);
	}
	(void)ac;
	(void)av;
	return (status);
}

