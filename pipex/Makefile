NAME	=	pipex

NAME_1	=	pipex_bonus

SRCS	=	ft_split.c 		\
			ft_strdup.c 	\
			ft_strjoin.c 	\
			ft_strlen.c 	\
			ft_substr.c 	\
			pipex.c 		\
			pipex_extra.c	\
			pre_definition.c	\

BONUS_SRCS	=	ft_split.c 		\
				ft_strdup.c 	\
				ft_strjoin.c 	\
				ft_strlen.c 	\
				ft_substr.c 	\
				ft_strncmp.c	\
				get_next_line_utils.c	\
				get_next_line.c	\
				pipex_bonus_extra.c	\
				pipex_bonus.c	\
				pipex_here_doc.c	\

INCLUDES	=	./

OBJS		= 	${SRCS:.c=.o}

BONUS_OBJS	= 	${BONUS_SRCS:.c=.o}

CC			= 	gcc -g
RM			= 	rm -f

CFLAGS		= 	-g -Wall -Werror -Wextra 

.c.o:
				${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} pipex.h
				gcc -o $(NAME) $(OBJS)

all:			${NAME}

bonus:			${BONUS_OBJS} pipex_bonus.h
				gcc -o ${NAME_1} $(BONUS_OBJS)

clean:			
				${RM} ${OBJS} $(BONUS_OBJS)

fclean:			clean 
				rm -rf ${NAME} ${NAME_1}

re:				fclean all

.PHONY:			all clean fclean 