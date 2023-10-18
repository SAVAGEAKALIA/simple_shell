#include "shell.h"

/**
 *shell_help - Print help information.
 *@args: The arguments.
 */

void shell_help(char **args)
{
	(void)args;
	write(STDOUT_FILENO, "Simple Shell - Help\n", 20);
	write(STDOUT_FILENO, "These are the built-in commands:\n", 34);
	write(STDOUT_FILENO, "cd - Change directory\n", 23);
	write(STDOUT_FILENO, "exit - Exit the shell\n", 22);
	write(STDOUT_FILENO, "env - Print environment\n", 24);
	write(STDOUT_FILENO, "unsetenv - Unset environment variable\n", 39);
	write(STDOUT_FILENO, "setenv - Set environment variable\n", 35);
	write(STDOUT_FILENO, "help - Display help information\n", 33);
}
