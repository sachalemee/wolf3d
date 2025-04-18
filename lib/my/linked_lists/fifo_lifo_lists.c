/*
** EPITECH PROJECT, 2025
** fifo_stack.c
** File description:
** fifo stack manager
*/

#include "../my.h"
#include "../linked_lists.h"

void burn_list(linked_list_t *list)
{
    clear_list(list);
    list->is_burnt = true;
}

void *list_to_val_arr(linked_list_t *list)
{
    char **val_array = NULL;
    size_t val_array_ind = 0;

    if (list->is_burnt)
        return NULL;
    val_array = malloc((list->len + 1) * sizeof(char *));
    if (val_array == NULL)
        return NULL;
    for (linked_node_t *node = list->top; node != NULL; node = node->next) {
        val_array[val_array_ind] = node->val;
        val_array_ind++;
    }
    val_array[val_array_ind] = NULL;
    return (void *)val_array;
}

static void stack_node(linked_node_t *new_node, linked_list_t *list)
{
    if (list->top == NULL) {
        list->tail = new_node;
    } else
        new_node->next = list->top;
    list->top = new_node;
}

static void queue_node(linked_node_t *new_node, linked_list_t *list)
{
    if (list->top == NULL) {
        list->top = new_node;
    } else
        list->tail->next = new_node;
    list->tail = new_node;
}

int add_item(void *new_val, free_func_t free_func,
    linked_list_t *stack, bool end)
{
    linked_node_t *new_node = calloc(1, sizeof(linked_node_t));

    if (check_mallocs(1, "", new_node) == false)
        burn_list(stack);
    if (stack->is_burnt) {
        destroy_node_val(free_func, new_val);
        return FAILURE;
    }
    new_node->val = new_val;
    new_node->free_function = free_func;
    (stack->len)++;
    if (end == QUEUE) {
        queue_node(new_node, stack);
    } else if (end == STACK)
        stack_node(new_node, stack);
    return SUCCESS;
}

int stack_item(void *new_val, free_func_t free_func,
    linked_list_t *stack)
{
    return add_item(new_val, free_func, stack, STACK);
}

int queue_item(void *new_val, free_func_t free_func,
    linked_list_t *queue)
{
    return add_item(new_val, free_func, queue, QUEUE);
}
