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
 * @cmd: Location to store the command
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
	token = _strt(words, " ");
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
 * __strcat - custom strcat function
 * @dest: destination string
 * @src: source string
 * Return: Dest
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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int _strcmp(const char *str1, const char *str2);

/* Custom strtok function */
char *__strt(char *string, const char *deli, char **save_ptr)
{
    int i, j, found;
    char *word = NULL;

    if (string != NULL)
    {
        *save_ptr = string;
    }

    if (*save_ptr == NULL || **save_ptr == '\0')
    {
        return NULL;
    }

    // Skip leading spaces
    while (**save_ptr == ' ')
    {
        (*save_ptr)++;
    }

    word = *save_ptr;
    i = 0;
    found = 0;
    while (word[i] != '\0')
    {
        for (j = 0; deli[j] != '\0'; j++)
        {
            if (word[i] == deli[j])
            {
                word[i] = '\0';
                *save_ptr = &word[i + 1];
                found = 1;
                break;
            }
        }
        if (found)
        {
            break;
        }
        i++;
    }
    if (!found)
    {
        *save_ptr = NULL;
    }
    return word;
}

#include <stddef.h>

int __strcmp(const char *str1, const char *str2)
{
    if (str1 == NULL && str2 == NULL)
    {
        return 0;
    }
    else if (str1 == NULL)
    {
        return -1;
    }
    else if (str2 == NULL)
    {
        return 1;
    }

    for (size_t i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if (str1[i] < str2[i])
        {
            return -1;
        }
        else if (str1[i] > str2[i])
        {
            return 1;
        }
    }

    return 0;
}

