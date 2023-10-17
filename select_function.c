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
		{'%', _ispercent},
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
