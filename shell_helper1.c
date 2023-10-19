#include "shell.h"

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @str: The string to be searched.
 * @target: The character to look for.
 *
 * This function searches for the first occurrence of the character `target` in
 * the string `str`.
 * Return: A pointer to the memory area in `str` where the character `target`
 * is found, or NULL if the character is not present in the string.
 */
char *_strchr(const char *str, char target)
{
	do {
		if (*str == target)
			return ((char *)str);
	} while (*str++ != '\0');

	/*If the character 'target' is not found, return NULL*/
	return (NULL);
}


/**
 * _strncpy - Copies a string with a specified length.
 * @dest: The destination buffer where the string will be copied.
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy.
 *
 * This function copies up to `n` characters from the `src` string to the
 * `dest` buffer.
 * If `src` is shorter than `n`, the remaining characters in `dest` are filled
 * with null bytes.
 *
 * Return: The `dest` buffer after copying.
 */
char *_strncpy(char *dest, const char *src, int n)
{
	int i, j;

	/*Initialize a pointer to the beginning of the destination buffer*/
	char *result = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}

	/*If the source string is shorter than 'n'*/
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	/* Return the modified 'dest' buffer*/
	return (result);
}

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string where the copy will be placed.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0'; /* Null-terminate the destination string */

	return (original_dest);
}

/**
 * _strncmp - Compare at most the first n characters of two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the first n characters of s1 and s2 are equal, a value greater
 *         than 0 if the first differing character in s1 is greater than s2,
 *         and a value less than 0 if the first differing character in s1 is
 *         less than s2.
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	if (n == 0)
	{
		return (0);  /* Nothing to compare, so they are considered equal. */
	}

	while (n-- && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (n == -1)
	{	return (0);  /* All compared characters match. */
	}
	else
	{
		return (*s1 - *s2);
	}
}


/**
  *_strrchr - Locates the last occurrence of a character in a string.
  *@str: pointer to string
  *@ch: character to track
  *Return:  A pointer to the memory area in `str`
  */

char *_strrchr(const char *str, int ch)
{
	char *result = NULL;

	if (str == NULL)
		return (NULL);

	while (*str)
	{
		if (*str == ch)
			result = (char *)str;
		str++;
	}
	return (result);
}
