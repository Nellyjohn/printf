#include "main.h"

/**
 * _ohlongint - function that converts int to octal
 * @list: argument list
 * Return: converted octal number
 */
char *_ohlongint(va_list list)
{
	long int octal[32], i = 0, j;
	char *result;
	unsigned long int num = (unsigned long int)va_arg(list, unsigned long int);

	if (num == 0)
	{
		result = (char *)malloc(2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}

	while (num > 0)
	{
		octal[i++] = num % 8;
		num /= 8;
	}

	result = (char *)malloc(i + 1);

	if (result == NULL)
	{
		return (NULL);
	}

	for (j = i - 1; j >= 0; j--)
	{
		result[i - 1 - j] = octal[j] + '0';
	}

	result[i] = '\0';
	return (result);
}
