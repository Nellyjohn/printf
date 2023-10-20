#include "main.h"

/**
 * buffer_overflow_check - function that check if buffer is above size
 * @buffer: pointer buffer holding string
 * @len: sting position in buffer
 * Return: position
 */
int buffer_overflow_check(char *buffer, int len)
{
	if (len > 1020)
	{
		write(1, buffer, len);
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
	int len = 0, size = 0, i = 0, j = 0;
	va_list list;
	char *buffer, *str;
	char* (*fn)(va_list);

	if (format == NULL)
		return (-1);
	buffer = make_buffer();
	if (buffer == NULL)
		return (-1);
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			len = buffer_overflow_check(buffer, len);
			buffer[len++] = format[i++], size++;
		}
		else
		{ i++;
			if (format[i] == '\0')
			{
				va_end(list), free(buffer), return (-1);
			}
			if (format[i] == '%')
			{
				len = buffer_overflow_check(buffer, len);
				buffer[len++] = format[i], size++;
			}
			else
			{
				fn = select_function(format[i]);
				if (fn == NULL)
				{
					len = buffer_overflow_check(buffer, len);
					buffer[len++] = '%', size++;
					buffer[len++] = format[i], size++;
				}
				else
				{
					str = fn(list);
					if (str == NULL)
					{
						va_end(list), free(buffer), return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = buffer_overflow_check(buffer, len);
						buffer[len++] = '\0', size++;
					}
					j = 0;
					while (str[j] != '\0')
					{
						len = buffer_overflow_check(buffer, len);
						buffer[len++] = str[j], size++, j++;
					} free(str);
				}
			} i++;
		}
	} print_buffer(buffer, len, list);
	return (size);
}
