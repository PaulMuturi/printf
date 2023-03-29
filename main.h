#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
int spformat(char);
int print_reverse(int);
size_t _pow(size_t, int);
int print_int(size_t n, char);
int print_bin(int b);
int _printf(const char *format, ...);
int print_arg(va_list *args, char c);
#endif
