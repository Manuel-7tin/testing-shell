#include "shell.h"

/**
 * ex_string - Executes a given comand
 *
 * @env: Environmental variable
 * @string: a string of the command and it's arguments
 *
 * Return: void
 */

void ex_string(char **env, char *string, int* command_count)
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



    if (strcmp(args[0], "cd") == 0)
    {
        // Handle 'cd' command
        change_directory(args[1]);
        return;  // Return after executing the built-in command
    }

	token = _strt(string, " ");
	while (token != NULL)
	{
		args[args_count++] = token;
		token = _strt(NULL, " ");
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
		i = locate_path(env, path, args[0], command_count);
		if (i == -1)
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
		exit(EXIT_FAILURE);
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
