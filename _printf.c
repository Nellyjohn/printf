#include "main.h"

/**
 * buffer_overflow_check - function that check if buffer is above size
 * @ptr: pointer buffer holding string
 * @len: sting position in buffer
 * Return: position
 */

int buffer_overflow_check(char *ptr, int len)
{
	if (len > 1024)
	{
		write(1, ptr, len);
		len = 0;
	}
	return (len);
}

/**
 * _printf - custome printf function
 * @format: string to be printed with it's idntifiers
 * Return: string
 */

int _printf(const char *format, ...)
{
	int width = 0, size = 0, i = 0, j = 0;
	va_list list;
	char *bf, *str;
	char* (*fn)(va_list);

	if (!format)
		return (-1);
	bf = make_buffer();
	if (!bf)
		return (-1);
	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			width = buffer_overflow_check(bf, width);
			bf[width++] = format[i++];
			size++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(list);
				free(bf);
				return (-1);
			}
			if (format[i] == '%')
			{
				width = buffer_overflow_check(bf, width);
				bf[width++] = format[i];
				size++;
			}
			else
			{
				fn = select_function(format[i]);
				if (!fn)
				{
					width = buffer_overflow_check(bf, width);
					bf[width++] = '%';
					size++;
					bf[width++] = format[i];
					size++;
				}
				else
				{
					str = fn(list);
					if (!str)
					{
						va_end(list);
						free(bf);
						return (-1);
					}
					if (format[i] == 'c' && str[0] != '\0')
					{
						width = buffer_overflow_check(bf, width);
						bf[width++] = '\0';
						size++;
					}
					while (str[j] != '\0')
					{
						width = buffer_overflow_check(bf, width);
						bf[width++] = str[j];
						size++;
						j++;
					}
					free(str);
				}
			}
			i++;
		}
	}
	print_buffer(bf, width, list);
	return (size);
}
