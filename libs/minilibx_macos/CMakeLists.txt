cmake_minimum_required(VERSION 3.21)
project(MiniRT C)

string(APPEND CMAKE_C_FLAGS "-O2")

add_library(MinilibX mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m
        mlx_xpm.c mlx_int_str_to_wordtab.c)
