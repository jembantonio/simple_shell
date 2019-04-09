include "shell.h"

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


int run_cmd(const char *path, char **argv, char **env)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	/* child */
	if (pid == 0)
	{
		execve(path, argv, env);
	}

	/* parent */
	else
	{
		wait(&status);
		status = WEXITSTATUS(status);
		return (status);
	}

	return (-1);
}

int exec_cmd(char **argv, char **env)
{
	const char *path = argv[0];

	if (path[0] == '/' || path[0] == '.')
	{
		if (access(path, X_OK) == 0)
		{
			return (run_cmd(path, argv, env));
		}
		_strprnt("no such file or directory\n");
		return (-1);
	}

	path = find_path(argv[0], env);
	if (!path)
	{
		_strprnt("no such file or directory\n");
		return (-1);
	}
	return (0);
}
