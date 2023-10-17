#include "main.h"

/**
 * _isbinary - function that convert unsigned int to binary
 * @list: argirment list
 * Return: binary string
 */

char *_isbinary(va_list list)
{
	int j = 0, bin = 1, val, i;
	char *str;

	val = va_arg(list, int);
	i = val;
	str = malloc(sizeof(char) * 33);
	if (!str)
		return (NULL);
	if (val < 0)
	{
		str[0] = 1 + '\0';
		j++;
		val *= -1;
		i *= -1;
	}

	while (val > 1)
	{
		val /= 2;
		bin *= 2;
	}
	while (bin > 0)
	{
		str[j++] = ((i / bin) + '0');
		i = i % bin;
		bin /= 2;
	}
	str[j] = '\0';
	return (str);
}
