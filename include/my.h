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
    #include <stdarg.h>
    #include "my_qsort_r.h"
    #define UNUSED(var) (void)(var)
    #define ABS(value) ((value) < 0 ? (value) * (-1) : (value))
    #define EXIT_84 84
    #define SQUARE(x) ((x) * (x))
    #define MY_INF ((double)1.0 / (double)0.0)
    #define SUCCESS 0
    #define FAILURE -1
    #define UNINIT ((void *)1)
    #define IN(string, ltr) my_contains(string, ltr)
    #define IN_2(buf1, buf2, item) (IN(buf1, item) || IN(buf2, item))
    #define W_STRT(cu, prv, sp) !IN_2(sp, "\n\"", cu) && IN_2(sp, "\n\"", prv)
    #define CONCAT(words...) my_strconcat(words, NULL) // null termination
    #ifndef _Nullable
        #define _Nullable
    #endif /* _Nullable */

typedef struct set_s {
    size_t start;
    size_t end;
} set_t;

int check_mallocs(int count_args, const char *msg, ...);
void my_destroy_array(void *start, size_t depth);
int my_dputstr(int fd, const char *tput);
void free_fstrsplit(char **to_free);
char **my_fstrsplit(char *to_split, const char *sep);
int qsrtr(qsrt_args_t args);
char **va_list_to_word_array(va_list to_concat);
char *my_strconcat(char *first_word, ...);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
size_t count_instances(const char *to_search, const char *tokens);
bool my_contains(const char *string, const char to_search_for);
bool my_isonly(const char *string, const char *char_pool);
size_t count_words(const char *string, const char *sep);
void my_swap(void *a, void *b, size_t size);
void swap_char(char *a, char *b);
int count_fragments(const char *sentence, const char *sep);
void destroy_word_array(char **to_destroy);
char **my_str_to_word_array(char const *str, char const *sep);
void rand128(__int128_t *dest);
void my_uuid_generator(__int128_t *dest);
int read_file_ctts(char const *const path, char **buffer);
#endif /* MY_H_ */
