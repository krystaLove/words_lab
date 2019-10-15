cmake_minimum_required(VERSION 3.15)
project(words_lab C)

set(CMAKE_C_STANDARD 99)

add_executable(words_lab main.c Word.h BinaryTree.h BinaryTree.c Word.c vector.h vector.c Data.h Data.c)