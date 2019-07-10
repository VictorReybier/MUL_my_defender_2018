/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** pause
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

int pause(sfRenderWindow *window, sfEvent event)
{
    int stop = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            stop = sfEvtKeyPressed == sfKeyEscape;
        if (stop)
            return (1);
    }
    return (0);
}