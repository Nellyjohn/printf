#include "main.h"

char *int_to_string(int len, int digit);

/**
 * int_to_string - converts an integer to string
 * @len: integer length
 * @digit: integer to be converted
 * Return: converted string
 */
char *int_to_string(int len, int digit)
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

	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	if (digit == INT_MIN)
	{
		str = malloc(sizeof(char) * 12);
		if (!str)
			return (NULL);
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
		return (str);
	}
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
 * _isinteger - prints an integer
 * @list: argument list
 * Return: integer
 */
char *_isinteger(va_list list)
{
	int num;
	int len = 0;
	int val = 1, temp;

	num = va_arg(list, int);
	val = num;
	if (num == 0)
	{
		len++;
		return (int_to_string(len, num));
	}
	temp = num;
	while (temp != 0)
	{
		len++;
		val /= 10;
		temp /= 10;
	}

	return (int_to_string(len, num));
}
