#include "shell.h"

/**
* main - entry point of the program
* @ac: unused
* @av: unused
* @env: a pointer to the user environment
*
* Return: status of the program
*/

int main(int ac, char **av, char **env)
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
		if (isatty(STDIN_FILENO) == 1)
			_strprnt("$ ");

		/* gets line from user input stores it into a char * */
		getline(&line, &size, stdin);

		/* function that tokenizes the user input into seperate tokens */
		/* seperated by a NULL terminating byte */
		args = tokenize(line, " \n\t");

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

