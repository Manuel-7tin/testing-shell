#include "shell.h"

/**
 * main - The main function of the shell program
 *
 * Description: This main function controls our basic shell program
 *
 * @argc: Argument count
 * @argv: Null terminated array of arguments
 * @env: Environment variables
 *
 * Return: int 0
 */
void free_args(char **args);
int main(int argc __attribute__((unused)), char **argv, char **env)
{
	int command_count = 1;

	signal(SIGINT, handle_signal);
	while (1)
	{
		char *string = NULL, *cmd = NULL, *token = NULL;
		int m;

		print_prompt();
		m = readline(&string, stdin);
		if (m == -1)
		{
			write(STDIN_FILENO, "\n", 1);
			free(string);
			return (0);
		}
		if (m == -5)
		{
			free(string);
			return (0);
		}

		token = strtok(string, " \n"); // Tokenize string using space and newline as delimiters
		if (token == NULL)
		{
			free(string);
			continue; // If there are no tokens, start the next iteration
		}

		if (str_cmp(token, "exit", 4) == 0)
		{
			free(string);
			return (0);
		}

		cmd = malloc(30 * sizeof(char));
		strcpy(cmd, token);

		char **args = malloc(30 * sizeof(char*)); // Array to store arguments
		int arg_count = 0;

		while (token != NULL)
		{
			args[arg_count] = malloc(strlen(token) + 1);
			strcpy(args[arg_count], token);
			arg_count++;
			token = strtok(NULL, " \n");
		}
		args[arg_count] = NULL; // Add NULL terminator at the end of the arguments array

		m = locate_path(env, cmd, cmd, &command_count); // Pass cmd instead of token for the command

		if (m == 0)
			ex_string(env, string, &command_count);

		free(cmd);
		free_args(args); // Custom function to free the arguments array
		free(string);

		command_count++;
	}
}

void free_args(char **args)
{
    if (args == NULL)
        return;

    for (int i = 0; args[i] != NULL; i++)
    {
        free(args[i]);
    }
    free(args);
}

