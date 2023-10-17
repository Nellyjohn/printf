#include "main.h"

char *int_to_string(int num, int len, int digit);

/**
  * int_to_string - converts an integer to string
  * @num: multiples of 10
  * @len: integer length
  * @digit: integer to be converted
  * Return: converted string
  */
char *int_to_string(int num, int len, int digit)
{
	char *str;
	int index = 0;

	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	if (digit < 0)
	{
		str[0] = '-';
		index++;
	}

	while (digit < 0)
	{
		str[index] = ((digit / num) * -1 + '\0');
		digit = digit % num;
		num /= 10;
		index++;
	}

	while (num > 1)
	{
		str[index] = ((digit / num) + '\0');
		digit = digit % num;
		num /= 10;
		index++;
	}
	str[index] = '\0';

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
		return (int_to_string(val, len, num));
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

	return (int_to_string(val, len, num));
}
