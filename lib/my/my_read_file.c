/*
** EPITECH PROJECT, 2024
** test
** File description:
** test
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *my_read_file(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    char *str;
    char temp = '0';
    int len;

    for (len = 0; read(fd, &temp, 1); len++);
    close(fd);
    fd = open(file_name, O_RDONLY);
    str = malloc(sizeof(char) * (len + 1));
    read(fd, str, len);
    str[len] = '\0';
    return str;
}
