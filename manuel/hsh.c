#include "shell.h"

/**
 * main - The main function of the shell program
 *
 * Description: This main function controls our basic shell program
 *
 * @argc: Argument count
 * @argv: Null terminuated array of arguments
 * @env: environment variables
 *
 * Return: int 0
 */

int main(int argc __attribute__((unused)),
		char **argv,
		char **env)
{
	char *string = NULL;
	int m;

	print_prompt();
	m = readline(&string, stdin);
	if (m == -1)
	{
		printf("error man");
		return (1);
	}
	if (string == NULL)
	{
		printf("ode");
		return (1);
	}
	printf("I guess it worked: : : YOu tyPeD %s\n", string);
	free(string);
	return (0);
}
