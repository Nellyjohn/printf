#include "main.h"

char _strlen(char *s);
char *_strcpy(char *str, char *s);

/**
  * _strcpy - cpoies string 2 into sring 1
  * @str: string 1
  * @s: string 2
  * Return: pointer to string 1
  */
char *_strcpy(char *str, char *s)
{
	int index = 0;

	while (s[index] != '\0')
	{
		str[index] = s[index];
		index++;
	}

	return (str);
}

/**
  * _strlen - prints the length of a string
  * @s: string
  * Return: length of the string
  */
char _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
  * _istring - prints a string
  * @list: list of arguments
  * Return: copy of the string
  */
char *_istring(va_list list)
{
	char *str;
	char *s = va_arg(list, char *);


	if (s == NULL)
		s = "(NULL)";

	str = malloc(sizeof(char) * (_strlen(s) + 1));
	if (!str)
		return (NULL);

	return (_strcpy(str, s));
}
