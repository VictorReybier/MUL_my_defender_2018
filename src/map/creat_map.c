/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** creat_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../include/my_lib.h"

char **creat_map(void)
{
    char **map = NULL;
    char *buffer = malloc(sizeof(char) * 1021);
    int fd = open("map/default.txt", O_RDONLY);

    buffer[read(fd, buffer, 1020)] = 0;
    map = str_to_word_array(buffer, '\n');
    map[20] = 0;
    return (map);
}