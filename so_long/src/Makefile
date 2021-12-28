# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:37:47 by mbarra            #+#    #+#              #
#    Updated: 2021/12/28 18:43:15 by mbarra           ###   ########.fr        #
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
		includes.c\

OBJECTS = $(patsubst %.c, %.o, $(SRC))

RM 			= rm -f
FLAGS 		= -Wall -Wextra -Werror
LINKS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(OBJECTS)
	make -C ./mlx
	gcc $(FLAGS) $(OBJECTS) $(LINKS) -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make clean -C ./mlx

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re