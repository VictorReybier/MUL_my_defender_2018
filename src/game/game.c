/*
** EPITECH PROJECT, 2019
** MUL_my_defender_201
** File description:
** game
*/

#include "../../include/my.h"



/*typedef struct enemy {
    sfSprite *sprite;
    sfClock *move;
    int direction;
    float speed;
    int hp;
    struct enemy *next;
} enemy_t;*/

/*typedef struct game {
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
} game_t;*/

typedef struct buy_menu {
    sfRectangleShape *type[4];
    sfText *slow;
    sfText *zone;
    sfText *shoot;
    sfText *farm;
    sfFont *font;
} buy_menu_t;

enemy_t *enemy_update(game_t *game, enemy_t *enemy, tower_t *tower);

enemy_t *init_enemy(game_t *game, enemy_t *enemy);

int game_difficulty(game_t *game)
{
    if (sfClock_getElapsedTime(game->gtime).microseconds >= 60000000) {//ATTENTION TIMER
        game->difficulty += 1;
    }
    return (0);
}

double my_sqrt(double max);

double dist(sfVector2f a, sfVector2f b)
{
    double size = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
    size = my_sqrt(size);
    return (size);
}

/*void towers_canno(game_t *game, enemy_t *enemy, tower_t *tower)
{
    static sfRectangleShape *canno = NULL;
    sfVector2f place = {0, 0};

    if (tower == NULL)
        return;
    if (canno == NULL) {
        canno = sfRectangleShape_create();
        sfRectangleShape_setFillColor(canno, sfBlack);
        sfRectangleShape_setSize(canno, (sfVector2f){40, 10});
        sfRectangleShape_setOrigin(canno, (sfVector2f){40, 5});
    }
    //if (tower->level > 0) {
        place = sfRectangleShape_getPosition(tower->rectangle);
        place = (sfVector2f){place.x + 25, place.y + 25};
        sfRectangleShape_setPosition(canno, place);
        for (enemy_t *enemy_switch = enemy; enemy_switch != NULL; enemy_switch = enemy_switch->next)
            if (enemy_switch->hp > 0 && tower->range >= dist(sfRectangleShape_getPosition(tower->rectangle), sfSprite_getPosition(enemy->sprite))) {
                printf("SHOOT: %f\n", dist(sfRectangleShape_getPosition(tower->rectangle), sfSprite_getPosition(enemy->sprite)));
                break;
            }
        //sfRectangleShape_setRotation(canno, 90);
        sfRenderWindow_drawRectangleShape(game->window, canno, NULL);
    //}
    return (towers_canno(game, enemy, tower->next));
}*/

