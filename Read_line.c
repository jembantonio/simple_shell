#include "shell.h"



int main ()
{
        /* line_cmd */
        char *line_cmd;
        /*size of line_cmd */
        size_t n;


        _printstring("$ ");
        /* getline(char **lineptr, size_t *n, FILE *stream) */
        /* getline(&line_cmd,&size,stdin) */
        getline(&line_cmd,&n,stdin);
        _printstring(line_cmd);

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