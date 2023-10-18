#include "shell.h"
/**
  *_strdup - function for duplicatin string using malloc
  *@s: string to be duplicated
  *Return: duplicted string
  */

char *_strdup(const char *s)
{
	char *str;
	int n = _strlen(s);
	int i;

	str = malloc(sizeof(char) * n + 1);

	if (str == NULL)
	{
		free(str);
		return (NULL);
	}

	for (i = 0; i < n; i++)
	{
		str[i] = s[i];
	}

	str[n] = '\0';

	return (str);
}

/**
  *_strlen - function for calculating string length
  *@s: string to be calculated
  *Return: length of string on success
  */


size_t _strlen(const char *s)
{
	int i = 0;

	if (s == NULL)
	{
		return (0); /*Return 0 for null pointer*/
	}

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
 * _atoi - Convert a string to an integer.
 * @str: The input string to be converted.
 *
 * Description: This function converts a string to an integer,
 * taking into account a possible negative sign at the beginning.
 *
 * Return: The integer value extracted from the string.
 */
int _atoi(char *str)
{
	int i, sign = 1, digitFlag = 0, result = 0;

	for (i = 0; str[i] != '\0' && digitFlag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1; /* Handle negative sign */

		if (str[i] >= '0' && str[i] <= '9')
		{
			digitFlag = 1;/*flagto indicate digits have been encountered*/
			result *= 10;
			result += (str[i] - '0'); /*Convert character to integer*/
		}
			else if (digitFlag == 1)
			digitFlag = 2; /*non-digit character encountered, break*/
	}

	if (sign == -1)
		result = -result;

	return (result); /*Return the final integer*/
}

/**
 * _strcmp - Compare two strings.
 * @str1: first string.
 * @str2: second string.
 * Return: Negative if str1 < str2, positive if str1 > str2, zero if str1 ==
 * str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strcat - Concatenates two strings.
 * @destination: The destination buffer.
 * @source: The source buffer.
 * Return: Pointer to the destination buffer.
 */
char *_strcat(char *destination, char *source)
{
	char *result = destination;

	while (*destination)
		destination++;

	while (*source)
		*destination++ = *source++;

	*destination = *source;

	return (result);
}
