/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        ++i;
    return (i);
}