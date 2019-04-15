#include "shell.h"

// The struct 
int builtin_struct(char **args, int *status)
{
        builtin_cmd array[] = {
		{"exit", exit_builtin},
		{"env", env_builtin}, //Jeremy is going to create this function
		{"0", NULL}
	};

	int c = 0;

	while (array[c].args)
	{
		if (array[c].args == args)
		{
			return (array[c].f);
		}
		c++;
	}
	return (status);
}

/* //Function that that check if args is built-in
int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < args; i++) 
  {
    if (strcmp(args[0], array[i].args) == 0) 
    {
      return (array[i].f);
    }
  }

  return lsh_launch(args);
}
*/


// The buil-in functions
void exit_builtin(char **argv)
{
        exit(0);
}

void env_builtin(char **argv)
{
        _strprnt("env");
}
