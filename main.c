#include "shell.h"

int main ()
{
	char *line;
	char **arrstr;
	size_t size;

	while (1)
	{
		/* TODO: fork process  */

		line = NULL;
		size = 0;
		pid_t child = fork();
		int i = 0;


		/* prints prompt */		
		_strprnt("$ ");
		/* gets line from user input stores it into a char * */
		getline(&line, &size, stdin);
	
		/* Fork process goes here */
		if (child == 0)
		{
			/* tokenize the stdin */
			
			token_count(line);
			printf("i am child");


		}
		else
		{
			_strprnt("$ ");
			wait (NULL);
		}
		
		

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
