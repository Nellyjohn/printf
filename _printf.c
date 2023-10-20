#include "main.h"

/**
 * buffer_overflow_check - function that check if buffer is above size
 * @ptr: pointer buffer holding string
 * @len: sting position in buffer
 * Return: position
 */
int buffer_overflow_check(char *ptr, int len)
{
	int i;

	if (len > 1020)
	{
		write(1, ptr, len);
		for (i = 0; i < len; i++)
		{
			ptr[i] = 0;
		}
		len = 0;
	}
	return (len);
}

/**
 * check_length_modifier - function that check for length modifier
 * @format: format specifir
 * @i: int
 * @length_modifier: specifier value
 * Return: int
 */

int check_length_modifier(const char *format, int i, char *length_modifier)
{
	/* Check for length modifiers*/
	if (format[i] == 'h' || format[i] == 'l')
	{
		*length_modifier = format[i];
		i++;
	}
	return (i);
}

/**
 * _printf - custome printf function
 * @format: string to be printed with it's idntifiers
 * Return: string
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int len = 0;
	int size = 0;
	int i = 0;
	int j = 0;
	va_list list;
	char *buffer, *str;
	char* (*fn)(va_list);
	char length_modifier = '\0';
	char flag = '\0';

	if (!format)
		return (-1);
	buffer = make_buffer();
	if (!buffer)
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
				va_end(list);
				free(buffer);
				return (-1);
			}
			if (format[i] == '%')
			{
				len = buffer_overflow_check(buffer, len);
				buffer[len++] = format[i], size++;
			}
			else
			{
				i = check_length_modifier(format, i, &length_modifier);
				while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
                {
                    flag = format[i];
                    i++;
                }
				fn = select_function(format[i], length_modifier, flag);
				/*fn = select_function(format[i]);*/
				if (!fn)
				{
					len = buffer_overflow_check(buffer, len);
					buffer[len++] = '%';
					size++;
					buffer[len++] = format[i];
					size++;
				}
				else
				{
					str = fn(list);
					if (!str)
					{
						va_end(list);
						free(buffer);
						return (-1);
					}
					if (format[i] == 'c' && str[0] == '\0')
					{
						len = buffer_overflow_check(buffer, len);
						buffer[len++] = '\0', size++;
					}
					/* Handle flag characters*/
                    if (flag == '+')
                    {
                        if (str[0] != '-')
                        {
                            len = buffer_overflow_check(buffer, len);
                            buffer[len++] = '+';
                            size++;
                        }
                    }
                    else if (flag == ' ')
                    {
                        if (str[0] != '-' && str[0] != '+')
                        {
                            len = buffer_overflow_check(buffer, len);
                            buffer[len++] = ' ';
                            size++;
                        }
                    }
                    else if (flag == '#')
                    {
                        /* Handle '#' flag (specific to certain conversions)
                        / Add your implementation here if needed*/
                    }
					j = 0;
					while (str[j] != '\0')
					{
						len = buffer_overflow_check(buffer, len);
						buffer[len++] = str[j];
						size++;
						j++;
					}
					free(str);
				}
			} i++;
		}
	} print_buffer(buffer, len, list);
	return (size);
}
