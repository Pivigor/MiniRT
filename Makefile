SRCS		=	my_colors.c					\
				my_hooks.c					\
				my_hooks2.c					\
				my_manager_camera.c			\
				my_manager_lib.c			\
				my_manager_lib2.c			\
				my_manager_light.c			\
				my_manager_render.c			\
				my_manager_render2.c		\
				my_manager_render_cyl.c		\
				my_manager_render_cyl2.c	\
				my_manager_render_cyl3.c	\
				my_manager_render_pl.c		\
				my_manager_render_pl2.c		\
				my_manager_render_sp.c		\
				my_manager_render_sp2.c		\
				my_minirt.c					\
				my_parser.c					\
				my_parser2.c				\
				my_parser3.c				\
				my_parser4.c				\
				my_setdata.c				\
				my_shadow.c					\
				my_shadow2.c				\
				my_transform.c				\
				my_transform2.c				\
				my_vector.c					\
				my_vector2.c				\
				my_vector3.c				\
				libs/ft_atoi.c				\
				libs/ft_lstadd_back.c		\
				libs/ft_lstclear.c			\
				libs/ft_lstlast.c			\
				libs/ft_lstnew.c			\
				libs/ft_lstsize.c			\
				libs/ft_split.c				\
				libs/ft_strlen.c			\
				libs/ft_strncmp.c			\
				libs/get_next_line.c		\
				libs/get_next_line_utils.c
OBJS		= ${SRCS:.c=.o}
DEPS		= ${SRCS:.c=.d}
NAME		= MiniRT
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEPFLAGS	= -MMD -MF ${<:.c=.d}
RM			= rm -f

all:		${NAME}

$(NAME):	${OBJS}
			${CC} -o ${NAME} ${OBJS}  -lmlx -framework OpenGL -framework AppKit

-include ${DEPS}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@ ${DEPFLAGS} -I libs

clean:
			${RM} ${OBJS} ${DEPS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
