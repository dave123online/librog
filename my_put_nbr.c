/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** a integer displayer
*/

#include "librog.h"

int my_put_nbr(int nb)
{
    int i = 0;
    char tab[15];
    int count = 0;
    long n = nb;

    if (n < 0) {
        my_putchar('-');
        n = -n;
        count++;
    }
    if (n == 0) {
        my_putchar('0');
        count++;
    }
    while (n > 0) {
        tab[i] = (n % 10) + 48;
        n = n / 10;
        i++;
    }
    for (i--; i >= 0; i--) {
        count += my_putchar(tab[i]);
    }
    return count;
}
