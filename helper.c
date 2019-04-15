#include "shell.h"

int _strprnt (char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}

int _strlen (const char *str)
{
	unsigned int len;

	len = 0;

	while (str[len])
		len++;

	return (len);
}

int _strcmp(char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		if (s1[i] == '\0' || s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);

}

void _strcpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;

	while (dest && src && i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

char *_strdup(const char *s)
{
	char *new;
	int len = _strlen(s);

	if (!s)
		return(NULL);

	new = malloc(_strlen(s) + 1);
	_strcpy(new, s, len);

	new[len] = 0;
	return (new);
}
