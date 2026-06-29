/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** a function that handle some parts of printf
*/

#include "librog.h"

static void write_stderr(char c)
{
    write(2, &c, 1);
}

static int putstr_stderr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write_stderr(str[i]);
        i++;
    }
    return i;
}

static int putnbr_stderr(int nb)
{
    int i = 0;
    char tab[12];
    int count = 0;
    long n = nb;

    if (n < 0) {
        write_stderr('-');
        n = -n;
        count++;
    }
    if (n == 0) {
        write_stderr('0');
        count++;
    }
    while (n > 0) {
        tab[i] = (n % 10) + 48;
        n = n / 10;
        i++;
    }
    for (i--; i >= 0; i--) {
        write_stderr(tab[i]);
        count++;
    }
    return count;
}

static void smnprintf(const char *format, int i, va_list args)
{
    switch (format[i + 1]) {
        case 'd':
        case 'i':
            putnbr_stderr(va_arg(args, int));
            break;
        case 's':
            putstr_stderr(va_arg(args, char *));
            break;
        case 'c':
            write_stderr(va_arg(args, int));
            break;
        case '%':
            write_stderr('%');
            break;
        default:
            write_stderr(format[i + 1]);
            break;
    }
}

int my_perror(const char *format, ...)
{
    va_list args;
    int i;
    int count = 0;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            smnprintf(format, i, args);
            i++;
        } else {
            write_stderr(format[i]);
            count++;
        }
    }
    va_end(args);
    return count;
}