void tower_buy_show(game_t *game, tower_t *tower, buy_menu_t *buy)
{
    sfEvent event;
    sfVector2f vec[4] = {{20, 480}, {140, 480}, {260, 480}, {380, 480}};

    if (*buy->type == NULL) {
        buy->font = sfFont_createFromFile("src/font/font.ttf");
        for (int i = 0; i < 4; ++i) {
            buy->type[i] = sfRectangleShape_create();
            sfRectangleShape_setSize(buy->type[i], (sfVector2f){100, 100});
            sfRectangleShape_setPosition(buy->type[i], vec[i]);
            sfRectangleShape_setOutlineThickness(buy->type[i], 4);
            sfRectangleShape_setOutlineColor(buy->type[i], sfRed);
        }
        buy->slow = sfText_create();
        sfText_setFont(buy->slow, buy->font);
        sfText_setColor(buy->slow, sfBlue);
        sfText_setCharacterSize(buy->slow, 20);
        sfText_setString(buy->slow, "Slow\n\nCost=100");
        sfText_setPosition(buy->slow, (sfVector2f){25, 480});
        buy->zone = sfText_create();
        sfText_setFont(buy->zone, buy->font);
        sfText_setColor(buy->zone, sfBlue);
        sfText_setCharacterSize(buy->zone, 20);
        sfText_setString(buy->zone, "Heal\n\nCost=100");
        sfText_setPosition(buy->zone, (sfVector2f){145, 480});
        buy->shoot = sfText_create();
        sfText_setFont(buy->shoot, buy->font);
        sfText_setColor(buy->shoot, sfBlue);
        sfText_setCharacterSize(buy->shoot, 20);
        sfText_setString(buy->shoot, "Shoot\n\nCost=200");
        sfText_setPosition(buy->shoot, (sfVector2f){265, 480});
        buy->farm = sfText_create();
        sfText_setFont(buy->farm, buy->font);
        sfText_setColor(buy->farm, sfBlue);
        sfText_setCharacterSize(buy->farm, 20);
        sfText_setString(buy->farm, "Farm\n\nCost=50");
        sfText_setPosition(buy->farm, (sfVector2f){385, 480});
    }
    sfRenderWindow_drawRectangleShape(game->window, *buy->type, NULL);
    sfRenderWindow_drawRectangleShape(game->window, buy->type[1], NULL);
    sfRenderWindow_drawRectangleShape(game->window, buy->type[2], NULL);
    sfRenderWindow_drawRectangleShape(game->window, buy->type[3], NULL);
    sfRenderWindow_drawText(game->window, buy->slow, NULL);
    sfRenderWindow_drawText(game->window, buy->zone, NULL);
    sfRenderWindow_drawText(game->window, buy->shoot, NULL);
    sfRenderWindow_drawText(game->window, buy->farm, NULL);
    //90 45       205
}

void tower_upg(game_t *game, tower_t *tower)
{
    static sfRectangleShape *type = NULL;
    static sfText *type2 = NULL;
    static sfText *level = NULL;
    static sfText *damage = NULL;
    static sfText *deley = NULL;
    static sfText *range = NULL;
    static sfFont *font = NULL;

    if (type == NULL) {
        font = sfFont_createFromFile("src/font/font.ttf");
        type = sfRectangleShape_create();
        sfRectangleShape_setFillColor(type, sfWhite);
        sfRectangleShape_setSize(type, (sfVector2f){100, 100});
        sfRectangleShape_setPosition(type, (sfVector2f){20, 480});
        sfRectangleShape_setOutlineThickness(type, 4);
        sfRectangleShape_setOutlineColor(type, sfRed);
        level = sfText_create();
        sfText_setFont(level, font);
        sfText_setColor(level, sfBlue);
        sfText_setCharacterSize(level, 20);
        sfText_setPosition(level, (sfVector2f){130, 480});
        type2 = sfText_create();
        sfText_setFont(type2, font);
        sfText_setColor(type2, sfBlue);
        sfText_setCharacterSize(type2, 20);
        sfText_setPosition(type2, (sfVector2f){130, 500});
    }
    sfText_setString(level, "Level: Null");
    sfText_setString(type2, (char [7]){'t', 'y', 'p', 'e', ' ', tower->type + 48, 0});
    sfRenderWindow_drawRectangleShape(game->window, type, NULL);
    sfRenderWindow_drawText(game->window, level, NULL);
    sfRenderWindow_drawText(game->window, type2, NULL);
}

