#include "shell.h"


/* char *parse_path(char *envp)
{
	int i;
	int count = 0;
	char **envp;
	char *env = _getenv(envp, "PATH=");
	char *directory;

	for (i = 0; env[i]; i++)
	{
		if (env[i] == ':')
			count++;
	}
	count += 2;

	envp = malloc(count * sizeof(void *));
	
	if (!envp)
		return (NULL);
	
	directory = strtok(env, ":");

	for (i = 0; i < count; i++)
	{
		envp[i] = _strdup (directory);
		directory = strtok(NULL, ":");
	}
	envp[i] = NULL;
} */

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

char *find_cmd(char *cmd, char **env)
{
	char *path = NULL;
	char *env_path;

	env_path = _getenv(env, "PATH=");
	if (!env_path)
		return (NULL);
	
	printf("PATH => %s", env_path);	
	parse_path(env_path);
	free(env_path);
	(void)cmd;
	return (path);
}