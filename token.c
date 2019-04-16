#include "shell.h"


size_t token_count(const char *line, const char *delim)
{
	size_t count;
	int index;

	count = 0;
	index = 0;

	while (line[index])
	{
		while(find_delim(line[index], delim))
			index++;
		if (line[index] == '\0')
		{
			break;
		}
		count++;
		while(!find_delim(line[index], delim) && line[index] != '\0')
			index++;
	}

	return (count);
}

char find_delim(const char c, const char *delim)
{
	unsigned char index;

	index = 0;

	while(delim[index])
	{
		if (delim[index] == c)
		{
			return (1);
		}
		index++;
	}
	return (0);
}

void tokenize_string(char **arrstr, char *line, const char *delim)
{

	char *token;
	size_t index;

	index = 0;

	/* first call of isolates sequential tokens based on delimeter and puts a NULL terminating byte at the end */
	/* first time strtok, string should be specified */
	token = strtok(line, delim);
	while (token)
	{
		/* tokenizes the very first string in the array of strings */
		arrstr[index] = token;
		index++;
		/* subsequent calls for obtaining the other tokens should pass a NULL pointer instead */
		token = strtok(NULL, delim);
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


char **tokenize (char *line, const char *delim)
{
        size_t n;
        char **arrstr;

	/* function that counts the tokens from user input */
        n = token_count(line, delim);
	if (n == 0)
		return (NULL);
	/* allocate memory for array of strings from user input */
        arrstr = malloc(sizeof(*arrstr) * (n + 1));
	if (arrstr ==  NULL)
	{
		_strprnt("malloc failed");
		exit(EXIT_FAILURE);
	}
	/* TODO: check for if malloc fails with NULL case */
	/* function that uses strtok to split the getline into different tokens based on delimeter and fills the allocated array with those tokens */
	tokenize_string(arrstr, line, delim);
 
       
	return (arrstr);
}
