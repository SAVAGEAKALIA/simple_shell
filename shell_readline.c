#include "shell.h"
/**
  *read_line - function to read line from stdin
  *Return: line on success
  */

char *read_line(void)
{
	size_t n = 0;
	char *line = NULL;

	if (getline(&line, &n, stdin) == -1)
	{
		while (1)
		{
		if (line != NULL)
		{	free(line);
			break;
		}
		/*perror("bytes_read");*/
		/*return (NULL);*//*Handle other errors as needed*/
		}
	}
	return (line);
}

/**
  *_getline - read line from stdin
  *Return: string on success
  */

char *_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_position;
	static int buffer_size;
	char *line = NULL, *new_line = NULL;
	int line_length = 0, ch;

	while (1)
	{/*If the buffer is empty, read more data into it*/
		if (buffer_position >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
			{/*No more data to read*/
				break;
			}
			buffer_position = 0;
		}
		/*Read one character from the buffer*/
		ch = buffer[buffer_position++];
		/* Check for newline or end of file*/
		if (ch == '\n' || ch == EOF)
		{	new_line = (char *)_realloc(line, line_length, line_length + 1);
			line = new_line;
			line[line_length] = '\0';
			break;
		}
		else
		{/*Allocate memory for the line and add the character*/
		new_line = (char *)_realloc(line, line_length, line_length + 2);
		/*new_line = malloc(sizeof(char) * (line_length) + 2);*/
		if (new_line == NULL)
		{	free(line);
			return (NULL);
		}
		line = new_line;
		line[line_length++] = ch;
		}
	}
	return (line);
}
