/*
** EPITECH PROJECT, 2025
** fifo.h
** File description:
** header to manipulate fifo stacks
*/

#ifndef FIFO_H_
    #define FIFO_H_
    #include <stddef.h>
    #include <stdbool.h>
    #include <stdarg.h>
    #define NA(...) __VA_ARGS__

    #define QUEUE 0
    #define STACK 1

typedef char byte_t;

typedef void (*free_func_t)(void *);

typedef struct linked_node_s {
    struct linked_node_s *next;
    void *val;
    free_func_t free_function;
} linked_node_t;

typedef struct linked_list_s {
    size_t len;
    linked_node_t *top;
    linked_node_t *tail;
    bool is_burnt;
} linked_list_t;

    #define NEW_LIST ((linked_list_t [])NA({{)0, NULL, NULL, false NA(}}))
    #define LINKED_LIST_TYP(type) linked_list_t

void *pop_list(linked_list_t *list);
void *read_list(linked_list_t *list);
void destroy_node_val(free_func_t free_function, void *val);
void destroy_node(linked_node_t *to_free);
void clear_list(linked_list_t *list);
void burn_list(linked_list_t *list);

void *list_to_val_arr(linked_list_t *list);
int stack_item(void *new_val, free_func_t free_func,
    linked_list_t *stack);
int queue_item(void *new_val, free_func_t free_func,
    linked_list_t *queue);

/* linked list search */
void del_item(bool (*attribute)(void *), linked_list_t *list);
int del_item_ext(bool (*attribute)(void *val, void *data),
    void *data, linked_list_t *list);
void *del_item_from_rank(size_t rank, linked_list_t *list);
void *insert_item(size_t rank, linked_list_t *list,
    void *value, free_func_t free_function);
void *pop_item(bool (*attribute)(void *), linked_list_t *list);
void *pop_item_ext(bool (*attribute)(void *val, void *data),
    void *data, linked_list_t *list);
void *pop_item_from_rank(size_t rank, linked_list_t *list);
void *read_item(bool (*attribute)(void *), linked_list_t *list);
void *read_item_ext(bool (*attribute)(void *val, void *data),
    void *data, linked_list_t *list);
void *read_item_from_rank(size_t rank, linked_list_t *list);
/* ~~~~~~~~~~~~~~~~~~ */

    #define DEF_NUL(arg_ptr...) ((void *)(arg_ptr - (long int)0))

    #define LSTACK(new_v, lst, dst...) stack_item(new_v, DEF_NUL(dst), lst)
    #define LQUEUE(new_v, lst, dst...) queue_item(new_v, DEF_NUL(dst), lst)

#endif /* FIFO_H_ */
