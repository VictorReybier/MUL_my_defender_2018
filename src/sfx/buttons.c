/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** buttons
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

int button_click(sfRenderWindow *window, sfRectangleShape *rect)
{
    int x = sfMouse_getPositionRenderWindow(window).x;
    int y = sfMouse_getPositionRenderWindow(window).y;
    int rect_x = sfRectangleShape_getPosition(rect).x;
    int rect_y = sfRectangleShape_getPosition(rect).y;
    int size_x = sfRectangleShape_getSize(rect).x;
    int size_y = sfRectangleShape_getSize(rect).y;

    rect_x -= sfRectangleShape_getOrigin(rect).x;
    rect_y -= sfRectangleShape_getOrigin(rect).y;
    if (x >= rect_x && x <= rect_x + size_x)
        if (y >= rect_y && y <= rect_y + size_y) {
            return (1);
        }
    return (0);
}