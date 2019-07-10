/*
** EPITECH PROJECT, 2019
** zoulou
** File description:
** char_add_in_str
*/

#include <stdlib.h>
#include "../../include/my_lib.h"

char *char_add_in_str(char *str, char add)
{
    int size = 0;

    if (str == NULL)
        str = malloc(sizeof(char) * 2);
    else {
        size = my_strlen(str);
        str = my_realloc(str, size + 1);
    }
    str[size] = add;
    str[++size] = 0;
    return (str);
}