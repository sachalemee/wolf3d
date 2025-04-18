/*
** EPITECH PROJECT, 2025
** linked_lists.c
** File description:
** fifo and lifo lists manager
*/

#include "../my.h"
#include "../linked_lists.h"

void *pop_list(linked_list_t *list)
{
    void *popped_val = NULL;
    linked_node_t *to_free = NULL;

    if (list->is_burnt)
        return NULL;
    if (list->top == NULL)
        return NULL;
    popped_val = list->top->val;
    to_free = list->top;
    list->top = list->top->next;
    if (list->tail == to_free)
        list->tail = NULL;
    free(to_free);
    (list->len)--;
    return popped_val;
}

void *read_list(linked_list_t *list)
{
    if (list->is_burnt)
        return NULL;
    return (list->top == NULL) ? NULL : (void *)list->top->val;
}

void destroy_node_val(free_func_t free_function, void *val)
{
    if ((free_function != NULL) && (val != NULL))
        free_function(val);
}

void destroy_node(linked_node_t *to_free)
{
    destroy_node_val(to_free->free_function, to_free->val);
    free(to_free);
}

void clear_list(linked_list_t *list)
{
    linked_node_t *to_free = NULL;

    if (list->is_burnt)
        return;
    for (linked_node_t *node = list->top; node != NULL;) {
        to_free = node;
        node = node->next;
        destroy_node(to_free);
    }
    list->top = NULL;
    list->tail = NULL;
    list->len = 0;
}
