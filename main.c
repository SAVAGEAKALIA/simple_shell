#include "shell.h"
/**
 *main - main function for simple shell
 *@argc: argument count
 *@argv: argument passed to shell
 *Return: 0 if it fails
 */

int main(int argc, char **argv)
{		char *read_fd = NULL;
		char **tokens = NULL, **commands = NULL;
		int i, cmd, interactive = isatty(STDIN_FILENO);

		if (argc > 1)
		{
			for (i = 1; i < argc; i++)
		{
			shell_exec(&argv[i], interactive);
		}
		}
		else
		{
		while (1)
		{
			if (interactive)
			{
				prompt();
			}
			read_fd = read_line();
			read_fd = _getline();
			if (read_fd == NULL)
			{ break;
			}
			commands = split_commands(read_fd);
			if (commands != NULL)
			{
			for (cmd = 0; commands[cmd] != NULL; cmd++)
			{	tokens = shell_tokens(commands[cmd]);
				if (tokens != NULL)
				{	shell_exec(tokens, interactive);
					ffree(tokens);
				}
			}
			 ffree(commands);
			 free(read_fd);
			}
		}
	}
	return (0);
}
