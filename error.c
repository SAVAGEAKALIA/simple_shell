#include "shell.h"
/**
 *error - prints error message
 *@input: argument for errror message
 *@cmd_number: cmd number
 *@status: error code
 *@interactive: checking interactive mode
 */

void error(char *input, int cmd_number, int status, int interactive)
{	char *path = input;
	char *cmd_name = input;
	int is_interactive = (interactive == 1), i;

	if (cmd_number > 0)
	{
		for (i = 0; i < cmd_number; i++)
		{	path = _strchr(path, '/');
			if (path)
			{	/* Remove trailing '/' characters*/
				while (*path == '/')
				{	*path = '\0';
					path--;	}
			}
			else
			{
				break; /* No more path components*/	}
		}
		if (i > 0)
		{
			cmd_name = path + 1; /*The command name is the next part*/	}
	}
	if (status == 127)
	{	handleCommandNotFound(cmd_name, is_interactive);	}
	else
	{handleOtherError(cmd_name, is_interactive);	}
}

/**
  *handleCommandNotFound - handle command not5 found error
  *@cmd_name: command name
  *@interactive: check if in interactive
  */
void handleCommandNotFound(const char *cmd_name, int interactive)
{
	if (interactive)
	{	write(STDERR_FILENO, cmd_name, strlen(cmd_name));
		write(STDERR_FILENO, ": command not found\n", 21);	}
	else
	{	write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, cmd_name, strlen(cmd_name));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
/**
  *error_cd - handle cd error
  *@cmd_name: command name
  *@name2: arg2
  */
void error_cd(const char *cmd_name, const char *name2)
{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, cmd_name, strlen(cmd_name));
		write(STDERR_FILENO, ": can't cd to ", 14);
		write(STDERR_FILENO, name2, strlen(name2));
		write(STDERR_FILENO, "\n", 1);
}
/**
  *handleOtherError - handle unknown error
  *@cmd_name: command name
  *@interactive: check if in interactive
  */

void handleOtherError(const char *cmd_name, int interactive)
{
	if (interactive)
	{	write(STDERR_FILENO, cmd_name, strlen(cmd_name));
		write(STDERR_FILENO, ": Error\n", 8);
	}
	else
	{	write(STDERR_FILENO, "hsh: 1:", 7);
		write(STDERR_FILENO, ": Error\n", 8);
	}
}
