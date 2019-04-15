#include "shell.h"

int (*builtin_struct(char *cmd))(char *str)
{
        cmd_struct array[] = {
		{"exit", exit_builtin},
		{"env", env_builtin}, //Jeremy is going to create this function
		{"0", NULL}
	};

	int c = 0;

	while (array[c].cmd)
	{
		if (array[c].cmd == cmd)
		{
			return (array[c].f);
		}
		c++;
	}
	return (NULL);
}