/*
** EPITECH PROJECT, 2025
** string checks
** File description:
** functions to check for simple conditions in strings
*/

#include "my.h"

size_t count_instances(const char *to_search, const char *tokens)
{
    int inst_counter = 0;

    for (int i = 0; to_search[i] != '\0'; i++) {
        if (my_contains(tokens, to_search[i]))
            inst_counter++;
    }
    return inst_counter;
}

bool my_contains(const char *string, const char to_search_for)
{
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (string[i] == to_search_for)
            return true;
    }
    return false;
}

bool my_isonly(const char *string, const char *char_pool)
{
    for (size_t i = 0; string[i] != '\0'; i++) {
        if (my_contains(char_pool, string[i]) == false)
            return false;
    }
    return true;
}

size_t count_words(const char *string, const char *sep)
{
    size_t word_count = 0;
    char prev = sep[0];

    if (prev == '\0')
        return word_count;
    for (size_t i = 0; string[i] != '\0'; i++) {
        word_count += (my_contains(sep, prev) && !my_contains(sep, string[i]));
        prev = string[i];
    }
    return word_count;
}
