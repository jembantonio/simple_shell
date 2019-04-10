#include "shell.h"

char *_getenv(char **env, char *key)
{
	size_t i;

	for (i = 0; env && env[i]; i++)
	{
		if (_strcmp(env[i], key, _strlen(key)) == 0)

			return (_strdup(env[i] + _strlen(key)));
	}

	return (NULL);
}

char *find_path(char *cmd, char **env)
{
	char *path = NULL;
	char *env_path;

	env_path = _getenv(env, "PATH=");
	if (!env_path)
		return (NULL);

	free(env_path);
	(void)cmd;
	return (path);
}


