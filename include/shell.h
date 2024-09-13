//
// Created by ebyrdeu on 2024-09-11.
//

#ifndef SHELL_H
#define SHELL_H

// Define the size of the buffer used to read input commands in the shell
// 128 bytes by default
#define SHELL_BUFFER_SIZE 1024

/**
 * Struct representing the shell prompt details.
 *
 * Members:
 * - usr: A character array holding the username of the current user (maximum 256 characters).
 * - hst: A character array holding the hostname of the system (maximum 256 characters).
 * - cwd: A character array holding the current working directory (maximum 256 characters).
 */
typedef struct {
 char usr[256]; // Username of the user running the shell
 char hst[256]; // Hostname of the system
 char cwd[256]; // Current working directory
} Prompt;

/**
 * Function to initialize and start the shell.
 * This function enters an infinite loop to continuously read user input and execute commands.
 */
void run_shell(void);

/**
 * Function to read a line of input from the user.
 *
 * @return A pointer to the string containing the user's input. The string should be freed by the caller.
 */
char *read_line(void);

/**
 * Function to print the shell prompt to the console.
 * It typically displays the username, hostname, and current working directory before each command input.
 */
void print_shell_prompt(void);

#endif //SHELL_H
