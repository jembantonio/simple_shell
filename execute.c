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
		return (status);
	}

	return (-1);
}

int exec_cmd(char **argv, char **env)
{
	const char *cmd = argv[0];

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
		{
			return (run_cmd(cmd, argv, env));
		}
	}
	return (-1);
}

