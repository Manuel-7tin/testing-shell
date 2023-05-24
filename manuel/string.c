#include "shell.h"

/**
* _strcpy - custom strcpy function
*
* @dest: destination of copied string
* @src: pointer to src string
*
* Return: pointer to dest
*/
char *_strcpy(char *dest, const char *src)
{
	char *p = dest;

	while
		((*p++ = *src++) != '\0');
	return (dest);
}

/**
 * _strcat - Concatenates two inputted strings
 *
 * @string1: The string to be appended to
 * @addition: The string to append
 * @final_string: The result of the concatenated strings
 *
 * Return: (0 on success, -1 on failure
 */

int _strcat(char *string1, char *addition, char *final_string)
{
	char *ptr;

	if (string1 == NULL || final_string == NULL)
		return (-1);
	ptr = final_string;
	while (*string1 != '\0')
	{
		*ptr = *string1;
		ptr++;
		string1++;
	}
	while (*addition != '\0')
	{
		*ptr = *addition;
		ptr++;
		addition++;
	}
	*ptr = '\0';
	return (0);
}

/**
 * get_cmd - Gets the users command
 *
 * @string: The string to extract the command from
 *
 * Return: int 0 on success, -1 on failure
 */

int get_cmd(char *string, char *cmd)
{
	char *token = NULL, *words = NULL;

	if (string == NULL)
		return (-1);
	words = malloc(50 * sizeof(char));
	if (words == NULL)
		return (-1);
	_strcpy(words, string);
	token = strtok(words, " ");
	if (token == NULL)
	{
		free(words);
		return (-1);
	}
	_strcpy(cmd, token);
	free(words);
	return (0);
}
/**
 * _strlen - Returns length of a string
 * @str: A pointer to a char string
 * Return: length
 */

size_t _strlen(const char *str)
{
	const char *ptr;

	if (str == NULL)
	{
		return (0);
	}
	ptr = str;
	while (*ptr != '\0')
	{
		ptr++;
	}
	return ((size_t)(ptr - str));

}
/**
 * __strcat - Custom strcat function
 * @dest: destination string
 * @src: source string
 * return: dest
 */
char *__strcat(char *dest, const char *src)
{
	char *ptr = dest;

	if (dest == NULL || src == NULL)
	{
		return (dest);
	}
	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';

	return (dest);
}
