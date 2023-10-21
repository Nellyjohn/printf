#include "main.h"
/**
 * _izero_padded_longint - Handles zero-padding for long integers
 * @list: Argument list
 * @width: Desired width for padding
 * Return: Zero-padded long integer string
 */
char *_izero_padded_longint(va_list list)
{
	long int num = va_arg(list, long int);
	char *str = int_to_string(0, num);
	int len, i, j, width = 6;

	if (!str)
		return (NULL);

	len = _strlen(str);

	if (len < width)
	{
		char *padded_str = malloc(width + 1);

		if (!padded_str)
		{
			free(str);
			return (NULL);
		}

		for (i = 0; i < width - len; i++)
			padded_str[i] = '0';

		for (j = 0; i < width && str[j] != '\0'; i++, j++)
			padded_str[i] = str[j];

		padded_str[i] = '\0';
		free(str);

		return (padded_str);
	}

	return (str);
}
