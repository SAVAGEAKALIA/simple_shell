#include "shell.h"

/**
 * _strtok - Splits a string into tokens using a set of delimiter characters.
 * @str: The string to be split.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token found in the string or NULL if no more
 * tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;  /* Stores the position of the last token */
	char *start = NULL, *end = NULL;

	if (str != NULL)
	{	lastToken = str;	}
	else if (lastToken == NULL)
	{	return (NULL);  /* No more tokens */	}
	/* Find the start of the token */
	start = lastToken;
	while (*start != '\0' && _strchr(delim, *start) != NULL)
	{	start++;
	}
	if (*start == '\0')
	{	lastToken = NULL;  /* No more tokens */
		return (NULL);
	}
	/* Find the end of the token */
	end = start + 1;
	while (*end != '\0' && _strchr(delim, *end) == NULL)
	{	end++;	}

	if (*end != '\0')
	{	*end = '\0';  /* Null-terminate the token */
		lastToken = end + 1;	}
	else
	{	lastToken = NULL;  /* No more tokens */
	}
	return (start);	}
