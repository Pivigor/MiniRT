cmake_minimum_required(VERSION 3.21)
project(MiniRT C)

set(CMAKE_C_STANDARD 99)

add_library(FT_Lib my_global_libs.h ft_atoi.c ft_split.c
        ft_strlen.c ft_strncmp.c get_next_line.c get_next_line.h get_next_line_utils.c
        ft_lstadd_back.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstsize.c)
