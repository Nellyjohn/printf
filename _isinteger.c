#include "main.h"

char *int_to_string(int len, int digit);

/**
  * int_to_string - converts an integer to string
  * @num: multiples of 10
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
	while ((j = index - 1) && i < j)
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
	int val = 1;

	num = va_arg(list, int);
	if (num == 0)
	{
		len++;
		return (int_to_string(len, val));
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

	return (int_to_string(len, val));
}
