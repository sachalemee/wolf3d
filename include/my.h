/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** header file for lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <stddef.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <string.h>
    #include "my_qsort_r.h"
    #define UNUSED(var) (void)(var)
    #define ABS(value) ((value) < 0 ? (value) * (-1) : (value))
    #define EXIT_84 84
    #define MY_INF ((double)1.0 / (double)0.0)
    #define SUCCESS 0
    #define FAILURE -1
    #define UNINIT ((void *)1)
    #define IN(string, char) my_contains(string, char)
    #define IN_2(buf1, buf2, item) (IN(buf1, item) || IN(buf2, item))
    #define W_STRT(cu, prv, sp) !IN_2(sp, "\n\"", cu) && IN_2(sp, "\n\"", prv)
    #ifndef _Nullable
        #define _Nullable
    #endif /* _Nullable */

typedef struct set_s {
    size_t start;
    size_t end;
} set_t;

void swap_char(char *a, char *b);
int check_mallocs(int count_args, const char *msg, ...);
char **my_fstrsplit(char *to_split, const char *sep);
void my_destroy_strsplit(char **to_destroy);
char **my_strsplit(const char *to_split_original, const char *sep);
int my_contains(char const *buffer, char target);
void destroy_word_array(char **to_destroy);
int count_fragments(const char *sentence, const char *sep);
char **my_str_to_word_array(char const *str, char const *sep);
char *my_strcpy(char *dest, char const *src);
int my_dputstr(int fd, const char *tput);
int my_putstr(char *to_print);
int my_strlen(char const *str);
int count_instances(const char *to_search, const char *tokens);
void my_destroy_array(void *start, size_t depth);
int exec_regex(const char *tcheck, const char *regex);
char **my_word_array_dup(char **original);
void destroy_word_table(char ***to_destroy);
char ***my_word_table_dup(char ***original);
char ***my_word_table_n_dup(char ***original, size_t n);
char *my_msprintf(const char *format, ...);
char *my_strnconcat(int count_str, ...);
int appnd_to(char *value, char **printbuffer);
size_t my_arrlen(void *ptr_array);
void my_swap(void *a, void *b, size_t size);
char **va_list_to_word_array(va_list to_concat);
char *my_strconcat(char *first_word, ...);
    #define CONCAT(words...) my_strconcat(words, NULL) // null termination
char *my_strcat(char *dest, char const *src);

#endif /* MY_H_ */
