//
// Created by ebyrdeu on 2024-09-11.
//
#include "../include/shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void run_shell(void) {
	char *res = read_line();


	printf("echo from the shell: %s\n", res);
	free(res);
}

char *read_line(void) {
	uint buffer_size = SHELL_BUFFER_SIZE;
	char *buffer = malloc(sizeof(char) * buffer_size);
	int position = 0;
	int current_char;

	if (!buffer) {
		fprintf(stderr, "malloc failed on allocating buffer in read_line\n");
		fprintf(stderr, "with buffer size: %d\n", buffer_size);
		exit(EXIT_FAILURE);
	}

	print_shell_prompt();

	while (current_char = getchar(), current_char != EOF && current_char != '\n') {
		buffer[position++] = current_char;

		if (position >= buffer_size) {
			buffer_size *= 2;
			char *new_buffer = realloc(buffer, buffer_size);
			if (new_buffer == NULL) {
				fprintf(stderr, "realloc failed on reallocating buffer in read_line\n");
				fprintf(stderr, "with buffer size: %d\n", buffer_size);
				free(buffer);
				exit(EXIT_FAILURE);
			}
			buffer = new_buffer;
		}
	}
	buffer[position] = '\0';
	return buffer;
}

void print_shell_prompt(void) {
	Prompt prompt;
	char *home_dir = NULL;

	// get full path of dir
	if (getcwd(prompt.cwd, sizeof(prompt.cwd)) == NULL) {
		printf("getcwd failed\n");
		exit(EXIT_FAILURE);
	}

	if (gethostname(prompt.hst, sizeof(prompt.hst)) != 0) {
		printf("get hostname failed\n");
		exit(EXIT_FAILURE);
	}

	if (getlogin_r(prompt.usr, sizeof(prompt.usr)) != 0) {
		printf("get username failed\n");
		exit(EXIT_FAILURE);
	}

	// remove all dir name before last /
	// + 1 is for shifting / aka removing
	home_dir = strrchr(prompt.cwd, '/') + 1;


	if (strcmp(home_dir, prompt.usr) == 0) {
		home_dir = "~";
	}

	// should look like arch based terminal
	// [username@hostname home_dir_name]$
	printf("[%s@%s %s]$ ", prompt.usr, prompt.hst, home_dir);
	fflush(stdout);
}
