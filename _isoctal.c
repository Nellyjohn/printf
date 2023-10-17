#include "main.h"

/**
 * _isoctal - function that convert int to octal
 * @list: argument list
 * Return: converted octal number
 */

char *_isoctal(va_list list)
{
	int i = 0, oct = 1, val;
	char *str;

	val = va_arg(list, int);
	str = mallac(sizeof(char) * 12);

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
		val /= 8;
		oct *= 8;
	}
	while (oct > 0)
	{
		str[i++] = (val / oct + '0');
		val = val % oct;
		oct /= 8;
	}
	str[i] = '\0';
	return (str);
}
