# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltesson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:46:25 by ltesson           #+#    #+#              #
#    Updated: 2017/05/09 18:14:32 by ltesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

FLAGS = -Wall -Wextra -Werror

SRC = maintest.c ft_mlx.c ft_drawscene.c

OBJ = maintest.o ft_mlx.o ft_drawscene.o

all: $(NAME)

$(NAME):
	make -C libft/ all
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
