#include "main.h"
/**
 * _is_hex_upper - prints a hexadecimal integer in uppercase
 * @list: list of arguments
 * Return: converted string
 */
char *hex_with_prefix_upper(va_list list);
char *hex_with_prefix_upper(va_list list)
{
	int num = va_arg(list, int);
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
		result[1] = 'X';
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
	result = malloc(9);
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

	return (result);
}
