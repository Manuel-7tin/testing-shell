#include "shell.h"

/**
 * str_cmp - Compares strings
 *
 * @str1: string 1 to compare with
 * @str2: String ti be compared
 * @len: number of chars
 *
 * Return: 0 if successful -1 if not
 */

int str_cmp(char *str1, char *str2, size_t len)
{
	size_t i, sum = 0;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	if (strlen(str1) < len || strlen(str2) < len)
		return (-1);
	for (i = 0; i < len; i++)
	{
		if (str1[i] == str2[i])
			sum++;
	}
	if (sum == len)
		return (0);
	return (-1);
}

/**
 * path_gen - Generates the pathenvironment
 *
 * @env: An array of strings of environment variables
 * @path_arr: An array to stotre th paths
 *
 * Return: nuber of paths if successful, -1 if not
 */

int path_gen(char **env, char **path_arr)
{
	int i, n;
	char *paths, *path;
	size_t m;

	paths = malloc(70 * sizeof(char));
	if (env == NULL || path_arr == NULL || paths == NULL)
		return (-1);
	for (i = 0; env[i]; i++)
	{
		n = str_cmp(env[i], "PATH", 4);
		if (n == 0)
		{
			_strcpy(paths, env[i] + 5);
			break;
		}
	}
	if (n == -1)
		return (-1);
	if (paths == NULL)
		return (-1);
	path = strtok(paths, ":");
	for (n = 0; path; n++)
	{
		_strcpy(path_arr[n], path);
		m = strlen(path_arr[n]);
		path_arr[n][m++] = '/';
		path_arr[n][m] = '\0';
		path = strtok(NULL, ":");
	}
	free(paths);
	return (n);
}

/**
 * locate_path - LOcates the path to a particular command
 *
 * @env: An array of strings of environment variables
 * @cmd_path: A pointer to a loation to store the path
 * @cmd: The command
 *
 * Return: (int): 0 if successful, -1 if not, -3 if path can't be located
 */

int locate_path(char **env, char *cmd_path, char *cmd)
{
	int i, n, num_of_path;
	char **path_arr, *temp_path;
	struct stat file_stat;

	path_arr = malloc(MAX_PATHS * sizeof(char *));
	if (path_arr == NULL)
		return (-1);
	for (i = 0; i < MAX_PATHS; i++)
	{
		path_arr[i] = malloc(20 * sizeof(char));
		if (path_arr[i] == NULL)
		{
			for (; i >= 0; i--)
				free(path_arr[i]);
			free(path_arr);
			return (-1);
		}
	}
	num_of_path = path_gen(env, path_arr);
	if (num_of_path == -1)
	{
		for (i = 0; i < MAX_PATHS; i++)
			free(path_arr[i]);
		free(path_arr);
		return (-1);
	}
	for (i = 0; i < num_of_path; i++)
	{
		temp_path = malloc(30 * sizeof(char));
		n = _strcat(path_arr[i], cmd, temp_path);
		if (n == -1)
		{
			for (i = 0; i < MAX_PATHS; i++)
				free(path_arr[i]);
			free(path_arr);
			free(temp_path);
			return (-1);
		}
		n = stat(temp_path, &file_stat);
		if (n == 0)
			break;
		else
			free(temp_path);
	}
	for (i = 0; i < MAX_PATHS; i++)
		free(path_arr[i]);
	free(path_arr);
	if (n == -1)
		return (-3);
	_strcpy(cmd_path, temp_path);
	free(temp_path);
	return (0);
}
