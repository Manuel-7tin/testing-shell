#include "shell.h"

/**
 * path_gen - Generates the pathenvironment
 *
 * @env: An array of strings of environment
 *
 * Return: An array of strings of paths
 */

char **path_gen(char **env)
{
	int i, j;
	char *path, **path_arr, *path_env;

	path_arr = malloc(100 * sizeof(char *));
	for (i = 0; env[i] != NULL; i++)
	{
		if (strcp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		}
	}
	if (path_env == NULL)
		return (NULL);
	path = strtok(path_env, ":");
	i = 0;
	while (path != NULL)
	{
		path_arr[i] = malloc(30 * sizeof(char));
		if (path_arr[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(path_arr[j]);
			return (NULL);
		}
		path_arr[i] = path;
		path = strtok(NULL, ":");
		i++;
	}
	path_arr[i] = NULL;
	return (path_arr);
}

/**
 * strcp - Compares strings
 *
 * @envr: AN environment string
 * @word: String ti be compared
 * @len: number of chars
 *
 * Return: 0 if successful -1 if not
 */

int strcp(char *envr, char *word, int len)
{
	int i, num = 0;

	for (i = 0; i < len && envr[i] && word[i]; i++)
	{
		if (envr[i] == word[i])
			num++;
	}
	if (num == len)
		return (0);
	return (-1);
}
