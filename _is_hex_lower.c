#include "main.h"

char *_is_hex_lower(va_list list)
{
	int i = 0, h = 1, val;
	char *str;
	char arr[] = "123456789abcdef";

	val = va_arg(list, int);

	str = malloc(sizeof(char) * 17);

	if (!str)
		return (NULL);
	if (val < 0)
	{
		s[0] = 1 + '0';
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
