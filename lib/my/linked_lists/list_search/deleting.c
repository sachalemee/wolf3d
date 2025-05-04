/*
** EPITECH PROJECT, 2025
** linked_lists.c
** File description:
** fifo and lifo lists manager
*/

#include "../my.h"
#include "../linked_lists.h"

void del_item(bool (*attribute)(void *), linked_list_t *list)
{
    void *node_freeing_pointer = NULL;

    if (list->is_burnt)
        return NULL;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (attribute((*node)->val)) {
            node_freeing_pointer = *node;
            *node = (*node)->next;
            destroy_node(node_freeing_pointer);
            return SUCCESS;
        }
    }
    return FAILURE;
}

int del_item_ext(bool (*attribute)(void *val, void *data),
    void *data, linked_list_t *list)
{
    void *node_freeing_pointer = NULL;

    if (list->is_burnt)
        return NULL;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (attribute((*node)->val, data)) {
            node_freeing_pointer = *node;
            *node = (*node)->next;
            destroy_node(node_freeing_pointer);
            return SUCCESS;
        }
    }
    return FAILURE;
}

void *del_item_from_rank(size_t rank, linked_list_t *list)
{
    void *node_freeing_pointer = NULL;
    size_t i = 0;

    if (list->is_burnt || list->len == 0)
        return NULL;
    rank = rank % list->len;
    for (linked_node_t **node = &(list->top);
        *node != NULL; node = &((*node)->next)) {
        if (i == rank) {
            node_freeing_pointer = *node;
            *node = (*node)->next;
            destroy_node(node_freeing_pointer);
            return SUCCESS;
        }
        i++;
    }
    return FAILURE;
}
