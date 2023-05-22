#include "shell.h"
/**
 * handle_signal - Handles Ctrl+C signal
 * @signal: Ctrl+C signal
 */
void handle_signal(int signal)
{
	write(STDIN_FILENO, "\n", 1);
	print_prompt();
	fflush(stdout);
}
