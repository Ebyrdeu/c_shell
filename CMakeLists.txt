cmake_minimum_required(VERSION 3.29)
project(c_shell C)

# Set the C standard to C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add the executable and source files
add_executable(c_shell
	src/main.c
	src/shell.c
)

# Include dirs for headers
target_include_directories(c_shell PRIVATE include/)

# Only apply these flags if using GCC
if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
	target_compile_options(c_shell PRIVATE
		-Wall                        # Enable common warnings
		-Wextra                      # Enable extra warnings
		-Wpedantic                   # Enforce strict compliance with C standard
		-Werror                      # Treat all warnings as errors
		-Wshadow                     # Warn when variables shadow others
		-Wconversion                 # Warn about implicit type conversions
		-Wfloat-equal                # Warn when comparing floating-point values
		-Wformat=2                   # Check printf/scanf format specifiers
		-Wstrict-prototypes          # Warn about missing function prototypes
		-Wmissing-prototypes         # Warn if functions lack a prototype
		-Wundef                      # Warn on undefined macros in #if/#elif
		-Wpointer-arith              # Warn on pointer arithmetic issues
		-Wcast-align                 # Warn if cast pointers have bad alignment
		-Wcast-qual                  # Warn when discarding const/volatile qualifiers
		-Wswitch-enum                # Warn if switch statements miss an enum case
		-fanalyzer                   # Enable static analysis
		-flto                        # Enable Link Time Optimization (LTO)
	)
endif ()
