#include "main.h"

char *unsigned_to_string(unsigned int num, unsigned int len,
		unsigned int digit);

/**
 * unsigned_to_string - converts unigned integer to string
 * @num: multiples of 10
 * @len: length of unsigned integer
 * @digit: unsigned integer to be convereted
 * Return: converted string
 */
char *unsigned_to_string(unsigned int num, unsigned int len,
		unsigned int digit)
{
	char *str;
	unsigned int index = 0;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	while (num > 0)
	{
		str[index] = ((digit / num) + '\0');
		digit = num % 10;
		num /= 10;
		index++;
	}

	str[index] = '\0';

	return (str);
}

/**
  * _is_unsignedint - prints an unsigned integer
  * @list: list of arguements
  * Return: string
  */
char *_is_unsignedint(va_list list)
{
	char *str;
	unsigned int num;
	unsigned int len = 0;
	unsigned int val = 1;

	num = va_arg(list, unsigned int);
	str = malloc(sizeof(char) * (len + 1));

	if (!str)
		return (NULL);

	if (num == 0)
	{
		len++;
		return (unsigned_to_string(val, len, num));
	}

	while (num != 0)
	{
		len++;
		if (len > 1)
		{
			val *= 10;
		}
		num /= 10;
	}
	return (unisgned_to_string(val, len, num));
}
