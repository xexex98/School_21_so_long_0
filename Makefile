# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2022/01/06 23:53:38 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

HEADER = ./so_long/src/so_long.h
HEADER_BONUS = ./so_long/src/so_long_bonus.h

SRC =		./so_long/src/main.c\
			./so_long/gnl/get_next_line.c\
			./so_long/gnl/get_next_line_utils.c\
			./so_long/src/exit_error.c\
			./so_long/src/map_validity.c\
			./so_long/src/map_validity_2.c\
			./so_long/src/map_draw.c\
			./so_long/src/gameplay.c\
			./so_long/src/includes.c\

SRC_BONUS =	./so_long_bonus/src/so_long_bonus.c\
			./so_long/gnl/get_next_line.c\
			./so_long/gnl/get_next_line_utils.c\
			./so_long_bonus/src/exit_error_bonus.c\
			./so_long_bonus/src/map_validity_bonus.c\
			./so_long_bonus/src/map_validity_2_bonus.c\
			./so_long_bonus/src/map_draw_bonus.c\
			./so_long_bonus/src/gameplay_bonus.c\
			./so_long_bonus/src/includes_bonus.c\

OBJS = $(SRC:%.c=%.o)

OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

RM 			= rm -f
FLAGS 		= -Wall -Wextra -Werror
LINKS		= -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

bonus: $(NAME_BONUS)

.c.o:
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ./so_long/src/mlx
	gcc $(FLAGS) $(OBJS) $(LINKS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C ./so_long/src/mlx
	gcc $(FLAGS) $(OBJS_BONUS) $(LINKS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	make clean -C ./so_long/src/mlx

re: fclean all

.PHONY: all clean fclean re