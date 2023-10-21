#include "main.h"

/**
 * _izero_padded_shortint - Handles zero-padding for short integers
 * @list: Argument list
 * @width: Desired width for padding
 * Return: Zero-padded short integer string
 */
char *_izero_padded_shortint(va_list list)
{
	short int num = (short int)va_arg(list, int);
	int i, j, len, width = 6;
	char *str = int_to_string(0, num);

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

