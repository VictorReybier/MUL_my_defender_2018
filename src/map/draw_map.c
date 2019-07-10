/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** draw_map
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../../include/my_lib.h"

char *trans_to_pnj(char type)
{
    char path[11] = "src//sprite/.pnj";
    char *str = malloc(sizeof(char) * 14);
    int i = 0;

    for (; i < 7; ++i)
        str[i] = path[i];
    str[i++] = type;
    for (; i < 12; ++i)
        str[i] = path[i - 1];
    str[i] = 0;
    printf("%s", str);
    return (str);
}

void draw_map(char **map, sfRenderWindow *window)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = NULL;

    for (int y = 0; map[y]; ++y) {
        for (int x = 0; map[y][x]; ++x) {
            trans_to_pnj(map[y][x]);
            printf("%c   ", map[y][x]);/*
            sfSprite_setPosition(sprite, (sfVector2f){y * 10, x * 10});
            texture = sfTexture_createFromFile(trans_to_pnj(map[y][x]), NULL);
            sfSprite_setTexture(sprite, texture, NULL);
            sfRenderWindow_drawSprite(window, sprite, NULL);
        */}
    }
    while (1);
}

//50 x 20 | 800 x 600