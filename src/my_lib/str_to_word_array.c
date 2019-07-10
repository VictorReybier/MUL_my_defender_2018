/*
** EPITECH PROJECT, 2019
** zoulou
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include "../../include/my_lib.h"

char **str_to_word_array(char *str, char separator)
{
    char **array = NULL;
    int size = 1;
    int y = 0;

    for (int i = 0; str[i]; ++i)
        size += str[i] == separator;
    array = malloc(sizeof(char *) * ++size);
    array[y] = char_add_in_str(NULL, str[0]);
    for (int i = 1; str[i]; ++i) {
        if (str[i] == separator)
            array[++y] = char_add_in_str(NULL, str[++i]);
        else
            array[y] = char_add_in_str(array[y], str[i]);
        
    }
    array[++y] = NULL;
    free(str);
    return (array);
}