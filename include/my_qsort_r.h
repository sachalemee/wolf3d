/*
** EPITECH PROJECT, 2025
** my_qsort_r.h
** File description:
** header file for qsort
*/

#ifndef MY_QSORT_R_H_
    #define MY_QSORT_R_H_
    #define IGN(...) __VA_ARGS__
    #define SCAL(...) IGN({) __VA_ARGS__ IGN(})
    #define VOID_ARR_SPAN(arr) ((arr).end - (arr).strt + 1)
    #define VOID_ARR_PTR_TO(arr, i) (void *)&(((char *)arr.base)[i * arr.size])
    #define GET_GREATEST(cmp, v1, v2, arg) ((cmp(v1, v2, arg) > 0) ? v1 : v2)
    #define IS_GREATER(cmp, v1, v2, av) ((cmp(v1, v2, av) > 0) ? true : false)
    #include <stddef.h>

typedef struct qsrt_args_s {
    void *base;
    size_t nmemb;
    size_t size;
    int (*compar)(const void *, const void *, void *);
    void *arg;
} qsrt_args_t;

typedef struct void_array_s {
    void *base;
    size_t strt;
    size_t end;
    size_t size;
} void_array_t;

typedef struct sort_swap_pair_s {
    size_t swap_index;
    size_t i;
} sort_swap_pair_t;

typedef struct sort_func_s {
    int (*funct)(const void *, const void *, void *);
    void *arg;
} sort_func_t;

int qsrtr(qsrt_args_t args);
    #define $$my_qsort_r(b, l, s, c, a) qsrtr((qsrt_args_t)SCAL(b, l, s, c, a))
// TO BE USED AS IF HEADER IS AS FOLLOWS:
// void qsort_r(void base[.size * .nmemb],
//              size_t nmemb,
//              size_t size,
//              int (*compar)(const void [.size], const void [.size], void *),
//              void *arg);
// EXAMPLE :
// #include <stdio.h>
//
// static int my_compare_nth_char(const void *v1, const void *v2, void *n_ptr)
// {
//     size_t n = *(size_t *)n_ptr;
//
//     return (*(char **)v1)[n] - (*(char **)v2)[n];
// }
//
// /* function to sort the word array using the ascii value of the 2nd char*/
// int main(void)
// {
//     char *base[4] = {"hello", "hawooga", "czech republic", "hi"};
//     size_t index_sort = 1;
//
//     $$my_qsort_r(base, 4, sizeof(char *), my_compare_nth_char, &index_sort);
// }

#endif /* MY_QSORT_R_H_ */
