# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltesson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:46:25 by ltesson           #+#    #+#              #
#    Updated: 2017/05/15 18:06:04 by ltesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

FLAGS = -Wall -Wextra -Werror

SRC = maintest.c ft_initcam.c ft_vecteur.c ft_mlx.c ft_drawscene.c \
	  ft_intersect.c ft_additem.c ft_addsphere.c ft_error.c

OBJ = $(SRC:.c=.o)

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
