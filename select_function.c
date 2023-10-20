#include "main.h"

/**
 * select_function - function that select the required function
 * @c: function identifier
 * @length_modifier: modify length
 * Return: point to required function
 */

char* (*select_function(char c, char length_modifier))(va_list)
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
		{'S', _is_special_string},
		{'p', _ispointer},
		{'r', _isreversed_string},
		{'R', _isrot13},
		{'\0', NULL}
	};

	while (chart[j].id != '\0')
	{
		/**
		 * if (chart[j].id == c)
		  * {
		  * return (chart[j].func);
		  * }
		  * j++;
		  */

		if (chart[j].id == c)
		{
			/*Check for length modifiers*/
			if (length_modifier == 'h')
			{
				switch (c)
				{
					case 'd':
					case 'i':
						return (_ishortint);
					case 'u':
						return (_uhshortint);
					case 'o':
						return (_ohshortint);
					case 'x':
					case 'X':
						return (_xhshortint);
				}
			}
			else if (length_modifier == 'l')
			{
				switch (c)
				{
					case 'd':
					case 'i':
						return (_islongint);
					case 'u':
						return (_uhlongint);
					case 'o':
						return (_ohlongint);
					case 'x':
					case 'X':
						return (_xhlongint);
				}
			}
			else
			{
				return (chart[j].func);
			}
		}
		j++;
	}
	return (NULL);
}
