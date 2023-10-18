#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: If the environment variable is found, a pointer to its value is
 *         returned. Otherwise, NULL is returned.
 */
char *_getenv(const char *name)
{
	char **env;
	size_t namelen;

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}

	namelen = _strlen(name);
	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(name, *env, namelen) == 0 && (*env)[namelen] == '=')
		{
			/* Found the environment variable */
			return (&(*env)[namelen + 1]); /* Return the value part */
		}
	}
	/* Environment variable not found */
	return (NULL);
}
