#include "main.h"
/**
 * int_to_str - converts an integer to string
 * @len: integer length
 * @digit: integer to be converted
 * Return: converted string
 */
char *int_to_str(int len, long int digit);
char *int_to_str(int len, long int digit)
{
	char *str;
	int isNegative = 0;
	int index, i, j;
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

	if (digit == LONG_MIN)
	{
		str = malloc(21);
		if (!str)
			return (NULL);
		strcpy(str, "-9223372036854775808");
		return (str);
	}
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	if (digit < 0)
	{
		digit = -digit;
		isNegative = 1;
	}

	index = 0;
	while (digit != 0)
	{
		str[index++] = digit % 10 + '0';
		digit = digit / 10;
	}
	if (isNegative)
		str[index++] = '-';

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
 * _islongint - prints an integer
 * @list: argument list
 * Return: integer
 */
char *_islongint(va_list list)
{
	long int num;
	int len = 0;
	int val = 1, temp;

	num = (long int)va_arg(list, long int);
	val = num;
	if (num == 0)
	{
		len++;
		return (int_to_str(len, num));
	}
	temp = num;
	while (temp != 0)
	{
		len++;
		val /= 10;
		temp /= 10;
	}

	return (int_to_str(len, num));
}
