#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char _ischar(va_list list);
int _printf(const char *format, ...);

#endif
