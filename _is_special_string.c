#include "main.h"

/**
 * hex_print - function that convert int to hex
 * @num: int to be converted
 * Return: converted hex as a dynamically allocated string
 */

char *hex_print(unsigned int num)
{
	int i, cn = 0, digit;
	unsigned int tem = num;
	char *result, *ptr;

	while (num / 16 != 0)
	{
		num = num / 16;
		cn++;
	}
	cn++;
	result = malloc(sizeof(char) * (cn + 1));
	if (!result)
		return (NULL);

	ptr = result;

	for (i = 0; i < cn; i++)
	{
		digit = tem % 16;
		ptr[i] = (digit < 10) ? (digit + '0') : (digit + 'A' - 10);
		tem = tem / 16;
	}
	ptr[cn] = '\0';
	return (result);
}

/**
 * _is_special_string - function that print special string
 * @list: arguments
 * Return: special string as a dynamically allocated string
 */
char *_is_special_string(va_list list);
char *_is_special_string(va_list list)
{
	char *str, *result, *hex_str, *ptr;
	int i, len = 0, val;

	str = va_arg(list, char *);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			len += 4;
			/*
			 * val = str[i];
			 if (val < 16)
			 len++;
			 hex_str = hex_print(val);
			 for (; *hex_str != '\0'; hex_str++)
			 len++;
			 */
		}
		else
			len++;
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ptr = result;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			*ptr++ = '\\';
			*ptr++ = 'x';
			val = str[i];
			if (val < 16)
				*ptr++ = '0';
			hex_str = hex_print(val);
			while (*hex_str != '\0')
				*ptr++ = *hex_str++;
		}
		else
		{
			*ptr++ = str[i];
		}
	}
	*ptr = '\0';
	return (result);
}
