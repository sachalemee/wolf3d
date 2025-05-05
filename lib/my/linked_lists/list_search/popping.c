/*
** EPITECH PROJECT, 2025
** linked_lists.c
** File description:
** fifo and lifo lists manager
*/

#include "../my.h"
#include "../linked_lists.h"

void *pop_item(bool (*attribute)(void *), linked_list_t *list)
{
    void *output_save = NULL;
    void *node_freeing_pointer = NULL;

    if (list->is_burnt)
        return NULL;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (attribute((*node)->val)) {
            output_save = (*node)->val;
            node_freeing_pointer = *node;
            *node = (*node)->next;
            free(node_freeing_pointer);
            return output_save;
        }
    }
    return NULL;
}

void *pop_item_ext(bool (*attribute)(void *val, void *data),
    void *data, linked_list_t *list)
{
    void *output_save = NULL;
    void *node_freeing_pointer = NULL;

    if (list->is_burnt)
        return NULL;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (attribute((*node)->val, data)) {
            output_save = (*node)->val;
            node_freeing_pointer = *node;
            *node = (*node)->next;
            free(node_freeing_pointer);
            return output_save;
        }
    }
    return NULL;
}

void *pop_item_from_rank(size_t rank, linked_list_t *list)
{
    void *output_save = NULL;
    void *node_freeing_pointer = NULL;
    size_t i = 0;

    if (list->is_burnt || list->len == 0)
        return NULL;
    rank = rank % list->len;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (i == rank) {
            output_save = (*node)->val;
            node_freeing_pointer = *node;
            *node = (*node)->next;
            free(node_freeing_pointer);
            return output_save;
        }
        i++;
    }
    return NULL;
}
