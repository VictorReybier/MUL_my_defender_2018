/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tower {
    sfRectangleShape *rectangle;
    int level;
    int type;
    int damage;
    int deley;
    int range;
    sfClock *time;
} tower_t;

typedef struct game {
    sfRenderWindow *window;
    sfClock *gtime;
    sfSprite *map;
    tower_t *tower_select;
    int pause;
    int score;
    int obj_hp;
    int difficulty;
    int money;
    sfClock *mtime;
} game_t;

typedef struct enemy {
    sfSprite *sprite;
    sfClock *move;
    int direction;
    float speed;
    int hp;
    struct enemy *next;
} enemy_t;


#endif