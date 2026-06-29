/*
** EPITECH PROJECT, 2025
** my_pow
** File description:
** a recoding of libC pow
*/

#include "librog.h"
int my_pow(int x, int y)
{
    int i = 1;
    int n = x;

    if (y < 0)
        return 0;
    if (y == 0)
        return 1;
    while (i < y) {
        x *= n;
        i++;
    }
    return x;
}
