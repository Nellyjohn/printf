#include "main.h"

/**
 * hex_with_prefix - function that conver int to hex lower
 * @list: argument list
 * Return: converted hex
 */
char *hex_with_prefix(va_list list);
char *hex_with_prefix(va_list list)
{
	int num = va_arg(list, int);
	char *hex_str = (char *)malloc(9);
	const char *hex_chars = "0123456789abcdef";
	int i, leadingZero = 1, resultIndex = 0;
	char *result;

	if (num == 0)
	{
		result = (char *)malloc(3);
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = 'x';
		result[2] = '\0';
		return (result);
	}

	if (hex_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < 8; i++)
	{
		hex_str[i] = hex_chars[(num >> (28 - 4 * i)) & 0xF];
	}

	result = malloc(10);
	if (result == NULL)
	{
		return (NULL);
	}

	result[0] = '0';
	result[1] = 'x';
	resultIndex = 2;

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
