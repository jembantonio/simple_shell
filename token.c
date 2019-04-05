#include "shell.h"

#define DELIM " \t\n"


char **tokenize (char *line)
{
	size_t n;

	n = token_count(line);
	printf("n = %ld\n", n);
	return (NULL);
}


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
