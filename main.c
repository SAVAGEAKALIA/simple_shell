#include "shell.h"
/**
 *main - main function for simple shell
 *@argc: argument count
 *@argv: argument passed to shell (vector)
 *Return: 0 if it fails
 */

int main(int argc, char **argv)
{		char *read_fd = NULL;
		char **tokens = NULL, **commands = NULL;
		int  cmd, exec_status = 0, exit_status = 0;
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
			if (read_fd == NULL  || read_fd[0] == '\0')
			{	continue;	}
			commands = split_commands(read_fd);
			if (commands != NULL)
			{
			for (cmd = 0; commands[cmd] != NULL; cmd++)
			{	tokens = shell_tokens(commands[cmd]);
				if (tokens != NULL)
			{
				if (tokens[0] != NULL && _strlen(tokens[0]) > 0)
				{	exec_status = shell_exec(tokens, interactive);
					ffree(tokens);
					if (exec_status != 0)
					{	exit_status = exec_status;
					if (!interactive)
					{	return (exit_status);	}
					}
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
	return (exit_status);	}
