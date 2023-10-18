#include "main.h"

/**
 * _isreversed_string - function that reverses string
 * @list: argument
 * Return: reversed string
 */

char *_isreversed_string(va_list list)
{
        char *ptr;
	char *str;
	int i = 0, len, j;

	str = va_arg(list, char *);
	if (!str)
		str = ")llun(";

	len = _strlen(str);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);

	for(j = (len - 1); j >= 0; j--)
	{
		ptr[i++] = str[j];
	}
	ptr[i] = '\0';

	return (ptr);
}
