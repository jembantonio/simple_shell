#include "shell.h"

char *_getenv(char **env, char *key)
{
	size_t i;

	for (i = 0; env && env[i]; i++)
	{
		if (_strncmp(env[i], key, _strlen(key)) == 0)

			return (_strdup(env[i] + _strlen(key)));
	}

	return (NULL);
}

static char *append_path(const char *dir, const char *file)
{
	char *path;
	size_t path_len;
	size_t dir_len = _strlen(dir);
	size_t file_len = _strlen(file);

	path_len = dir_len + 1 + file_len;
	path = malloc(path_len + 1);

	_strcpy(path, dir, dir_len);
	path[dir_len] = '/';
	_strcpy(path + dir_len + 1, file, file_len);
	path[path_len] = 0;

	return (path);
}

char *find_cmd(char *cmd, char **env)
{
	char *env_path = NULL;
	char **dirs = NULL;
	size_t index;
	char *path = NULL;

	env_path = _getenv(env, "PATH=");
	if (!env_path)
		return (NULL);
	
	dirs = tokenize(env_path, ":");
	
	for (index = 0; dirs && dirs[index]; index++)
	{
		char *curr_path;

		curr_path = append_path(dirs[index], cmd);
		if (access(curr_path, X_OK) == 0)
		{
			path = curr_path;
			break;
		}
		free(curr_path);
	}
	free(dirs);
	free(env_path);

	(void)cmd;
	return (path);
}
