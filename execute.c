#include "shell.h"

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
	char *path = argv[0];

	if (_strcmp(path, "exit") == 0)
		exit (1);


	if (path[0] == '/' || path[0] == '.')
	{
		if (access(path, X_OK) == 0)
		{
			return (run_cmd(path, argv, env));
		}
		_strprnt("no such file or directory\n");
		return (127);
	}

	path = find_cmd(argv[0], env);
	if (!path)
	{
		_strprnt("no such file or directory\n");
		return (127);
	}
	return (run_cmd(path, argv, env));
}
