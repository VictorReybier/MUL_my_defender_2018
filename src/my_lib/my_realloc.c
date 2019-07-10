/*
** EPITECH PROJECT, 2019
** zoulou
** File description:
** my_realloc
*/

#include <stdlib.h>

char *my_realloc(char *ptr, int size)
{
    char *new_ptr = NULL;
    int i = 0;

    if (ptr == NULL)
        return (NULL);
    new_ptr = malloc(sizeof(char) * (size + 1));
    if (new_ptr == NULL) {
        free(ptr);
        return (NULL);
    }
    for (; i < size && ptr[i]; ++i)
        new_ptr[i] = ptr[i];
    new_ptr[i] = 0;
    free(ptr);
    return (new_ptr);
}