NAME	=	push_swap

NAME_1	=	checker

SRCS	=	change_a.c		\
			ft_atoi_add.c	\
			ft_atoi.c	 	\
			push_swap.c 	\
			push.c			\
			rev_rotate.c	\
			rotate.c		\
			swap.c			\
			verify_data.c	\
			change_between_full.c	\
			change_bfh.c	\
			definition_min_max.c	\
			super_method.c	\

BONUS_SRCS = ft_atoi_add.c	\
			ft_atoi.c	 	\
			push_swap_bonus.c 		\
			push_bonus.c			\
			rev_rotate_bonus.c		\
			rotate_bonus.c			\
			swap_bonus.c			\
			verify_data_bonus.c		\
			change_bfh.c			\
			ft_strncmp.c	\
			ft_itoa.c		\
			ft_strdup.c		\
			ft_strlen.c		\
			handel_bonus.c	\

INCLUDES	=	./

OBJS		= 	${SRCS:.c=.o}

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

CC			= 	gcc -g
RM			= 	rm -f

CFLAGS		= 	-g -Wall -Werror -Wextra 

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} push_swap.h
				gcc -o $(NAME) $(OBJS)

all:			${NAME}

bonus:			${BONUS_OBJS} bonus_push_swap.h
				gcc -o ${NAME_1} $(BONUS_OBJS)

clean:			
				${RM} ${OBJS} $(BONUS_OBJS)

fclean:			clean 
				rm -rf ${NAME} ${NAME_1}

re:				fclean all

.PHONY:			all clean fclean 