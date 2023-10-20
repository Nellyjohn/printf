#include "main.h"

/**
 * _xhlongint - function that conver int to hex lower
 * @list: argument list
 * Return: converted hex
 */

char *_xhlongint(va_list list)
{
	long int num = va_arg(list, long int);
	char *hex_str = (char *)malloc(17);
	const char *hex_chars = "0123456789abcdef";
	int i, leadingZero = 1, resultIndex = 0;
	char *result;

	if (num == 0)
	{
		result = (char *)malloc(2);
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}

	if (hex_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < 16; i++)
	{
		hex_str[i] = hex_chars[(num >> (60 - 4 * i)) & 0xF];
	}

	result = malloc(17);
	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < 16; i++)
	{
		if (hex_str[i] == '0' && leadingZero)
			continue;

		leadingZero = 0;
		result[resultIndex++] = hex_str[i];
	}

	if (leadingZero)
		result[resultIndex++] = '0';

	result[resultIndex] = '\0';

	return result;
}
