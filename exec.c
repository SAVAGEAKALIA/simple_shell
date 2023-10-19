#include "shell.h"
/**
  *shell_exec - funct to execute command
  *@argv: command passed to be executed
  *Return: -1 on error
  */
int shell_exec(char **argv)
{
	pid_t pid;
	int status;	/*char *path = get_path(argv[0]);*/

	if (builtin_exec(argv) == 0)
	{	/*free(path);*/
		return (0);
	}

	pid = fork();
	if (pid == -1)
	{	perror("Fork");
		/*free(path);*/
		return (-1);	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{/*No such file or directory*/
			/*free(path)*/
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{	perror("Waitpid");
			/*free(path);*/
			return (-1);	}
		/*free(path);*/
		return (status);
	}
	return (-1);	}

/**
  *get_path - get command path
  *@argv: command passed
  *Return: Null on failure
  */
char *get_path(char *argv)
{	char *path = _getenv("PATH"), *path_cpy, *path_token;
	char *file_path = NULL; /*lastSlash;*/
	size_t len = _strlen(argv);
	size_t path_length;
	struct stat st;


	if (argv != NULL && _strchr(argv, '/') != NULL)
	{	/*Return argv as is*/
		return (_strdup(argv)); }

	if (argv != NULL && argv[0] != '\0')
	{
	path_cpy = _strdup(path);
	path_token = _strtok(path_cpy, ":");
	while (path_token != NULL)
	{	/*get length of path*/
		path_length = _strlen(path_token) + len + 2;
		/*memory alloc for storing argv length with path_length*/
		file_path = malloc(path_length);
		if (file_path == NULL)
		{	perror("malloc get_path");
			free(path_cpy);
			return (NULL);
		}
		/*build path for argv*/
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, argv);
		/*check if path exist*/
		if (stat(file_path, &st) == 0)
		{/*return 0 vallue indicates success*/
			free(path_cpy);
			return (file_path);
		}
		else
		{	free(file_path);
			path_token = _strtok(NULL, ":");	}
	}
	free(path_cpy);
	}
	return (NULL); }

static struct builtin builtins[] = {
	{"help", shell_help},
	{"cd", shell_cd},
	{"exit", shell_exit},
	{"env", shell_env},
	{"setenv", shell_setenv},
	{"unsetenv", shell_unsetenv},
	{NULL, NULL},
};

/**
  *num_builtin - function to cal num of builtin
  *Return: builtin num
  */

int num_builtin(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}

/**
  *builtin_exec - move through builtin struct
  *@argv: cammand from stdin
  *Return: -1 on failure
  */

int builtin_exec(char **argv)
{
	int i;

	if (argv == NULL || argv[0] == NULL)
	{
		return (-1);
	}

	for (i = 0; i < num_builtin(); i++)
	{
		if (builtins[i].name != NULL && _strcmp(argv[0], builtins[i].name) == 0)
		{
			if (builtins[i].funct != NULL)
			{
			(builtins[i].funct(argv));
			return (0);
			}
			else
				return (-1);
		}
	}
	return (-1);
}
