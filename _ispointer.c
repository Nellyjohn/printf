#include "main.h"

/**
 * _ishex - function that convert int to hex
 * @num: int value to convert
 * Return: returned converted hex as a dynamically allocated string
 */

char *_ishex(unsigned long int num)
{
    long int i, cn = 0;
    unsigned long int tem = num;
    char *result, *ptr;
	int digit;

    while (num / 16 != 0)
    {
        num = num / 16;
        cn++;
    }
    cn++;
    result = malloc(sizeof(char) * (cn + 1));
    if (!result)
        return NULL;

    ptr = result;

    for (i = cn - 1; i >= 0; i--)
    {
		digit = tem % 16;
        ptr[i] = (digit < 10) ? (digit + '0') : (digit + 'a' - 10);
        tem = tem / 16;
    }
    ptr[cn] = '\0';

    return (result);
}

/**
 * _ispointer - function that return pointer
 * @list: argument
 * Return: value
 */

char *_ispointer(va_list list)
{
    void *ptr;
    char *str = "(NULL)", *hex_str, *result;
    int i;
    unsigned long int l;

    ptr = va_arg(list, void *);
    if (!ptr)
    {
        result = malloc(sizeof(char) * 6);
        if (!result)
            return NULL;
        for (i = 0; str[i] != '\0'; i++)
            result[i] = str[i];
        result[i] = '\0';
        return result;
    }
    l = (unsigned long int)ptr;
    hex_str = _ishex(l);
    result = malloc(sizeof(char) * (_strlen(hex_str) + 3));
    if (!result)
        return NULL;
    result[0] = '0';
    result[1] = 'x';
    for (i = 0; hex_str[i] != '\0'; i++)
        result[i + 2] = hex_str[i];
    result[i + 2] = '\0';
    free(hex_str);
    return (result);
}