void tower_ui(game_t *game, tower_t **tower)
{
    static sfRectangleShape *bg = NULL;
    static buy_menu_t buy[] = 
    {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    if (bg == NULL) {
        bg = sfRectangleShape_create();
        sfRectangleShape_setFillColor(bg, sfBlack);
        sfRectangleShape_setSize(bg, (sfVector2f){500, 140});
        sfRectangleShape_setPosition(bg, (sfVector2f){0, 460});
    }
    sfRenderWindow_drawRectangleShape(game->window, bg, NULL);
    if (game->tower_select == NULL)
        return;
    else if (game->tower_select->type == 0)
        tower_buy_show(game, game->tower_select, buy);
    else
        tower_upg(game, game->tower_select);

    /*if (tower->level > 0) {
        for (enemy_t *enemy_switch = enemy; enemy_switch != NULL; enemy_switch = enemy_switch->next)
            if (enemy_switch->hp > 0 && tower->range >= dist(sfRectangleShape_getPosition(tower->rectangle), sfSprite_getPosition(enemy->sprite))) {
                printf("SHOOT: %f\n", dist(sfRectangleShape_getPosition(tower->rectangle), sfSprite_getPosition(enemy->sprite)));
                break;
            }
        //sfRectangleShape_setRotation(bg, 90);
    }*/
}

void towers_base(game_t *game, tower_t **tower)
{
    sfRectangleShape *rect = NULL;

    for (int i = 0; i < 8; ++i)
        if (tower[i]->type != 0) {
            rect = tower[i]->rectangle;
            sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
        }
    return;
}

tower_t **update_tower(game_t *game, enemy_t *enemy, tower_t **tower)
{
    tower_ui(game, tower);
    towers_base(game, tower);
    return (tower);
}

char *int_to_string(int nb)
{
    int pow = 1;
    int nbcpy = nb;
    char *buffer = malloc(sizeof(char) * 4);
    int i = 0;
    while (nbcpy > 9) {
        pow = pow * 10;
        nbcpy = nbcpy / 10;
    }
    while (nb > 9) {
        buffer[i] = nb / pow + 48;
        nb = nb % pow;
        pow = pow / 10;
        i++;
    }
    buffer[i] = nb + 48;
    buffer[i + 1] = '\0';
    return (buffer);
}

void draw_money(game_t *game)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("src/font/font.ttf");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setString(text, int_to_string(game->money));
    sfText_setPosition(text, (sfVector2f){600, 20});
    sfText_setColor(text, sfYellow);
    sfRenderWindow_drawText(game->window, text, NULL);
}

void draw_life(game_t *game)
{
    sfEvent event;
    sfTexture *texture = sfTexture_createFromFile("src/sprite/heart.png", 0);
    sfSprite *sprite;
    for (int i = 0; i < game->obj_hp; i++) {
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setScale(sprite, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(sprite, (sfVector2f){10 + (i * 50), 20});
        sfRenderWindow_drawSprite(game->window, sprite, NULL);
    }
    sfTexture *text_go = sfTexture_createFromFile("src/sprite/game_over.jpg", 0);
    sfSprite *sprite_go = sfSprite_create();
    sfSprite_setTexture(sprite_go, text_go, sfTrue);
    sfSprite_setScale(sprite_go, (sfVector2f){1.9, 2.5});
    if (game->obj_hp == 0)
        sfRenderWindow_drawSprite(game->window, sprite_go, NULL);
}

int update(game_t *game, enemy_t *enemy, tower_t **tower)
{
    sfRenderWindow_clear(game->window, sfRed);
    sfRenderWindow_drawSprite(game->window, game->map, NULL);
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->mtime)) > 100) {
        sfClock_restart(game->mtime);
        game->money += 3;
    }
    enemy = enemy_update(game, enemy, tower);
    tower = update_tower(game, enemy, tower);
    draw_money(game);
    draw_life(game);
    sfRenderWindow_display(game->window);
}

game_t *init_game(game_t *game, sfRenderWindow *window)
{
    sfTexture *map_texture = sfTexture_createFromFile("src/sprite/map.png", NULL);

    game->difficulty = 1;
    game->gtime = sfClock_create();
    game->mtime = sfClock_create();
    game->money = 100;
    game->obj_hp = 5;
    game->score = 0;
    game->map = sfSprite_create();
    game->window = window;
    game->tower_select = NULL;
    sfSprite_setTexture(game->map, map_texture, sfTrue);
    sfSprite_scale(game->map, (sfVector2f){0.5, 0.5});
    return (game);
}

sfRectangleShape *rectangle_init(int nb[4], sfColor color[2], int thickness);

