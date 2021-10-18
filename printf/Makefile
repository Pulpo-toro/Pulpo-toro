NAME = libftprintf.a

SRC = first_part.c \
		second_part.c\
		write_i_d.c\
		write_p.c\
		get_number_base_16.c\
		write_c.c\
		write_u.c\
		write_i_d_adding.c\
		write_x.c\
		write_x_adding.c\
		write_big_X.c\
		write_big_X_adding.c\
		write_s.c\
		extra.c
OBJ		= ${SRC:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS		= -Ilibft -Wall -Wextra -Werror

$(NAME):		${OBJ}
				cd libft && make && mv libft.a ../ && cd ..
				ar rc libft.a ${OBJ}
				mv libft.a ${NAME}


.PHONY: 		all bonus clean fclean re

all:			${NAME}

clean:
				${RM} ${OBJ} ${OBJ_BONUS}
				cd libft && make clean

fclean:			clean
				${RM} ${NAME}

re:				fclean all