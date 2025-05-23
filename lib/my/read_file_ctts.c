/*
** EPITECH PROJECT, 2025
** parser
** File description:
** parser.c
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file_ctts(char const *const path, char **buffer)
{
    struct stat file_data = {0};
    FILE *file_ptr = NULL;

    if (stat(path, &file_data) == FAILURE)
        return FAILURE;
    file_ptr = fopen(path, "r");
    *buffer = malloc((file_data.st_size + 1) * sizeof(char));
    if (*buffer == NULL || file_ptr == NULL
        || fread(*buffer, sizeof(char), file_data.st_size, file_ptr) == 0
        || fclose(file_ptr) == EOF) {
        free(*buffer);
        if (file_ptr != NULL)
            fclose(file_ptr);
        *buffer = NULL;
        return FAILURE;
    }
    (*buffer)[file_data.st_size] = '\0';
    return SUCCESS;
}
