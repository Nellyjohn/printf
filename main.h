#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

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

/* printf helper functions */
char* (*select_function(char c, char length_modifier))(va_list);
char *make_buffer(void);
void print_buffer(char *ptr, int len, va_list list);
char _strlen(char *s);
char *_strcpy(char *str, char *s);
int buffer_overflow_check(char *ptr, int len);
char *int_to_string(int len, int digit);

char *_ischar(va_list list);
char *_istring(va_list list);
char _ispercent(void);
char *_isinteger(va_list list);
char *_isbinary(va_list list);
char *_is_unsignedint(va_list list);
char *_isoctal(va_list list);
char *_is_hex_lower(va_list list);
char *_is_hex_upper(va_list list);
char *_is_special_string(va_list list);
char *_ispointer(va_list list);
char *_isreversed_string(va_list list);
char *_isrot13(va_list list);
char *_ishortint(va_list list);
char *_islongint(va_list list);
char *_uhshortint(va_list list);
char *_uhlongint(va_list list);
char *_ohshortint(va_list list);
char *_ohlongint(va_list list);
char *_xhshortint(va_list list);
char *_xhlongint(va_list list);
int _printf(const char *format, ...);
char *_xhupperlongint(va_list list);
char *_xhuppershortint(va_list list);

#endif
