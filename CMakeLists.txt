cmake_minimum_required(VERSION 3.29)
project(c_shell C)

set(CMAKE_C_STANDARD 23)

add_executable(c_shell src/main.c
	src/shell.c
)
