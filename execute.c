#include "shell.h"

/**
* run_cmd - a function that creates a child process to execute binary
* @path: a pointer to tokenized path
* @argv: a pointer to the argument array by user
* @env: a pointer to the enivornment of the user
*
* Return: Status on sucess, -1 on failure
*/

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

/**
* exec_cmd - a function that runs a command based on if it is a builtin,
* absolute path or a appended path
* @argv: a pointer to the argument array by user
* @env: a pointer to the environment of the user
*
* Return: the function run_cmd on success, 127 when a file cannot be found
*/

int exec_cmd(char **argv, char **env)
{
	char *path = argv[0];

	if (_strcmp(path, "exit") == 0)
	{
		free(argv);
		exit(1);
	}

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
