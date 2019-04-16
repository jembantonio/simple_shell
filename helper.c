#include "shell.h"

/**
* _strlen - a function that returns the length of a string
* @str: a pointer to the string to be counted
*
* Return: length of the string
*/

int _strlen(const char *str)
{
	unsigned int len;

	len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
* _strncmp - a function that compares two strings with the byte size "n" and
* returns the number of differences
* @s1: a pointer to the first string to compare
* @s2: a pointer to the second string to compare
* @n: the byte size of the string to compare
*
* Return: the difference of s1 and s2
*/

int _strncmp(char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; i < n; ++i)
		if (s1[i] == '\0' || s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);

}

/**
* _strcpy - a function that copies the string pointer to by src,
* including the terminating null byte to the buffer pointed to by dest
* @dest: destination to copy src
* @src: a pointer to the source string to be copied
* @n: size of string you want to copy
*
* Return: a pointer to the first character of dest
*/

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

/**
* _strdup - a function that returns a pointer to a newly allocated space in
* in memory, which contains a copy of the string being passed
* @s: a pointer to the string to be duplicated
*
* Return: NULL if str == NULL, a pointer to the new string on success
*/

char *_strdup(const char *s)
{
	char *new;
	int len = _strlen(s);

	if (!s)
		return (NULL);

	new = malloc(_strlen(s) + 1);
	_strcpy(new, s, len);

	new[len] = 0;
	return (new);
}


/**
* _strcmp - a function that compares two strings and return the number
* of difference
* @s1: a pointer to the first string to compare
* @s2: a pointer to the second string to compare
*
* Return: the difference of s1 and s2
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;

	return (s1[i] - s2[i]);
}
