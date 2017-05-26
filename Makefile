# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltesson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:46:25 by ltesson           #+#    #+#              #
#    Updated: 2017/05/23 15:55:45 by ltesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

FLAGS = -Wall -Wextra -Werror

SRC = maintest.c ft_initcam.c ft_vecteur.c ft_mlx.c ft_drawscene.c \
	  ft_intersect.c ft_scene01.c ft_addsphere.c ft_error.c ft_move.c \
	  ft_morevecteur.c ft_intersphere.c ft_interplan.c ft_addplan.c \
	  ft_intervcylindre.c ft_addvcylindre.c \

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
