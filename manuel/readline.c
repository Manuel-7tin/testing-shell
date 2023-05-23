#include "shell.h"

/**
 * print_prompt - Prints a prompt
 *
 * return: void
 */

void print_prompt(void)
{
	char *prompt = "$ ";

	write(STDOUT_FILENO, prompt, strlen(prompt));
}

/**
 * readline - reads a line from stdin
 *
 * @str: string to store read line in
 * @stream: The file to rad input frtom
 *
 * Return: int: number of read chars on success | -1 on failure
 */

int readline(char **str, FILE *stream)
{
	int char_num;
	size_t input_size;
	char *temp_str = NULL, *token = NULL;

	char_num = getline(&temp_str, &input_size, stream);
	if (temp_str == NULL)
		return (-5);
	if (char_num != -1)
		token = strtok(temp_str, "\n");
	if (token != NULL)
	{
		*str = malloc(30);
		_strcpy(*str, token);
	}
	free(temp_str);
	return (char_num);
}
