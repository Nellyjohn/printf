#include "main.h"

/**
 * _ischar - function return char as string
 * @list: char value
 * Return: return string
 */

char *_ischar(va_list list)
{
	char *str, alpha;

	alpha = va_arg(list, int);

	if (alpha == 0)
	{
		alpha = '\0';
	}

	str = malloc(sizeof(char) * 2);

	if (!str)
	{
		return (NULL);
	}
	str[0] = alpha;
	str[1] = '\0';
	return (str);
}
