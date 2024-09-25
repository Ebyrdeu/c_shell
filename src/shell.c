//
// Created by ebyrdeu on 2024-09-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/shell.h"
#include "../include/error_handling.h"

void shell(void) {
	char *res = read_line();

	free(res);
}

char *read_line(void) {
	ulong buffer_size = SHELL_BUFFER_SIZE;
	char *buffer = NULL;

	print_prompt();

	// https://man7.org/linux/man-pages/man3/getline.3.html
	if (getline(&buffer, &buffer_size, stdin) == -1) {
		if (!feof(stdin)) {
			EXIT_ON_ERR("Error reading from stdin");
		}

		exit(EXIT_SUCCESS);
	}
	return buffer;
}


void print_prompt(void) {
	Prompt prompt;
	char *home_dir = NULL;

	// get full path of dir
	if (getcwd(prompt.cwd, PATH_MAX) == NULL) {
		EXIT_ON_ERR("getcwd failed");
	}

	if (gethostname(prompt.hst, HOST_NAME_MAX) != 0) {
		EXIT_ON_ERR("get hostname failed");
	}

	if (getlogin_r(prompt.usr, LOGIN_NAME_MAX) != 0) {
		EXIT_ON_ERR("get username failed");
	}

	// remove all dir name before last /
	// then shift by 1
	home_dir = strrchr(prompt.cwd, '/') + 1;


	if (strcmp(home_dir, prompt.usr) == 0) {
		home_dir = "~";
	}

	// should look like arch based terminal
	// [username@hostname home_dir_name]$
	printf("[%s@%s %s]$ ", prompt.usr, prompt.hst, home_dir);
	fflush(stdout);
}
