/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** converts a string into a word array
*/

#include <stddef.h>
#include <stdlib.h>
#include "./my.h"

int count_fragments(const char *sentence, const char *sep)
{
    int nb_frag = 0;

    if (!sentence || !sep)
        return FAILURE;
    for (int i = 1; sentence[i - 1] != '\0'; i++) {
        for (; my_contains(sep, sentence[i]) && sentence[i] != '\0'; i++);
        for (; !my_contains(sep, sentence[i]) && sentence[i] != '\0'; i++);
        nb_frag = nb_frag + !my_contains(sep, sentence[i - 1]);
    }
    return nb_frag;
}

static char *get_word(const char *word, char const *sep, int *i)
{
    int len_word = 0;
    char *str;

    for (; !my_contains(sep, word[len_word])
        && word[len_word] != '\0'; len_word++);
    str = malloc(sizeof(char) * (len_word + 1));
    if (!str)
        return NULL;
    for (int i = 0; i < len_word; i++)
        str[i] = word[i];
    str[len_word] = '\0';
    *i = *i + len_word;
    return (str);
}

static void destroy_word(char *word)
{
    if (word)
        free(word);
}

void destroy_word_array(char **to_destroy)
{
    if (to_destroy != NULL) {
        for (int i = 0; to_destroy[i] != NULL; i++)
            destroy_word(to_destroy[i]);
        free(to_destroy);
    }
}

int nullify_word_array(char **word_array, int len)
{
    if (word_array == NULL)
        return EXIT_FAILURE;
    for (int i = 0; i <= len; i++)
        word_array[i] = NULL;
    return EXIT_SUCCESS;
}

// the second if in the for loop should be in the first if but couldnt be there
// because of the triple tabulation rule (checks if the get_word failed)
char **my_str_to_word_array(char const *str, char const *sep)
{
    char **out;
    int index_out = 0;
    int word_count = count_fragments(str, sep);

    if (!str || !sep)
        return NULL;
    out = malloc((word_count + 1) * sizeof(char *));
    if (nullify_word_array(out, word_count))
        return NULL;
    for (int i = 0; str[i] != '\0'; i += (str[i] != '\0')) {
        for (; my_contains(sep, str[i]) && str[i] != '\0'; i++);
        if (i != 0 && str[i - 1] == '\0') {
            destroy_word_array(out);
            return NULL;
        }
        out[index_out] = get_word(&(str[i]), sep, &i);
        index_out++;
    }
    return out;
}
