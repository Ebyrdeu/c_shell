//
// Created by ebyrdeu on 2024-09-11.
//
#include "../include/shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void run_shell(void) {
	print_cmd();
}


void print_cmd(void) {
	char cwd[256];
	char usr[256];
	char hst[256];

	char *home_dir = NULL;

	if (getcwd(cwd, sizeof(cwd)) == NULL) {
		printf("getcwd failed\n");
		exit(EXIT_FAILURE);
	}

	if (gethostname(hst, sizeof(hst)) != 0) {
		printf("get hostname failed\n");
		exit(EXIT_FAILURE);
	}

	if (getlogin_r(usr, sizeof(usr)) != 0) {
		printf("get username failed\n");
		exit(EXIT_FAILURE);
	}

	// remove all dir name before last /
	// + 1 is for shifting / aka removing
	home_dir = strrchr(cwd, '/') + 1;

	if (strcmp(home_dir, usr) == 0) {
		home_dir = "~";
	}

	// should look like arch based terminal
	// [username@hostname home_dir_name]$
	printf("[%s@%s %s]$ ", usr, hst, home_dir);
	fflush(stdout);
}
