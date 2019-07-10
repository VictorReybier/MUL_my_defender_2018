/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** text
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../../include/my_lib.h"

sfText *text_init(char *str, sfVector2f position)
{
    sfFont *font = sfFont_createFromFile("src/font/font.ttf");
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, position);
    sfText_setOrigin(text, (sfVector2f){(30 * my_strlen(str)) / 2, 30});
    return (text);
}