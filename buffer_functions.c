#include "main.h"

/**
 * make_buffer - function that make buffer until it is ready to print
 * Return: buffer created
 */
char *make_buffer(void)
{
	char *ptr;

	ptr = malloc(sizeof(char) * 1024);
	if (!ptr)
		return (NULL);
	return (ptr);
}

/**
 * print_buffer - function that print the buffer and free the space
 * @ptr: pointer holding printabl buffers
 * @len: length of string to be printed
 * @list: list
 */

void print_buffer(char *ptr, int len, va_list list)
{
	char *buffer;

	buffer = realloc(ptr, len);
	write(1, buffer, len);
	free(buffer);
	va_end(list);
}
