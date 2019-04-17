#include "shell.h"

/**
* token_count - a function that counts the number of tokens from getline
* @line: a pointer to the string from getline
* @delim: a pointer to the delimiter string to seperate each token by
*
* Return: the amount of tokens
*/

size_t token_count(const char *line, const char *delim)
{
	size_t count;
	int index;

	count = 0;
	index = 0;

	while (line[index])
	{
		while (find_delim(line[index], delim))
			index++;
		if (line[index] == '\0')
		{
			break;
		}
		count++;
		while (!find_delim(line[index], delim) && line[index] != '\0')
			index++;
	}

	return (count);
}

/**
* find_delim - a function that checks for each delimeter in the string
* @c: the character to compare to if it is a matching delimeter
* @delim: a pointer to a string list of delimeters
*
* Return: 1 if c is a delimeter, 0 if c is not a delimeter
*/

char find_delim(const char c, const char *delim)
{
	unsigned char index;

	index = 0;

	while (delim[index])
	{
		if (delim[index] == c)
		{
			return (1);
		}
		index++;
	}
	return (0);
}

/**
* tokenize_string - a function that tokenizes a given string by a delimeter
* @arrstr: a pointer to an array that will hold the tokenized strings
* @line: a pointer to the string to be tokenized
* @delim: a pointer to the delimeter to be used to seperate
*
* Return: void
*/

void tokenize_string(char **arrstr, char *line, const char *delim)
{

	char *token;
	size_t index;

	index = 0;

	/* first call of isolates sequential tokens based on delimeter */
	/* puts a NULL terminating byte at the end */
	/* first time strtok, string should be specified */
	token = strtok(line, delim);
	while (token)
	{
		/* tokenizes the very first string in the array of strings */
		arrstr[index] = token;
		index++;
		/* subsequent calls for obtaining the other tokens */
		/* should pass a NULL pointer instead */
		token = strtok(NULL, delim);
	}
	arrstr[index] = NULL;
}

/**
* tokenize - a function that allocates memory for a a given array.
* then, fills the array with tokens
* @line: line passed from getline to be tokenized
* @delim: a string of delimeters to seperate the string
*
* Return: an array of the tokenized strings
*/

char **tokenize(char *line, const char *delim)
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
	/* function that uses strtok to split the getline into different tokens */
	/* based on delimeter and fills the allocated array with those tokens */
	tokenize_string(arrstr, line, delim);

	return (arrstr);
}
