cmake_minimum_required(VERSION 3.21)
project(MiniRT C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(libs)
add_subdirectory(libs/minilibx_macos)

include_directories(libs libs/minilibx_macos)

add_executable(MiniRT my_minirt.c my_minirt.h
        my_manager_render.c my_manager_camera.c my_manager_light.c my_manager_lib.c my_manager_render2.c
        my_manager_render_cyl.c my_manager_render_pl.c my_manager_render_sp.c my_manager_render_cyl2.c my_manager_render_cyl3.c my_manager_render_pl2.c my_manager_render_sp2.c
        my_setdata.c my_colors.c my_hooks.c my_vector.c my_shadow.c my_vector2.c my_vector3.c my_vector.h my_transform.c my_hooks2.c my_manager_lib2.c my_transform2.c my_shadow2.c
        my_parser.c my_parser.h my_parser2.c my_parser3.c my_parser4.c)

add_executable(MiniRT_Parser my_parser.c my_parser.h my_parser2.c my_parser3.c my_parser4.c my_parser_test.c)

target_link_libraries(MiniRT "-framework OpenGL" "-framework AppKit" FT_Lib MinilibX)
target_link_libraries(MiniRT_Parser FT_Lib)
