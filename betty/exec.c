#include "shell.h"

/**
 * exec - executes a command
 *
 * @array: A null terminated array of strings
 * @env: A null terminated array of environment variables
 * @filename: A string of the file name
 *
 * Return: int
 */

int exec(char **array, char **env, char *filename)
{
	int i, n, j;
	char **paths, *command = array[0], full_path[40];
	struct stat file_stat;

	paths = path_gen(env);
	if (paths == NULL)
	{
		write(STDERR_FILENO, "PATH environment variable not found.\n", 37);
		return (-1);
	}
	for (i = 0; paths[i] != NULL; i++)
	{
		for (j = 0; paths[i][j]; j++)
			full_path[j] = paths[i][j];
		full_path[j++] = '/';
		for (n = 0; command[n]; n++)
			full_path[j++] = command[n];
		full_path[j] = '\0';
		if (stat(full_path, &file_stat) == 0)
			break;
	}
	printf("%s", full_path);
	if (execve(full_path, array, NULL) == -1)
	{
		perror(filename);
		return (-1);
	}
	return (0);
}
