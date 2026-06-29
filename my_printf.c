/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** a own version of printf
*/

#include "librog.h"
int fake_flag(ccr_t format, int i, va_list args)
{
    char *flags = "dicseEfFpxXo%u";
    int x;

    for (x = 0; flags[x] != '\0'; x++) {
        if (flags[x] == format[i + 1])
            return print_sub1(format, i, args);
    }
    return my_putchar(format[i]) + my_putchar(format[i + 1]);
}

int my_printf(ccr_t format, ...)
{
    va_list args;
    int i;
    int count = 0;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            count += fake_flag(format, i, args);
            i++;
        } else {
            count += my_putchar(format[i]);
        }
    }
    va_end(args);
    return count;
}
