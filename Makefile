# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbeata <lbeata@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 18:32:54 by lbeata            #+#    #+#              #
#    Updated: 2021/12/04 18:54:45 by lbeata           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

NAME_BONUS	=	philo_bonus

SRCS	=	main.c \
			ft_atoi.c \
			check.c \
			time.c\
			ft_strlen.c\
			ft_strncmp.c\
			routine.c\
			creat_array.c\
			free.c\

BONUS_SRCS	=	main_bonus.c \
			ft_atoi_bonus.c \
			check_bonus.c \
			time_bonus.c\
			ft_strlen_bonus.c\
			ft_strncmp_bonus.c\
			routine_bonus.c\
			creat_array_bonus.c\
			free_bonus.c\

OBJ_SRC = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS_SRCS:.c=.o)

CC = gcc

REM = rm -f

HEADER = philosophers.h

HEADER_BONUS = phil_bonus.h

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): 			$(OBJ_SRC)
					$(CC) $(FLAGS) $(OBJ_SRC) -o $(NAME)

%.o:	%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus:
	@make OBJ_SRC="$(OBJ_BONUS)" HEADER="$(HEADER_BONUS)" NAME="$(NAME_BONUS)" all

clean:
	$(REM) $(OBJ_SRC) $(OBJ_BONUS) 

fclean: clean
	$(REM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re