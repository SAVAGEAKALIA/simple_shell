#include "shell.h"

/**
 * is_valid_command - Check if a token is a valid command.
 * @token: The token to check.
 *
 * Return: 1 if it's a valid command, 0 otherwise.
 */
int is_valid_command(const char *token)
{
	/* Define a list of valid commands here. */
	const char *valid_commands[] = {
		"ls", "echo", "cd", "grep", "find", "cat", NULL
	};
	int i;

	for (i = 0; valid_commands[i] != NULL; i++)
	{
		if (_strcmp(token, valid_commands[i]) == 0)
		{
			return (1); /* Valid command */
		}
	}
	return (0); /* Invalid command */
}

/**
 * is_valid_argument - Check if a token is a valid argument.
 * @token: The token to check.
 *
 * Return: 1 if it's a valid argument, 0 otherwise.
 */
int is_valid_argument(const char *token)
{
	/* Define rules for valid arguments here. */
	/* This is a simplified example; real shells have more complex rules. */
	if (token[0] == '-')
	{
		return (1); /* Valid option or flag */
	}
	return (1); /* Valid argument (other than options) */
}

/**
 * is_valid_operator - Check if a token is a valid operator.
 * @token: The token to check.
 *
 * Return: 1 if it's a valid operator, 0 otherwise.
 */
int is_valid_operator(const char *token)
{
	/* Define rules for valid operators here. */
	const char *valid_operators[] = {"|", "&&", "||", ">", ">>", "<", "<<", NULL};
	int i;

	for (i = 0; valid_operators[i] != NULL; i++)
	{
		if (_strcmp(token, valid_operators[i]) == 0)
		{
			return (1); /* Valid operator */
		}
	}
	return (0); /* Invalid operator */
}

/**
 * validate_tokens - Validate a list of tokens for a shell command.
 * @tokens: The list of tokens to validate.
 *
 * Return: 1 if all tokens are valid, 0 if there's an error.
 */
int validate_tokens(char **tokens)
{
	int i = 0;
	int is_operator_expected = 0;

	while (tokens[i] != NULL)
	{
		if (is_operator_expected)
		{
			if (!is_valid_operator(tokens[i]))
				return (0); /* Invalid operator */
			is_operator_expected = 0;
		}
		else
		{
			if (is_valid_command(tokens[i]))
			{/*valid command doesn't require an operator immediately after*/
				is_operator_expected = 0;
			}
			else if (!is_valid_argument(tokens[i]))
			{
				return (0); /* Invalid argument */
			}
		}
		i++;
	}
	/*If an operator is still expected at the end, consider it an error*/
	if (is_operator_expected)
	{
		return (0); /* An operator is expected at the end */
	}
	return (1); /* All tokens are valid */
}
