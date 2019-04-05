#include "shell.h"

/* 3 Steps of Shell */
/* load the configuration files */
/* run an REPL loop */
/* perform any shutdown cleanup */


int main (int argc, char ** argv)
{
        char *line_cmd;              /* line_cmd */
        size_t n;                    /*getline will auto allocate space (n) needed for line_cmd */

        while (1)
        {
                _printstring("$ ");
                getline(&line_cmd,&n,stdin); /* getline(char **lineptr, size_t *n, FILE *stream) */
                _printstring(line_cmd);
                /* token function goes here */
                /* execute(args); goes here */
        }

        return (EXIT_SUCCESS);

}

int _strlen(const char *str)
{
        unsigned int len;
        len = 0;
        while (str[len])
                len++;
        return (len);
}

/* converted vers of putchar(c), which prints a str instead */
int _printstring (char *str)
{
        return (write(1, str, _strlen(str)));
}