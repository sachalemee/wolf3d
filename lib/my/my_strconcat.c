/*
** EPITECH PROJECT, 2024
** my_strconcat.c
** File description:
** merges two strings into one
*/

#include "my.h"
#include "linked_lists.h"
#include <stdarg.h>

char **va_list_to_word_array(va_list to_concat)
{
    linked_list_t *word_buff = NEW_LIST;
    char *current_word = UNINIT;
    char **result = NULL;

    while (current_word != NULL) {
        current_word = va_arg(to_concat, char *);
        if (current_word != NULL)
            queue_item(current_word, NULL, word_buff);
    }
    result = list_to_val_arr(word_buff);
    burn_list(word_buff);
    return result;
}

static size_t my_strlen_array(char **str_list)
{
    size_t total_size = 0;

    for (size_t i = 0; str_list[i] != NULL; i++)
        total_size += my_strlen(str_list[i]);
    return total_size;
}

static void my_word_array_copy_str(char *dest, char **str_list)
{
    size_t total_size = 0;

    for (size_t i = 0; str_list[i] != NULL; i++) {
        my_strcpy(&(dest[total_size]), str_list[i]);
        total_size += my_strlen(str_list[i]);
    }
    dest[total_size] = '\0';
}

char *my_strconcat(char *first_word, ...)
{
    va_list to_concat;
    char **str_list = NULL;
    size_t arg_len = 0;
    size_t va_args_words_total_len = 0;
    char *dest = NULL;

    if (first_word == NULL)
        return strdup("");
    va_start(to_concat, first_word);
    str_list = va_list_to_word_array(to_concat);
    if (str_list == NULL)
        return NULL;
    arg_len = my_strlen(first_word);
    va_args_words_total_len = my_strlen_array(str_list);
    dest = malloc((arg_len + va_args_words_total_len + 1) * sizeof(char));
    dest[arg_len + va_args_words_total_len] = '\0';
    my_strcpy(dest, first_word);
    my_word_array_copy_str(&(dest[arg_len]), str_list);
    free(str_list);
    return dest;
}
