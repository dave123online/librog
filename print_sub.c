/*
** EPITECH PROJECT, 2025
** print_sub
** File description:
** a sub function of my_printf
*/

#include <stdarg.h>
#include "librog.h"
int print_sub5(ccr_t format, int i, va_list args)
{
    switch (format[i + 1]) {
        case 'p':
            return my_put_ptr(va_arg(args, void *));
        default:
            break;
    }
    return 0;
}

int print_sub4(ccr_t format, int i, va_list args)
{
    int count = 0;

    switch (format[i + 1]) {
        case 'u':
            return 0;
        case 'X':
            return my_base_convert(va_arg(args, int), "0123456789ABCDEF");
        case 'c':
            return my_putchar(va_arg(args, int));
        default:
            break;
    }
    count += print_sub5(format, i, args);
    return count;
}

int print_sub3(ccr_t format, int i, va_list args)
{
    int count = 0;

    switch (format[i + 1]) {
        case 's':
            return my_putstr(va_arg(args, char *));
        case '%':
            return my_putchar('%');
        default:
            break;
    }
    count += print_sub4(format, i, args);
    return count;
}

int print_sub2(ccr_t format, int i, va_list args)
{
    int count = 0;

    switch (format[i + 1]) {
        case 'f':
        case 'F':
            return my_put_floats(va_arg(args, double));
        case 'e':
            return my_put_sci_e(va_arg(args, double));
        case 'E':
            return maj_e_case(va_arg(args, double));
        default:
            break;
    }
    count += print_sub3(format, i, args);
    return count;
}

int print_sub1(ccr_t format, int i, va_list args)
{
    int count = 0;

    switch (format[i + 1]) {
        case 'd':
        case 'i':
            return my_put_nbr(va_arg(args, int));
        case 'o':
            return my_base_convert(va_arg(args, int), "01234567");
        case 'x':
            return my_base_convert(va_arg(args, int), "0123456789abcdef");
        default:
            break;
    }
    count += print_sub2(format, i, args);
    return count;
}
