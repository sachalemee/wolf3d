/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** raycasting.c
*/
#include <math.h>
#include <stdlib.h>
#include "wolfengine.h"
#include "hmap.h"

/*
int insert_enemy_at_ordered_place(int insert_enemies,
    linked_list_t monsters_seen, thing_t *enemy)
{
    size_t i = 0;
    linked_node_t *new_node = malloc(sizeof(linked_node_t));

    if (list->is_burnt || list->len == 0 || new_node == NULL) {
        if (new_node == NULL)
            burn_list(list);
        free(new_node);
        return FAILURE;
    }
    rank = rank % list->len;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (i == rank) {
            *new_node = (linked_node_t){*node, value, free_function};
            *node = new_node;
            return SUCCESS;
        }
        i++;
    }
    return FAILURE;
}

    thing_t *last; // uninit?
    thing_t *prev; // uninit?
    int axis;
    int direction;

static bool item_is_greater(void *current_thing, void *comparison)
{
    thing_t *current_thing_struct = current_thing;
    monster_comparison_data_t *comparison_data = comparison;
    float value_to_check = 0;
    sfVector2f current_set = {0};
    sfVector3f calculation_values = {0};

    if (comparison_data->axis == VERTICAL_WALL) {
        calculation_values = (sfVector3f){comparison_data->last->coords.y,
            current_thing_struct->coords.y, comparison_data->prev->coords.y};
    } else
        calculation_values = (sfVector3f){comparison_data->last->coords.x,
            current_thing_struct->coords.x, comparison_data->prev->coords.x};


    if (comparison_data->axis == VERTICAL_WALL) {
        value_to_check = comparison_data->direction
            * comparison_data->last->coords.y;
        current_set = (sfVector2f){
            comparison_data->direction * current_thing_struct->coords.y,
            comparison_data->direction * comparison_data->prev->coords.y
        };
    } else {
        value_to_check = comparison_data->direction
            * comparison_data->last->coords.x;
        current_set = (sfVector2f){
            comparison_data->direction * current_thing_struct->coords.x,
            comparison_data->direction * comparison_data->prev->coords.x
        };
    }
    comparison_data->prev = comparison;
    return current_set.x <= value_to_check && value_to_check <= current_set.y;
}

static float get_vector_oriented_value(monster_comparison_data_t *data,
    sfVector2f *vector)
{
    return (data->direction *
        ((data->axis == VERTICAL_WALL) ? vector->y : vector->x));
}
int queue_monsters_in_order(map_tile_t *map_tile,
    monster_comparison_data_t *comparison_data, linked_list_t *monsters_seen)
{
    thing_t *current_monster = UNINIT;

    while (current_monster != NULL) {
        current_monster = read_item_ext(item_is_greater,
            comparison_data, monsters_seen);
        queue_item(insert_enemies, monsters_seen, current_monster);
        comparison_data->last = current_monster;
    }
}
*/

float scalar(sfVector3f *v1, sfVector3f *v2)
{
    return (float)(v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

sfVector3f cross_product(sfVector3f *vec1, sfVector3f *vec2)
{
    return (sfVector3f){
        vec1->y * vec2->z - vec1->z * vec2->y,
        vec1->z * vec2->x - vec1->x * vec2->z,
        vec1->x * vec2->y - vec1->y * vec2->x
    };
}

sfVector3f get_vector_from_points(sfVector3f *start, sfVector3f *end)
{
    return (sfVector3f){
        end->x - start->x,
        end->y - start->y,
        end->z - start->z
    };
}

static void get_seen_ennemies(linked_list_t *monsters, camera_t *camera,
    linked_list_t *dest_buffer)
{
    sfVector3f player_pos = {camera->pos.x, camera->pos.y, 0};
    sfVector3f player_monster_vec = {0};
    sfVector3f player_dir = {camera->dir.x, camera->dir.y, 0};
    float player_monster_scal = 0;
    thing_t *current_monster = NULL;

    for (linked_node_t **node = &(monsters->top);
        *node != NULL; node = &((*node)->next)) {
        current_monster = (thing_t *)((*node)->val);
        player_monster_vec = get_vector_from_points(&player_pos,
            &(current_monster->coords));
        player_monster_scal = scalar(&player_monster_vec, &player_dir);
        if (player_monster_scal > 0) {
            current_monster->onscreen = true;
            queue_item(current_monster, destroy_monster, dest_buffer);
        } else
            current_monster->onscreen = false;
        current_monster->player_dist = NORM(player_monster_vec);
    }
}

int monster1_is_farthest(const void *monster1, const void *monster2)
{
    const thing_t *monster1_struct = monster1;
    const thing_t *monster2_struct = monster2;

    return monster1_struct->player_dist > monster2_struct->player_dist;
}

/*
    size_t band_x = 0;
    sfTexture *texture = (void *)sfSprite_getTexture(thing->sprite);
    ray_hit_data_t ray_data = {0};
    sfVector2u tex_size = sfTexture_getSize(texture);
    (ray_hit_data_t){SIMPLE_WALL, thing->player_dist, tex_size.x / band_x, 0};
    draw_raycast_band(ray_data, thing->sprite, , win)
*/
static void draw_thing(thing_t *thing, double *raymap, sfRenderWindow *win)
{
    UNUSED(thing);
    UNUSED(raymap);
    UNUSED(win);
    return;
}

void show_things(double *raymap, camera_t *camera,
    linked_list_t *things, sfRenderWindow *win)
{
    linked_list_t dest_buffer[] = {0};
    thing_t **thing_array = NULL;

    get_seen_ennemies(things, camera, dest_buffer);
    thing_array = list_to_val_arr(dest_buffer);
    qsort(thing_array, sizeof(thing_t *),
        dest_buffer->len, monster1_is_farthest);
    for (size_t i = 0; thing_array[i] != NULL; i++) {
        draw_thing(thing_array[i], raymap, win);
    }
}
