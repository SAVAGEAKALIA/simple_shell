#include "shell.h"

/**
  *shell_tokens - Splits a string into tokens based on a delimiter.
  *@line: The input string to be tokenized.
  *Return: An array of tokens.
  */
char **shell_tokens(const char *line)
{
	char *delim = " \n\t\r";/*remove space for question 2*/
	char *token = NULL, *line_cpy = NULL;
	size_t length = _strlen(line), len = 0, i = 0;
	char **tokens = (char **)malloc(sizeof(char *) * (length + 1));

	if (tokens == NULL || line == NULL)
	{	perror("malloc");
		return (NULL);
	}	line_cpy = _strdup(line);  /*Duplicate the input line*/
	if (line_cpy == NULL)
	{	perror("_strdup");
		ffree(tokens);
		free(line_cpy);
		return (NULL);
	}	token = _strtok(line_cpy, delim);
	while (token != NULL)
	{		tokens[i++] = _strdup(token);  /* Duplicate the token*/
			if (tokens[i - 1] == NULL)
			{	perror("_strdup");
				ffree(tokens);
				free(line_cpy);
				return (NULL);
			}	len++;
			if (len >= length)
			{length *= 2;/* Resize the tokens array if needed*/
			tokens = _realloc(tokens, sizeof(char *) * (length * 2),
					sizeof(char *) * length);
			if (tokens == NULL)
			{	perror("_realloc");
				ffree(tokens);
				free(line_cpy);
				return (NULL);
			}
			}
			token = _strtok(NULL, delim);
	}
	tokens[i] = NULL;  /*Null-terminate the array of tokens*/
	free(line_cpy);
	return (tokens);
}
/**
  *split_commands - function to split commands with ;&&||
  *@input: line of argv from stdin
  *Return: return commnads on success
  */

char **split_commands(const char *input)
{	char *input_copy = NULL, *token = NULL;
	size_t num_commands = 0, len = _strlen(input);
	char **commands = malloc(sizeof(char *) * (len + 1));

	if (commands == NULL)
	{	perror("malloc split_commands");
		return (NULL);
	}
	input_copy = _strdup(input); /*Create a copy of the input string*/
	if (input_copy == NULL)
	{	perror("_strdup split_commands");
		free(commands);
		exit(EXIT_FAILURE);
	}
	token = _strtok(input_copy, ";&&||");
	while (token != NULL)
	{
		if (num_commands >= len)
		{	len *= 2;
			commands = _realloc(commands, sizeof(char *) * (len * 2),
					sizeof(char *) * len);
			if (commands == NULL)
			{	perror("realloc split_commands");
				free(input_copy);
				exit(EXIT_FAILURE);
			}
		}
		commands[num_commands] = _strdup(token);
		if (commands[num_commands] == NULL)
		{	perror("_strdup split_commands");
			ffree(&commands[num_commands]);
			free(input_copy);
			exit(EXIT_FAILURE);
		}
		num_commands++;
		token = _strtok(NULL, ";&&||");
	} /*Null-terminate the array of commands*/
	commands[num_commands] = NULL;
	free(input_copy);
	return (commands);
}
