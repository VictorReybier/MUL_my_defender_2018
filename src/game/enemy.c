/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** enemy
*/

#include "../../include/my.h"

/*typedef struct game {
    sfRenderWindow *window;
    sfClock *gtime;
    sfSprite *map;
    int score;
    int obj_hp;
    int difficulty;
} game_t;*/

enemy_t *init_enemy(game_t *game, enemy_t *enemy);
double dist(sfVector2f a, sfVector2f b);

int enemy_direction(enemy_t *enemy)
{
    sfVector2f vector;

    if (enemy == NULL)
        return (1);
    vector = sfSprite_getPosition(enemy->sprite);
    if ((int)vector.y == 290 && (int)vector.x >= 190 && (int)vector.x <= 250) {
        enemy->direction = 1;
        sfSprite_setPosition(enemy->sprite, (sfVector2f){190, 289});
    }
    if ((int)vector.x == 190 && (int)vector.y <= 170 && (int)vector.y >= 100) {
        enemy->direction = 2;
        sfSprite_setPosition(enemy->sprite, (sfVector2f){191, 170});
    }
    if ((int)vector.y == 170 && (int)vector.x >= 575 && (int)vector.x <= 600) {
        enemy->direction = 3;
        sfSprite_setPosition(enemy->sprite, (sfVector2f){575, 171});
    }
    if ((int)vector.x == 575 && (int)vector.y >= 410 && (int)vector.y <= 450) {
        enemy->direction = 2;
        sfSprite_setPosition(enemy->sprite, (sfVector2f){576, 410});
    }
    return (enemy_direction(enemy->next));
}

int enemy_move(enemy_t *enemy)
{
    sfVector2f vector;

    if (enemy == 0 || sfClock_getElapsedTime(enemy->move).microseconds < 10000)
        return (0);
    vector = (sfVector2f){0, -enemy->speed};
    if (enemy->direction == 2)
        vector = (sfVector2f){enemy->speed, 0};
    if (enemy->direction == 3)
        vector = (sfVector2f){0, enemy->speed};
    sfSprite_move(enemy->sprite, vector);
    sfClock_restart(enemy->move);
    return (enemy_move(enemy->next));
}

enemy_t *enemy_remove(enemy_t *enemy, enemy_t *save_enemy)
{
    if (enemy == save_enemy)
        save_enemy = save_enemy->next;
    else if (enemy->next == NULL) {
        while (save_enemy->next->next != NULL)
            save_enemy = save_enemy->next;
        save_enemy->next = NULL;
    }
    else {
        while (save_enemy->next != enemy);
        save_enemy->next = enemy->next;
    }
    return (save_enemy);
}

enemy_t *enemy_life(enemy_t *enemy)
{
    static enemy_t *save_enemy = NULL;

    if (save_enemy == NULL)
        save_enemy = enemy;
    if (enemy->hp <= 0)
        save_enemy = enemy_remove(enemy, save_enemy);
    if (enemy->next == NULL) {
        enemy = save_enemy;
        save_enemy = NULL;
        return (enemy);
    }
    return (enemy_life(enemy->next));
}

void enemy_draw(game_t *game, enemy_t *enemy)
{
    for (; enemy != NULL; enemy = enemy->next)
        sfRenderWindow_drawSprite(game->window, enemy->sprite, NULL);
}

int enemy_spawn(game_t *game, enemy_t *enemy)
{
    for (; enemy != NULL; enemy = enemy->next)
        if (enemy->move == NULL) {
            enemy->move = sfClock_create();
            break;
        }
    if (enemy == NULL)
        return (0);
    sfClock_restart(game->gtime);
    return (1);
}

void tower_shoot(enemy_t *enemy, tower_t **tower, int j, game_t *game)
{
    double size = dist(sfRectangleShape_getPosition(tower[j - 1]->rectangle), sfSprite_getPosition(enemy->sprite));
    if (size < 150 && tower[j - 1]->type == 3 && sfTime_asSeconds(sfClock_getElapsedTime(tower[j - 1]->time)) >= 1.3) {
        sfSprite_setPosition(enemy->sprite, (sfVector2f){-100, 290});
        sfClock_restart(tower[j - 1]->time);
    }
    if (size < 150 && tower[j -1]->type == 1)
        enemy->speed = 0.6;
    if (size > 150 && tower[j - 1]->type == 1)
        enemy->speed = 1;
    if (size > 150 && tower[j - 1]->type == 4 && sfTime_asSeconds(sfClock_getElapsedTime(tower[j - 1]->time)) >= 1) {
        sfClock_restart(tower[j - 1]->time);
        game->money += 20;
    }
    if (tower[j - 1]->type == 2  && sfTime_asSeconds(sfClock_getElapsedTime(tower[j - 1]->time)) >= 10) {
        sfClock_restart(tower[j - 1]->time);
        game->obj_hp++;
    }
        
}

enemy_t *enemy_update(game_t *game, enemy_t *enemy, tower_t **tower)
{
    enemy_t *enemy_initi = enemy;
    enemy_direction(enemy);
    enemy_move(enemy);
    enemy_draw(game, enemy);
    for (; enemy != NULL; enemy = enemy->next)
        if (sfSprite_getPosition(enemy->sprite).x > 800 && game->obj_hp > 0) {
            sfSprite_setPosition(enemy->sprite, (sfVector2f){-10000, 1000});
            game->obj_hp--;
        }
    for (int j = 0; j <= 8; j++) {
        for (; enemy != NULL; enemy = enemy->next) {
            tower_shoot(enemy, tower, j, game);
        }
        enemy = enemy_initi;
    }
    return (enemy);
}

void enemy_info(enemy_t *enemy)
{
    for (int i = 0; enemy != NULL; i++) {
        printf("------------------\n");
        printf("-------MOB  %i-----\n", i);
        printf("------------------\n");
        printf("    hp = %i\n", enemy->hp);
        printf("    speed = %f\n", enemy->speed);
        printf("    direction = %i\n", enemy->direction);
        printf("    pos = %f; %f\n", sfSprite_getPosition(enemy->sprite).x, sfSprite_getPosition(enemy->sprite).y);
        printf("\n");
        enemy = enemy->next;
    }
}

enemy_t *init_enemy(game_t *game, enemy_t *enemy)
{
    sfTexture *texture = sfTexture_createFromFile("src//sprite/monster/a.png", 0);
    enemy_t *save_enemy = malloc(sizeof(enemy_t));
    static int offset = 0;

    enemy = save_enemy;
    for (int i = 0; 1; ++i) {
        //printf("init 2\n");
        offset++;
        enemy->next = NULL;
        enemy->move = sfClock_create();
        enemy->sprite = sfSprite_create();
        sfSprite_setTexture(enemy->sprite, texture, sfTrue);
        sfSprite_setScale(enemy->sprite, (sfVector2f){0.2, 0.2});
        sfSprite_setOrigin(enemy->sprite, (sfVector2f){180, 180});
        sfSprite_setPosition(enemy->sprite, (sfVector2f){offset * -100 + 100, 290});
        enemy->direction = 2;
        enemy->speed = 1;
        enemy->hp = 10;
        if (i > 70)
            break;
        enemy->next = malloc(sizeof(enemy_t));
        enemy = enemy->next;
    }
    offset = 0;
    return (save_enemy);
}