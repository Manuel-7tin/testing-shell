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
