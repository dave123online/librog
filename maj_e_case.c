/*
** EPITECH PROJECT, 2025
** my_put_sciE
** File description:
** a function to display scientific form of numbers
*/

#include "librog.h"

static int zecond_case(double nb, int i, double n)
{
    int j = (int) nb;
    int count = 0;

    if (nb > 1) {
        for (i = 0; j > 10; i++) {
            nb /= 10;
            j = (int) nb;
        }
        n = (n / my_pow(10, i));
        count += my_put_floats(n);
        if (i < 10) {
            count += my_putstr("E+0");
            count += my_put_nbr(i);
        } else {
            count += my_putstr("E+");
            count += my_put_nbr(i);
        }
    }
    return count;
}

int maj_e_case(double nb)
{
    int i = 0;
    int j = (int) nb;
    double n = nb;
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        n = -n;
        j = (int) nb;
        count++;
    }
    if (nb < 1) {
        for (i = 0; j < 1; i++) {
            nb *= 10;
            j = (int) nb;
        }
        n = (n * my_pow(10, i));
        count += my_put_floats(n);
        if (i < 10) {
            count += my_putstr("E-0");
            count += my_put_nbr(i);
        } else {
            count += my_putstr("E-");
            count += my_put_nbr(i);
        }
    } else
        count += zecond_case(nb, i, n);
    return count;
}
