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
	while (1)
	{
		char *string = NULL, *cmd, *token;
		int m;

		print_prompt();
		m = readline(&string, stdin);
		if (m == -1)
			return (1);
		token = strtok(string, "\n");
		if (str_cmp(token, "exit", 4) == 0)
			return (0);
		cmd = malloc(30 * sizeof(char));
		printf("string is %s", string);
		m = locate_path(env, cmd, token);
		printf("How many times outside\n");
		if (m == 0)
		{
			printf("how many times");
			printf("God abeg");
			ex_string(env, string);
			printf("for god's sake\n");
		}
		free(cmd);
		free(string);
	}
}
