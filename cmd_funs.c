#include "shell.h"

int (*cmd_funs(char *cmd))(char *str)
{
        cmd_struct array[] = {
		{"exit", print_char}, //TO-DO , need to ask Jeremy which function for exit
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