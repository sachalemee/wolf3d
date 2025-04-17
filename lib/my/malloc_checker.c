/*
** EPITECH PROJECT, 2025
** malloc_checker.c
** File description:
** checks the imput mallocs and frees the if one of them is null
** (putting the imput error message in stderr)
*/

#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./my.h"

static int contains_null_mallocs(int count_args, va_list to_check)
{
    void *malloc_pointer = NULL;

    malloc_pointer = va_arg(to_check, void *);
    for (int i = 0; i < count_args; i++) {
        if (!malloc_pointer)
            return true;
        malloc_pointer = va_arg(to_check, void *);
    }
    return false;
}

int check_mallocs(int count_args, const char *msg, ...)
{
    va_list to_check;
    va_list to_delete;
    void *malloc_pointer = NULL;

    va_start(to_check, msg);
    va_copy(to_delete, to_check);
    if (!contains_null_mallocs(count_args, to_check))
        return true;
    my_dputstr(2, msg);
    for (int i = 0; i < count_args; i++) {
        if (malloc_pointer)
            free(malloc_pointer);
        malloc_pointer = va_arg(to_check, void *);
    }
    return false;
}
