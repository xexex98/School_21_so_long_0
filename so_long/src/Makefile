# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2022/01/07 15:47:51 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

HEADER		=	so_long.h\

HEADER_B	=	so_long_bonus.h\

SRC =		../gnl/get_next_line.c\
			../gnl/get_next_line_utils.c\
			exit_error.c\
			gameplay.c\
			includes.c\
			main.c\
			map_draw.c\
			map_validity_2.c\
			map_validity.c\

SRC_B =		../gnl/get_next_line.c\
			../gnl/get_next_line_utils.c\
			exit_error_bonus.c\
			gameplay_bonus.c\
			includes_bonus.c\
			main_bonus.c\
			map_draw_bonus.c\
			map_validity_2_bonus.c\
			map_validity_bonus.c\

OBJS	= $(SRC:.c=.o)
OBJS_B	= $(SRC_B:.c=.o)

RM 			= rm -f
FLAGS 		= -Wall -Wextra -Werror
LINKS		= -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c  $(HEADER) $(HEADER_B)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C ../mlx
	gcc $(FLAGS) $(LINKS) $(OBJS) -o $(NAME)

bonus: $(OBJS_B) $(HEADER_B)
	make -C ../mlx
	gcc $(FLAGS) $(LINKS) $(OBJS_B) -o $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	make clean -C ../mlx

re: fclean all

.PHONY: bonus all clean fclean re