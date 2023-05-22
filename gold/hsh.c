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
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	int command_count = 1;

	signal(SIGINT, handle_signal);
	while (1)
	{
		char *string = NULL, *cmd, *token;
		int m;

		print_prompt();
		m = readline(&string, stdin);
		if (m == -1)
		{
			free(string);
			return (1);
		}

		token = _strt(string, " ");
		if (str_cmp(token, "exit", 4) == 0)
		{
			free(string);
			return (0);
		}

		cmd = malloc(30 * sizeof(char));
		m = locate_path(env, cmd, token, &command_count);
		if (m == 0)
		ex_string(env, string, &command_count);

		free(cmd);
		free(string);

		command_count++;
	}
}


