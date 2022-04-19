/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** get_buffer
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

static int my_file_len(char const *name)
{
    int fd = open(name, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
    char buff[2];
    int offset = 0;
    int len = 1;

    while (len != 0) {
        len = read(fd, buff, 1);
        ++offset;
    }
    close(fd);
    return offset;
}

char *get_buffer(char const *file)
{
    int fd = open(file, O_RDONLY, S_IRUSR | S_IRGRP | S_IROTH);
    int len = my_file_len(file);
    char *buffer;
    buffer = malloc(sizeof(char) * (len));
    if (fd != -1)
        len = read(fd, buffer, len);
    close(fd);
    buffer[len] = '\0';

    return buffer;
}
