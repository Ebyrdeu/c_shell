//
// Created by ebyrdeu on 2024-09-11.
//

#ifndef SHELL_H
#define SHELL_H
#include <linux/limits.h>

// Define the size of the buffer used to read input commands in the shell
// 128 bytes by default
// mostly overkill 64 bytes is enough for simple shell
#define SHELL_BUFFER_SIZE 1024

// these are not implemented for linux (at least not on my machine)
// I kinda could use POSIX ones, but they intention doesn't have \0 in mind
// which, eh... well... I can just initiate myself
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

void print_prompt(void);

#endif //SHELL_H