tower_t **inti_tower(game_t *game, tower_t **tower)
{
    sfVector2f pos[8] = {{447, 269}, {273, 269}, {450, 395}, {660, 311},
    {665, 523}, {346, 69}, {65, 184}, {61, 398}};

    tower = malloc(sizeof(tower_t *) * 9);
    for (int i = 0; i < 8; ++i) {
        tower[i] = malloc(sizeof(tower_t));
        tower[i]->rectangle = sfRectangleShape_create();
        sfRectangleShape_setPosition(tower[i]->rectangle, pos[i]);
        sfRectangleShape_setSize(tower[i]->rectangle, (sfVector2f){50, 50});
        sfRectangleShape_setOutlineThickness(tower[i]->rectangle, 4);
        sfRectangleShape_setOutlineColor(tower[i]->rectangle, sfColor_fromRGB(102,102,102));
        tower[i]->type = 0;
        tower[i]->damage = 0;
        tower[i]->deley = 0;
        tower[i]->level = 0;
        tower[i]->range = 0;
        tower[i]->time = sfClock_create();
    }
    tower[8] = NULL;
    return (tower);
}

int square_click(sfVector2i mouse, sfVector2i vec, int size)
{
    if (mouse.x >= vec.x && mouse.x <= vec.x + size)
        if (mouse.y >= vec.y && mouse.y <= vec.y + size)
            return (1);
    return (0);
}

int buy_turret(game_t *game, int i)
{
    if (i == 0)
        if (game->money >= 50) {
            game->money -= 50;
            return (1);
        }
    if (i == 1)
        if (game->money >= 100) {
            game->money -= 100;
            return (1);
        }
    if (i == 2)
            if (game->money >= 230) {
            game->money -= 200;
            return (1);
            }
    if (i == 3)
        if (game->money >= 130) {
            game->money -= 100;
            return (1);
        }
}

int mousebuttonpressed(game_t *game, tower_t **tower)
{
    sfColor color[4] = {sfGreen, sfRed, sfBlack, sfYellow}; 
    sfVector2i vec[4] = {{20, 480}, {140, 480}, {260, 480}, {380, 480}};
    sfVector2i mousepose = sfMouse_getPositionRenderWindow(game->window);
    sfRectangleShape *rect = NULL;
    int i = 0;

    if (game->obj_hp == 0)
        return (0);
    for (; i < 8 && button_click(game->window, tower[i]->rectangle) == 0;)
        ++i;
    if (i != 8)
        game->tower_select = tower[i];
    if (i != 8 || game->tower_select == NULL || game->tower_select->type != 0)
        return (1);
    for (i = 0; i < 4; ++i)
        if (square_click(mousepose, vec[i], 100) && buy_turret(game, i) == 1) {
            game->tower_select->type = i + 1;
            rect = game->tower_select->rectangle;
            game->money -= 100;
            sfRectangleShape_setFillColor(rect, color[i]);
        }
    return (1);
}

int event(game_t *game, enemy_t *enemy, tower_t **tower)
{
    int i = 0;
    sfEvent ev;

    if (sfRenderWindow_pollEvent(game->window, &ev) == 0)
        return (1);
    if (ev.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (ev.type == sfEvtKeyPressed)
        if (ev.key.code == sfKeyEscape)
            main_menu(game->window);
    if (ev.type == sfEvtMouseButtonPressed)
        if (mousebuttonpressed(game, tower) == 0)
            return (0);
    return (event(game, enemy, tower));
}

int play(sfRenderWindow *window)
{
    game_t *game = init_game(malloc(sizeof(game_t)), window);
    enemy_t *enemy = init_enemy(game, enemy);
    tower_t **tower = inti_tower(game, tower);

    while (sfRenderWindow_isOpen(window)) {
        if (event(game, enemy, tower) == 0)
            return (0);
        update(game, enemy, tower);
    }
}