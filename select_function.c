#include "main.h"

/**
 * select_function - function that select the required function
 * @c: function identifier
 * @length_modifier: modify length
 * Return: point to required function
 */

char *(*select_function(char c, char length_modifier, char flag))(va_list)
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
			if (flag == '#')
			{
				switch (c)
				{
					case 'o':
						return &octal_with_prefix;
					case 'x':
						return &hex_with_prefix;
					case 'X':
						return &hex_with_prefix_upper;
					default:
						break;
				}
			}
			if (flag == '0' && (c == 'd' || c == 'i'))
            {
                switch (length_modifier)
                {
                    case '\0':
                        return &_izero_padded_integer;
                    case 'h':
                        return &_izero_padded_shortint;
                    case 'l':
                        return &_izero_padded_longint;
                    default:
                        break;
                }
            }
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
						return (_xhshortint);
					case 'X':
						return (_xhuppershortint);
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
						return (_xhlongint);
					case 'X':
						return (_xhupperlongint);
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
