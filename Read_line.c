#include "shell.h"



int main ()
{
        /* buffer */
        char *buffer;
        /*size of buffer */
        size_t *n = 1024;

        char *commands;

        _printstring("$ ");
        /* getline(char **lineptr, size_t *n, FILE *stream) */
        /* getline(&buffer,&size,stdin) */
        commands = getline(&buffer,&n,stdin);
        _printstring(commands);

}

int _strlen(const char *str)
{
        unsigned int len;
        len = 0;
        while (str[len])
                len++;
        return (len);
}

int _printstring (char *str)
{
        return (write(1, str, _strlen(str)));
}