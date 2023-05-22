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
		char *string = NULL, *cmd = NULL, *unknown_cmd = NULL;
		int n, m = -1;

		print_prompt();
		/*string = malloc(30);*/
		n = readline(&string, stdin);
		if (n == -1)
		{
			free(string);
			return (1);
		}
		if (str_cmp(string, "exit", 4) == 0)
		{
			free(string);
			return (0);
		}
		cmd = malloc(30 * sizeof(char));
		unknown_cmd = malloc(20 * sizeof(char));
		n = get_cmd(string, unknown_cmd);
		if (n == 0)
			m = locate_path(env, cmd, unknown_cmd);
		if (m == 0)
			ex_string(env, string);
		free(string);
		free(cmd);
		free(unknown_cmd);
	}
}
