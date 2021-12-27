# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/12/27 19:04:05 by mbarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h get_next_line.h\

SRC =	so_long.c\
		../gnl/get_next_line.c\
		../gnl/get_next_line_utils.c\
		exit_error.c\
		map_validity.c\
		map_validity_2.c\
		map_draw.c\
		gameplay.c\

OBJECTS = $(patsubst %.c, %.o, $(SRC))

RM 			= rm -f
FLAGS 		= -Wall -Wextra -Werror -D BUFFER_SIZE=1 
LINKS		= -Lmlx -lmlx -framework OpenGL -framework AppKit
# ./mlx/libmlx.a

all: $(NAME) 

$(NAME): $(OBJECTS)
	@make -C ./mlx
	@gcc $(OBJECTS) $(LINKS) -o $(NAME)
	@rm *.o
#flags

%.o: %.c $(HEADER)
	@gcc -c $< -o $@
#flags
#header?

clean:
	@$(RM) $(OBJECTS)
cleanmlx:
	@make clean -C ./mlx
#fclean
f: clean
	@$(RM) $(NAME)

re: f all

.PHONY: all clean f re