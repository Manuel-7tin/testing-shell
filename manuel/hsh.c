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
		char *string = NULL, *cmd;
		int m;

		print_prompt();
		m = readline(&string, stdin);
		if (m == -1)
			return (1);
		/**if (string == NULL)
			return (1);**/
		if (str_cmp(strtok(string, "\n"), "exit", 4) == 0)
			return (0);
		cmd = malloc(30 * sizeof(char));
		m = locate_path(env, cmd, strtok(string, " "));
		if (m == 0)
			ex_string(env, string);
		free(cmd);
		free(string);
	}
}
