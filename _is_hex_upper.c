#include "main.h"

/**
  * _is_hex_upper - prints a hexadecimal integer in uppercase
  * @list: list of arguments
  * Return: converted string
  */
char *_is_hex_upper(va_list list)
{
	int i = 0;
	int h = 1;
	int val;
	char *str;
	char arr[] = "0123456789ABCDEF";

	val = va_arg(list, int);

	str = malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);

	if (val < 0)
	{
		str[0] = 1 + '0';
		i++;
		val *= -1;
	}

	while (val > 1)
	{
		val /= 16;
		h *= 16;
	}

	while (h > 0)
	{
		str[i++] = arr[val % 16];
		val %= 16;
		h /= 16;
	}
	str[i] = '\0';

	return (str);
}
