#include "shell.h"

#define DELIM " \t\n"

size_t token_count(const char *line)
{
	size_t count;
	int index;

	count = 0;
	index = 0;

	while (line[index])
	{
		while(find_delim(line[index]))
			index++;
		if (line[index] == '\0')
			break;
		count++;
		while(!find_delim(line[index]))
			index++;
	}

	return (count);
}

char find_delim(const char c)
{
	unsigned char index;

	index = 0;

	while(DELIM[index])
	{
		if (DELIM[index] == c)
			return (1);
		index++;
	}
	return (0);
}

void tokenize_string(char **arrstr, char *line)
{
	char *token;
	size_t index;

	index = 0;
	token = strtok(line, DELIM);
	while (token)
	{
		arrstr[index] = token;
		index++;
		token = strtok(NULL, DELIM);
	}
	arrstr[index] = NULL;
}

void print_tokenizestr(char **arrstr)
{
	size_t index;

	index = 0;
	while (arrstr[index] != NULL)
	{
		_strprnt(arrstr[index]);
		_strprnt("\n");
		index++;
	}
}

char **tokenize (char *line)
{
        size_t n;
        char **arrstr;

        n = token_count(line);
        arrstr = malloc(sizeof(*arrstr) * (n + 1));
        /* check for if malloc fails with NULL case */
	tokenize_string(arrstr, line);
        printf("n = %ld\n", n);
        print_tokenizestr(arrstr);
        return (NULL);
}
