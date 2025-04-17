/*
** EPITECH PROJECT, 2024
** my_qsort_r
** File description:
** sorts a void *array
*/

#include "my.h"
#include "my_qsort_r.h"
#include <stdbool.h>
#include <stdarg.h>

static void qsort_step(void_array_t to_sort,
    sort_swap_pair_t *sort_indexes, void *pivot, sort_func_t compar)
{
    void *swap_value = NULL;
    void *i_value = NULL;

    i_value = VOID_ARR_PTR_TO(to_sort, sort_indexes->i);
    if (IS_GREATER(compar.funct, i_value, pivot, compar.arg) == false) {
        sort_indexes->swap_index = sort_indexes->swap_index + 1;
        swap_value = VOID_ARR_PTR_TO(to_sort, sort_indexes->swap_index);
        if (sort_indexes->i > sort_indexes->swap_index)
            my_swap(i_value, swap_value, to_sort.size);
    }
}

static int my_qsort_r(void_array_t to_sort, sort_func_t compar)
{
    size_t set_span = VOID_ARR_SPAN(to_sort);
    void *pivot = NULL;
    sort_swap_pair_t srt_idxs = {to_sort.strt - 1, 0};
    void_array_t sort_sections[2] = {};

    if (set_span <= 0)
        return FAILURE;
    if (set_span == 1)
        return SUCCESS;
    pivot = VOID_ARR_PTR_TO(to_sort, to_sort.end);
    for (srt_idxs.i = to_sort.strt; srt_idxs.i <= to_sort.end; srt_idxs.i += 1)
        qsort_step(to_sort, &srt_idxs, pivot, compar);
    sort_sections[0] = (void_array_t){to_sort.base, to_sort.strt,
        srt_idxs.swap_index - 1, to_sort.size};
    sort_sections[1] = (void_array_t){to_sort.base, srt_idxs.swap_index + 1,
        to_sort.end, to_sort.size};
    if (my_qsort_r(sort_sections[0], compar) == FAILURE
        || my_qsort_r(sort_sections[1], compar) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int qsrtr(qsrt_args_t args)
{
    void_array_t to_sort = {};
    sort_func_t compar = {};

    to_sort.size = args.size;
    to_sort.strt = 0;
    to_sort.end = args.nmemb - 1;
    to_sort.base = args.base;
    compar.funct = args.compar;
    compar.arg = args.arg;
    if (to_sort.size <= 0 || to_sort.base == NULL)
        return FAILURE;
    return my_qsort_r(to_sort, compar);
}
