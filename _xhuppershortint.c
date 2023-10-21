#include "main.h"

/**
 * _xhuppershortint - function that conver int to hex lower
 * @list: argument list
 * Return: converted hex
 */

char *_xhuppershortint(va_list list);
char *_xhuppershortint(va_list list)
{
	short int num = (short int)va_arg(list, int);
	char *hex_str = (char *)malloc(9);
	const char *hex_chars = "0123456789ABCDEF";
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

	for (i = 0; i < 8; i++)
	{
		hex_str[i] = hex_chars[(num >> (12 - 4 * i)) & 0xF];
	}
	hex_str[4] = '\0';

	result = malloc(9);
	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < 8; i++)
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
