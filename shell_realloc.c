#include "shell.h"
/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloced block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the reallocated block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_data;
	char *new_data;
	unsigned int i, copy_size;

	if (!ptr)  /*If ptr is NULL, equivalent to malloc*/
	{
		return (malloc(new_size));
	}
	if (!new_size)  /*If new_size is 0, equivalent to freeing the memory*/
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)  /*If the sizes are the same, don't reallocate*/
	{
		return (ptr);
	}
	new_ptr = malloc(new_size);  /* Allocate memory for the new block*/
	if (!new_ptr)
	{
		return (NULL);  /*Return NULL if malloc fails*/
	}
	/*Copy data from the old block to the new block*/
	old_data = (char *)ptr;
	new_data = (char *)new_ptr;

	copy_size = (old_size < new_size) ? old_size : new_size;

	for (i = 0; i < copy_size; i++)
	{
		new_data[i] = old_data[i];
	}
	free(ptr);
	/* Free old block*/
	return (new_ptr);
}
