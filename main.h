#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct options - struct
 * @id: identifier
 * @func: pointer to function that select data type to print
 */

typedef struct options
{
        char id;
        char* (*func)(va_list);
} print_option;

char* (*select_function(char c))(va_list);
char *make_buffer(void);
void print_buffer(char *ptr, int len, va_list list);

char *_ischar(va_list list);
char *_istring(va_list list);
char *_ispercent(void);
int _printf(const char *format, ...);

#endif
