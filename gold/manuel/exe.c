#include "shell.h"

void ex_string(char **env, char *string)
{
	int i, status, args_count = 0;
	char **args = malloc(4 * sizeof(char *));
	char *path, *token;
	pid_t pids = fork();

	path = malloc(30 * sizeof(char));
	if (args == NULL || path == NULL)
	{
		free(args);
		free(path);
		return;
	}
	token = strtok(string, " ");
	while (token != NULL)
	{
		args[args_count++] = token;
		token = _strt(NULL, " ");
	}
	args[args_count] = NULL;

	if (pids < 0)
	{
		perror("fork");
		free(path);
		free(args);
		return;
	}
	else if (pids == 0)
	{
		i = locate_path(env, path, args[0]);
		if (i == -3)
		{
			perror("./hsh");
			free(path);
			free(args);
			exit(EXIT_FAILURE);
		}
		execve(path, args, env);
		perror("execve");
		free(path);
		free(args);
		return;
	}
	else
	{
		waitpid(pids, &status, 0);
		if ((WTERMSIG(status)))
		{
			free(path);
			free(args);
			return;
		}
	}
	free(path);
	free(args);
}
