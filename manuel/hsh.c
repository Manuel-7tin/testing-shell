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
	int command_count = 1;

	signal(SIGINT, handle_signal);
	while (1)
	{
		char *string = NULL, *cmd = NULL, *unknown_cmd = NULL;
		int n, m = -1;

		print_prompt();
		n = readline(&string, stdin);
		if (n == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			free(string);
			return (0);
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
			m = locate_path(env, cmd, unknown_cmd, &command_count);
		if (m == 0)
			ex_string(env, string, &command_count);
		free(string);
		free(cmd);
		free(unknown_cmd);
		command_count++;
	}
	return (0);
}
