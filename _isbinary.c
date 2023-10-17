#include "main.h"

/**
 * _isbinary - function that convert unsigned int to binary
 * @list: argirment list
 * Return: binary string
 */

char *_isbinary(va_list list)
{
	int j = 0, bin = 1, val;
	char *str;

	val = va_arg(list, int);
	str = malloc(sizeof(char) * 33);
	if (!str)
		return (NULL);
	if (val < 0)
	{
		str[0] = 1 + '\0';
		j++;
		val *= -1;
	}

	while (val > 1)
	{
		val /= 2;
		bin *= 2;
	}
	while (bin > 0)
	{
		str[j++] = ((val / bin) + '0');
		val = val % bin;
		bin /= 2;
	}
	str[j] = '\0';
	return (str);
}
