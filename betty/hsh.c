#include "shell.h"

/**
 * main - The main function
 *
 * Description: The main function of our shell project
 *
 * @argc: Argument count
 * @argv: Null terminuated array of arguments
 * @env: environment variables
 *
 * Return: 0 on success -1 on failure
 */

int main(int argc __attribute__((unused)),
		char **argv,
		char **env)
{
	while (1)
	{
		int i;
		size_t input_size;
		char *input, **input_arr, *prompt = "$ ";
		pid_t pid;

		write(STDOUT_FILENO, prompt, strlen(prompt));
		input = malloc(400 * sizeof(char));
		if (input == NULL)
			return (-1);
		getline(&input, &input_size, stdin);
		input = strtok(input, "\n");
		input_arr = str_to_arr(input, " ");
		if (strcp(input_arr[0], "exit", 4) == 0)
			break;
		signal(SIGINT, exit);
		signal(SIGTERM, exit);
		pid = fork();
		if (pid == 0)
		{
			exec(input_arr, env, argv[0]);
			exit(1);
		} else
		{
			wait(NULL);
			for (i = 0; input_arr[i]; i++)
				free(input_arr[i]);
			free(input_arr);
		}
	}
	return (0);
}
