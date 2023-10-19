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
		int  cmd;
		bool interactive = isatty(STDIN_FILENO);

		(void)argv;
		(void)argc;
		while (1)
		{
			if (interactive)
			{
				prompt();	}

			read_fd = read_line(interactive);
			/*read_fd = _getline();*/
			if (read_fd == NULL)
			{ break;
			}
			commands = split_commands(read_fd);
			if (commands != NULL)
			{
			for (cmd = 0; commands[cmd] != NULL; cmd++)
			{	tokens = shell_tokens(commands[cmd]);
				if (tokens != NULL)
			{
				if (tokens[0] != NULL && strlen(tokens[0]) > 0)
				{
					shell_exec(tokens);
					ffree(tokens);
				}
				else
				{
					continue;	}
				}
			}
			 ffree(commands);
			 free(read_fd);
			}
		}

	return (0);
}
