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


		/* checks for non-interactive, then prints prompt */
		if (isatty(STDIN_FILENO) == 1)
			_strprnt("$ ");

		/* gets line from user input OR Ctrl -D * */
		if (getline(&line, &size, stdin) == EOF)
		{
			if (isatty(0) == 1)
				_strprnt("\n");
			break;
		}

		/* function that tokenizes the user input into seperate tokens */
		args = tokenize(line, " \n\t");

		if (args != NULL)
		{
			status = exec_cmd(args, env);
		}
		/* frees both strings line and arrstr */
		free(line);
		free(args);
	}
	(void)ac;
	(void)av;
	return (status);
}

