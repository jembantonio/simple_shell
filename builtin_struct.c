#include "shell.h"

int (*builtin_struct(char *cmd))(char *str)
{
        cmd_struct array[] = {
		{"exit", exit_builtin},
		{"env", get_path}, //Jeremy is going to create this function
		{"0", NULL}
	};

	int c = 0;

	while (array[c].var)
	{
		if (array[c].var == cmd)
		{
			return (array[c].f);
		}
		c++;
	}
	return (NULL);
}