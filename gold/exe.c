#include "shell.h"
char **environ;
void ex_string(char *string)
{
	int status, args_count = 0;
	char **args = malloc(4 * sizeof(char *));
	char *path, *token;
	/* path points to the string of the command path that your fing_path() function will return*/
	pid_t pids = fork();

	/*splits the incoming string returned by getline()*/
	token = _strt(string, " ");
	while (token != NULL)
	{
		args[args_count++] = token;
		token = _strt(NULL, " ");
	}
	args[args_count] = NULL;

	if (pids < 0)
	{
		perror("fork");
		free(args);
		return;
	}
	else if (pids == 0)
	{
		path = find_path(args[0]);
		/*calls find_path function, finds the path of the command and store it in path*/
		if (path == NULL)
		{
			perror("./hsh");
			free(args);
			exit(EXIT_FAILURE);
		}
		excve(path, args, environ);
		perror("execve");
		free(args);
		return;
	}
	else
	{
		waitpid(pids, &status, 0);
		if ((WTERMSIG(stats)))
		{
			free(args);
			return;
		}
	}
	free(args);
}
