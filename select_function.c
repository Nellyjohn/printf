#include "main.h"

/**
 * select_function - function that select the required function
 * @c: function identifier
 * Return: point to required function
 */

char* (*select_function(char c))(va_list)
{
	int j = 0;

	print_option chart[] = {
		{'c', _ischar},
		{'s', _istring},
		{'d', _isinteger},
		{'i', _isinteger},
		{'b', _isbinary},
		{'u', _is_unsignedint},
		{'o', _isoctal},
		{'x', _is_hex_lower},
		{'X', _is_hex_upper},
		{'\0', NULL}
	};

	while (chart[j].id != '\0')
	{
		if (chart[j].id == c)
		{
			return (chart[j].func);
		}
		j++;
	}
	return (NULL);
}
