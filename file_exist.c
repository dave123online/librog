/*
** EPITECH PROJECT, 2025
** file_exist
** File description:
** check if a file exists
*/

#include "librog.h"
#include <sys/stat.h>

int file_exist(char *filepath)
{
    struct stat st;

    if (!filepath)
        return 0;
    return (stat(filepath, &st) == 0);
}
