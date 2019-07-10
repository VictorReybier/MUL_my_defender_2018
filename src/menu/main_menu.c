/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** main_menu
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "../../include/sfx.h"
#include "../../include/menu.h"

int event_action(sfEvent event, sfRenderWindow *window,
sfRectangleShape *rect[4])
{
    int i = 0;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    else if (event.type == sfEvtMouseButtonReleased) {
        while (rect[i] && !button_click(window, rect[i]))
            ++i;
        if (i < 3) {
            return (i + 1);
        }
    }
    return (0);
}

int display(sfRenderWindow *window, sfText *text[3],
sfRectangleShape *rect[3], sfEvent event)
{
    int button = 0;

    sfRenderWindow_clear(window, sfYellow);
    sfRenderWindow_drawRectangleShape(window, *rect, NULL);
    sfRenderWindow_drawRectangleShape(window, rect[1], NULL);
    sfRenderWindow_drawRectangleShape(window, rect[2], NULL);
    sfRenderWindow_drawText(window, *text, NULL);
    sfRenderWindow_drawText(window, text[1], NULL);
    sfRenderWindow_drawText(window, text[2], NULL);
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window))
        while (sfRenderWindow_pollEvent(window, &event))
            switch (event_action(event, window, rect)) {
            case 1:
                return (play(window));
            case 2:
                return (option(window));
            case 3:
                return 1;
            }
}

int main_menu(sfRenderWindow *window)
{
    sfEvent event;
    sfText *text[4] = {text_init("Play", (sfVector2f){400, 100}), 0, 0, 0};
    sfRectangleShape *rect[4] = {0, 0, 0, 0};
    int pos[4] = {400, 100, 300, 100};
    int button = 0;

    text[1] = text_init("Options", (sfVector2f){400, 300});
    text[2] = text_init("Quit", (sfVector2f){400, 500});
    for (int i = 0; i < 3; ++i) {
        rect[i] = rectangle_init(pos, (sfColor [2]){sfRed, sfBlack}, 10);
        pos[1] += 200;
    }
    return (display(window, text, rect, event));
}