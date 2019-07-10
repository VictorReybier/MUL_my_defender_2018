/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/sfx.h"
#include "../include/menu.h"

int main(int ac, char **av)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = NULL;

    if (ac != 1)
        return (84);
    window = sfRenderWindow_create(mode, "Defender", sfClose, NULL);
    if (main_menu(window))
        sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    return (0);
}