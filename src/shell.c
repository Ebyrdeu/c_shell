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
	ulong buffer_size = SHELL_BUFFER_SIZE;
	char *buffer = NULL;

	print_shell_prompt();

	//https://man7.org/linux/man-pages/man3/getline.3.html
	if (getline(&buffer, &buffer_size, stdin) == -1) {
		if (!feof(stdin)) {
			perror("Error reading from stdin");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}
	return buffer;
}

void print_shell_prompt(void) {
	Prompt prompt;
	char *home_dir = NULL;

	// get full path of dir
	if (getcwd(prompt.cwd, PATH_MAX) == NULL) {
		printf("getcwd failed\n");
		exit(EXIT_FAILURE);
	}

	if (gethostname(prompt.hst, HOST_NAME_MAX) != 0) {
		printf("get hostname failed\n");
		exit(EXIT_FAILURE);
	}

	if (getlogin_r(prompt.usr, LOGIN_NAME_MAX) != 0) {
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
