/*
** EPITECH PROJECT, 2025
** linked_lists.c
** File description:
** fifo and lifo lists manager
*/

#include "../my.h"
#include "../linked_lists.h"

void *read_item(bool (*attribute)(void *), linked_list_t *list)
{
    if (list->is_burnt)
        return NULL;
    for (linked_node_t *node = list->top; node != NULL; node = node->next) {
        if (attribute(node->val))
            return node->val;
    }
    return NULL;
}

void *read_item_ext(bool (*attribute)(void *val, void *data),
    void *data, linked_list_t *list)
{
    if (list->is_burnt)
        return NULL;
    for (linked_node_t *node = list->top; node != NULL; node = node->next) {
        if (attribute(node->val, data))
            return node->val;
    }
    return NULL;
}

void *read_item_from_rank(size_t rank, linked_list_t *list)
{
    size_t i = 0;

    if (list->is_burnt || list->len == 0)
        return NULL;
    rank = rank % list->len;
    for (linked_node_t *node = list->top; node != NULL; node = node->next) {
        if (i == rank)
            return node->val;
        i++;
    }
    return NULL;
}
