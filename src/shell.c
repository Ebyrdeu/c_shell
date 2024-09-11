//
// Created by ebyrdeu on 2024-09-11.
//
#include "../include/shell.h"

#include <stdio.h>

static void welcome_message(void) {
	printf("Welcome to the very simple shell!\n");
	fflush(stdout);
}

void run_shell(void) {
	welcome_message();

	char *output = NULL;

	output = read_line();

	printf("output: %s", output);
}

char *read_line(void) {
	constexpr int buffer = MAX_CMD_LEN;

	char input[buffer];

	printf("> ");
	fflush(stdout);

	return fgets(input, sizeof(char) * buffer, stdin);
}
