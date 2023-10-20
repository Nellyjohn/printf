#include "main.h"

char *unsigned_to_str(unsigned short int len,
		unsigned short int digit);

/**
 * unsigned_to_str - converts unigned integer to string
 * @len: length of unsigned integer
 * @digit: unsigned integer to be convereted
 * Return: converted string
 */
char *unsigned_to_str(unsigned short int len,
		unsigned short int digit)
{
	char *str;
	unsigned short int index, i, j;
	char temp;

	if (digit == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

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
 * _uhshortint - prints an unsigned integer
 * @list: list of arguements
 * Return: string
 */
char *_uhshortint(va_list list)
{
	char *str;
	unsigned short int num;
	unsigned short int len = 0;
	unsigned short int val = 1, temp;

	num = va_arg(list, unsigned int);
	str = malloc(sizeof(char) * (len + 1));

	if (!str)
		return (NULL);

	if (num == 0)
	{
		len++;
		return (unsigned_to_str(len, num));
	}

	temp = num;
	while (temp != 0)
	{
		len++;
		val *= 10;
		temp /= 10;
	}
	return (unsigned_to_str(len, num));
}
