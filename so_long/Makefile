# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/12/17 17:00:35 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h\

SRC =	so_long.c ../map/mapinit_and_pec.c	../map/map_rules.c\
		../gnl/get_next_line.c ../gnl/get_next_line_utils.c\
		ft_putstr.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

RM 			= rm -f
FLAGS 		= -Wall -Wextra #-Werror
LINKS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
# ./mlx/libmlx.a

all: $(NAME) 

$(NAME): $(OBJECTS)
	@make -C ./mlx
	@gcc $(OBJECTS) $(LINKS) -o $(NAME)
#flags

%.o: %.c $(HEADER)
	@gcc -c $< -o $@
#flags
#header?

clean:
	@$(RM) $(OBJECTS)
cleanmlx:
	@make clean -C ./mlx
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re