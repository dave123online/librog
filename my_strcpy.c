/*
** EPITECH PROJECT, 2026
** librog
** File description:
** description
*/

#include <stdlib.h>
void my_strcpy(char *dst, char *src)
{
    int i = 0;

    if (dst == NULL || src == NULL)
        return;
    for (; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
}
