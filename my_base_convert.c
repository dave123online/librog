/*
** EPITECH PROJECT, 2025
** my_base_converter
** File description:
** as said by the name
*/

#include "librog.h"
int my_base_convert(int nb, char *digits)
{
    int count = 0;
    int i;
    int base_len;
    char buffer[12];

    if (nb == 0) {
        my_putchar(digits[0]);
        return 1;
    }
    base_len = my_strlen(digits);
    for (i = 0; nb != 0; i++) {
        buffer[i] = digits[nb % base_len];
        nb /= base_len;
    }
    for (i--; i >= 0; i--) {
        count += my_putchar(buffer[i]);
    }
    return count;
}
