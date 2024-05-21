/*
** EPITECH PROJECT, 2024
** read
** File description:
** file
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_macro.h"
#include "op.h"
#include <sys/stat.h>

static int get_file_len(const char *filename)
{
    char waste[1] = {' '};
    int fd = open(filename, O_RDONLY);
    int file_len = 0;
    int nbr_bytes_readed = 1;

    if (fd == -1)
        return -1;
    while (nbr_bytes_readed == 1){
        nbr_bytes_readed = read(fd, waste, 1);
        file_len++;
    }
    close(fd);
    return file_len - 1;
}

char **read_file(const char *file_name)
{
    int file_len = get_file_len(file_name);
    int fd = open(file_name, O_RDONLY);
    int read_return;
    char *file = NULL;

    if (fd == -1)
        return NULL;
    file = malloc(sizeof(char) * (file_len + 1));
    if (file == NULL)
        return NULL;
    read_return = read(fd, file, file_len);
    if (read_return == -1)
        return NULL;
    file[file_len] = '\0';
    close(fd);
    return my_split(file, '\n');
}

int nbr_word(char **tab)
{
    int i = 0;

    while (tab[i] != NULL){
        i++;
    }
    return i;
}

char *find_name(char *line, int j)
{
    char *name = malloc(sizeof(char) * my_strlen(line));
    int i = 0;

    while (line[j] != '"'){
        name[i] = line[j];
        j++;
        i++;
    }
    name[i] = '\0';
    return name;
}

char **name_headers(char **tab)
{
    int j = 0;

    for (int i = 0; i != 2; i++){
        if (have_headers(tab[i]) == 84)
            return NULL;
        for (j = 0; tab[i][j] != '"'; j++);
        tab[i] = find_name(tab[i], j + 1);
    }
    return tab;
}
