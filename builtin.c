#include "shell.h"
/**
  *shell_cd - function to change the directory
  *@args: argument passed to function
  *No return value for void function
  */

void shell_cd(char **args)
{
	const char *home, *previous_dir;
	char cwd[1024];

	if (args[1] == NULL)
	{	home = _getenv("HOME");
		if (home == NULL)
		{	/*write(STDERR_FILENO, "cd: $HOME not set\n", 18);*/
			return;
		}
		if (chdir(home) != 0)
		{	error_cd(args[0], args[1]);
			return;	}
	}
	else if (_strcmp(args[1], "-") == 0)
	{	previous_dir = _getenv("OLDPWD");
		if (previous_dir == NULL)
		{	/*write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);*/
			return;
		}
		if (chdir(previous_dir) != 0)
		{	error_cd(args[0], args[1]);
			return;
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{	error_cd(args[0], args[1]);
			return;
		}
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{	perror("getcwd");
		return;
	}
	if (setenv("PWD", cwd, 1) != 0)
	{	perror("setenv");
		return;
	}
}


/**
  *shell_exit - function to exit the shell
  *@args: argument passed to function
  *If status is passed shell exits with status code
  */

void shell_exit(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		exit(status);
	}
	else
	{/*No status code provided, exit with 0 as the default*/
		exit(0);
	}
}


/**
 *shell_env - function to  print the environment.
 *@args: The arguments passed to shell
 *Function to print current shell environment
 */
void shell_env(char **args)
{
	char **env = environ;
	(void)args;

	while (*env)
	{
		write(STDOUT_FILENO, *env, _strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 *shell_unsetenv - Unset an environment variable.
 *@args: args[0] is "unsetenv", and args[1] is the variable to unset.
 */

void shell_unsetenv(char **args)
{
	if (args[1] != NULL)
	{
		if (unsetenv(args[1]) == -1)
		{
			perror("hsh");
		}
	}
}

/**
 *shell_setenv - Set an environment variable.
 *@args: args[0] is "setenv", args[1] is the variable, and args[2] the value.
 */

void shell_setenv(char **args)
{
	if (args[1] != NULL && args[2] != NULL)
	{
		if (setenv(args[1], args[2], 1) == -1)
		{
			perror("hsh");
		}
	}
}
