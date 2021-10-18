NAME	=	so_long

NAME_1	=	so_long_bonus

SRCS	=	get_next_line_bonus.c	\
			get_next_line_utils_bonus.c \
			get_next_line_bonus_extra.c	\
			ft_strlen.c 	\
			ft_strncmp.c	\
			so_long.c		\
			list.c			\
			ft_lstsize.c	\
			ft_lstadd_back.c	\
			ft_lstlast.c	\
			array.c			\
			verify_array.c	\
			verify_array_content_ECP.c	\
			player.c		\
			initialization_data.c	\
			ft_strdup.c	\
			hook_and_another.c	\
			player_1.c	\
			clean.c	\
			main.c	\


BONUS_SRCS	=	get_next_line_bonus.c	\
			get_next_line_utils_bonus.c \
			get_next_line_bonus_extra.c	\
			ft_strlen_bonus.c 	\
			ft_strncmp_bonus.c	\
			so_long_bonus.c		\
			list_bonus.c			\
			ft_lstsize_bonus.c	\
			ft_lstadd_back_bonus.c	\
			ft_lstlast_bonus.c	\
			array_bonus.c			\
			verify_array_bonus.c	\
			verify_array_content_ECP_bonus.c	\
			player_bonus.c		\
			initialization_data_bonus.c	\
			ft_strdup.c	\
			hook_and_another_bonus.c	\
			player_1_bonus.c	\
			enemy_bonus.c	\
			ft_itoa_bonus.c	\
			player_2_bonus.c	\
			enemy_1_bonus.c	\
			enemy_2_bonus.c	\
			display_bonus.c	\
			clean_bonus.c	\
			appendix_bonus.c	\
			main_bonus.c	\

INCLUDES	=	./

OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	= 	${BONUS_SRCS:.c=.o}

CC 			= gcc -g
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
FLAGS		= -ldl -I${INCLUDES} -L${INCLUDES} -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/



.c.o:
			${CC} ${CFLAGS} -I${INCLUDES} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS) so_long.h
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

all: 		${NAME}

bonus:			${BONUS_OBJS} so_long_bonus.h
				${CC} $(CFLAGS) -o $(NAME_1) $(BONUS_OBJS) $(FLAGS)


clean:			
				${RM} ${OBJS} $(BONUS_OBJS)

fclean:			clean 
				rm -rf ${NAME} ${NAME_1}

re:				fclean all

.PHONY:			all clean fclean 