/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** rectangle
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

sfRectangleShape *rectangle_init(int nb[4], sfColor color[2], int thickness)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setOrigin(rect, (sfVector2f){nb[2] / 2, nb[3] / 2});
    sfRectangleShape_setPosition(rect, (sfVector2f){nb[0], nb[1]});
    sfRectangleShape_setSize(rect, (sfVector2f){nb[2], nb[3]});
    sfRectangleShape_setFillColor(rect, color[0]);
    sfRectangleShape_setOutlineThickness(rect, thickness);
    sfRectangleShape_setOutlineColor(rect, color[1]);
    return (rect);
}