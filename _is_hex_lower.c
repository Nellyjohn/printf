#include "main.h"

/**
 * _is_hex_lower - function that conver int to hex lower
 * @list: argument list
 * Return: converted hex
 */

char *_is_hex_lower(va_list list)
{
	int num = va_arg(list, int);
	char *hex_str = (char *)malloc(9);
	const char *hex_chars = "0123456789abcdef";
	int i;

	if (hex_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < 8; i++)
	{
		hex_str[i] = hex_chars[(num >> (28 - 4 * i)) & 0xF];
	}
	hex_str[8] = '\0';

	return (hex_str);
}






