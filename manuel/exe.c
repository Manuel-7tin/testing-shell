#include "shell.h"

/**
 * ex_string - Executes a given comand
 *
 * @env: Environmental variable
 * @string: a string of the command and it's arguments
 *
 * Return: void
 */

void ex_string(char **env, char *string)
{
	int i, status, args_count = 0;
	char **args = malloc(MAX_STRING_LEN * sizeof(char *));
	char *path, *token;
	pid_t pids;

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
		token = strtok(NULL, " ");
	}
	args[args_count] = NULL;
	pids = fork();
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
