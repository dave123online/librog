/*
** EPITECH PROJECT, 2025
** my_put_floats
** File description:
** a function to display floats
*/

#include "librog.h"
int my_put_floats(double nb)
{
    int int_part;
    double dec_part;
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        count++;
    }
    int_part = (int) nb;
    dec_part = nb - int_part;
    count += my_put_nbr(int_part);
    if (int_part == nb)
        return count;
    my_putchar('.');
    count++;
    count += my_put_nbr((int) (dec_part * 10000));
    return count;
}
