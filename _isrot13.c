#include "main.h"

/**
 * _isrot13 - function that encrypt string with rot13
 * @list: argument
 * Return: encrypted string
 */
char *_isrot13(va_list list)
{
	int i = 0;
	char *str;
	char *ptr;

	str = va_arg(list, char *);

	ptr = malloc(sizeof(char) * (_strlen(str) + 1));
	if (ptr == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'm') ||
				(str[i] >= 'A' && str[i] <= 'M'))
		{
			ptr[i] = str[i] + 13;
		}
		else if ((str[i] >= 'n' && str[i] <= 'z') ||
				(str[i] >= 'N' && str[i] <= 'Z'))
		{
			ptr[i] = str[i] - 13;
		}
		else
			(ptr[i] = str[i]);
		i++;
	}
	ptr[i] = '\0';

	return (ptr);
}
