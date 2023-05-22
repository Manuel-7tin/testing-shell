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

	char_num = getline(str, &input_size, stream);
	if (str == NULL)
		return (-5);
	*str = strtok(*str, "\n");
	return (char_num);
}
