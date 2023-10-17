#include "main.h"

/**
 * _is_hex_lower - function that conver int to hex lower
 * @list: argument list
 * Return: converted hex
 */

char *_is_hex_lower(va_list list)
{
	int i = 0, h = 1, val;
	long int j;
	char *str;
	char arr[] = "0123456789abcdef";

	val = va_arg(list, int);
	j = val;
	str = malloc(sizeof(char) * 17);

	if (!str)
		return (NULL);
	if (val < 0)
	{
		str[0] = 1 + '0';
		i++;
		val *= -1;
		j *= -1;
	}

	while (val > 1)
	{
		val /= 16;
		h *= 16;
	}

	while (h > 0)
	{
		str[i++] = arr[j / 16];
		j %= 16;
		h /= 16;
	}
	str[i] = '\0';
	return (str);
}
