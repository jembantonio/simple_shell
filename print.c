#include "shell.h"

int _strprnt (char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}
