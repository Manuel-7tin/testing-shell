#include "shell.h"

/**
 * str_to_arr - This function converts a string to an array of strings
 *
 * @str: The string to b e converted
 * @brk: The break character
 *
 * Return: A null terminated array of strings
 */

char **str_to_arr(char *str, char *brk)
{
	int j, i = 0;
	char *word, **array;

	word = strtok(str, brk);
	array = malloc(150 * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (word)
	{
		array[i] = malloc(200 * sizeof(char));
		if (array[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(array[j]);
			return (NULL);
		}
		cpystr(array[i], word);
		word = strtok(NULL, brk);
		i++;
	}
	array[i] = NULL;
	return (array);
}

/**
 * cpystr  - Copies strings
 *
 * @str1: The string to be copied into
 * @str2: THe string to br copied
 *
 * Return: int
 */
int cpystr(char *str1, char *str2)
{
	int i;

	for (i = 0; str2[i]; i++)
		str1[i] = str2[i];
	str1[i] = '\0';
	return (0);
}
