//
// Created by ebyrdeu on 2024-09-25.
//

#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define ERR(error_message) { \
int errnum = errno; \
fprintf(stderr, "Error: %s\n", error_message); \
fprintf(stderr, "Details: %s\n", strerror(errnum)); \
fprintf(stderr, "In File: %s\n", __FILE__); \
fprintf(stderr, "Function: %s()\n", __func__); \
fprintf(stderr, "At Line: %d\n", __LINE__); \
}

#define EXIT_ON_ERR(error_message) { \
ERR(error_message); \
exit(EXIT_FAILURE); \
}

#endif //ERROR_HANDLING_H
