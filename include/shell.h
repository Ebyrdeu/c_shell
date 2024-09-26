//
// Created by ebyrdeu on 2024-09-11.
//

#ifndef SHELL_H
#define SHELL_H
#include <linux/limits.h>

// Define the size of the buffer used to read input commands in the shell
// 128 bytes by default
// mostly overkill - 64 bytes is enough for simple shell
// but with 128 I fell safe
#define SHELL_BUFFER_SIZE 1024

// 16 bytes by default
// more than enough for token size
#define TOKEN_BUFFER_SIZE 128

// these are not implemented for linux (at least not on my machine)
// I kinda could use POSIX ones, but they intentionally are 255 bites in mind
// which, eh... well... I can just do myself with 256
// https://man7.org/linux/man-pages/man0/limits.h.0p.html
#define HOST_NAME_MAX 64
#define LOGIN_NAME_MAX 256

typedef struct Prompt {
	char usr[LOGIN_NAME_MAX]; // Login name of the user running the shell
	char hst[HOST_NAME_MAX]; // Hostname of the system
	char cwd[PATH_MAX]; // Current working directory
} Prompt;

void shell(void);

char *read_line(void);

// function to tokenize from *read_line
char **parse_line(char *line);

// example: username@hostname: dir_name/dir_name_2$
void print_prompt(void);

#endif //SHELL_H
