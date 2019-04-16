#include "shell.h"

/**
* _strprnt - a function that uses write to print an entire string
* @str: a pointer to the string to print
*
* Return: size bytes of the string to print
*/

int _strprnt(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}
