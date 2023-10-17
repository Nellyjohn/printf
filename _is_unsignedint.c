#include "main.h"

char *unsigned_to_string(unsigned int len,
		unsigned int digit);

/**
 * unsigned_to_string - converts unigned integer to string
 * @len: length of unsigned integer
 * @digit: unsigned integer to be convereted
 * Return: converted string
 */
char *unsigned_to_string(unsigned int len,
		unsigned int digit)
{
	char *str;
	unsigned int index, i, j;
	char temp;


	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	index = 0;
	while (digit > 0)
	{
		str[index++] = digit % 10 + '0';
		digit = digit / 10;
	}

	str[index] = '\0';

	i = 0;
	j = index - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
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
	unsigned int val = 1, temp;

	num = va_arg(list, unsigned int);
	str = malloc(sizeof(char) * (len + 1));

	if (!str)
		return (NULL);

	if (num == 0)
	{
		len++;
		return (unsigned_to_string(len, num));
	}

	temp = num;
	while (temp != 0)
	{
		len++;
		val *= 10;
		temp /= 10;
	}
	return (unsigned_to_string(len, num));
}
