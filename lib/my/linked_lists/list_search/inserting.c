/*
** EPITECH PROJECT, 2025
** linked_lists.c
** File description:
** fifo and lifo lists manager
*/

#include "../my.h"
#include "../linked_lists.h"

void *insert_item(size_t rank, linked_list_t *list,
    void *value, free_func_t free_function)
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
