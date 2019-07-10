/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** sfx
*/

#ifndef SFX_H_
#define SFX_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

sfText *text_init(char *str, sfVector2f position);
sfRectangleShape *rectangle_init(int nb[4], sfColor color[2], int thickness);
int button_click(sfRenderWindow *window, sfRectangleShape *rect);

#endif