#include "shell.h"
/**
 * ffree - Frees the memory allocated for an array of strings.
 * @argv: The array of strings to free.
 */

void ffree(char **argv)
{
	int i = 0;

	if (argv == NULL)
	{
		return;
	}

	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}

	free(argv);
}
