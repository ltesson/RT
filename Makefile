# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltesson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 15:46:25 by ltesson           #+#    #+#              #
#    Updated: 2017/06/17 19:30:31 by ltesson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_initcam.c ft_vecteur.c ft_mlx.c ft_drawscene.c \
	  ft_intersect.c ft_addsphere.c ft_error.c ft_move.c \
	  ft_morevecteur.c ft_intersphere.c ft_interplan.c ft_addplan.c \
	  ft_intercylindre.c ft_addcylindre.c ft_intercone.c ft_addcone.c \
	  ft_produitscalaire.c ft_getnormevecteur.c ft_getnormale.c \
	  ft_getnormplan.c ft_getnormcyl.c ft_getnormcone.c ft_getlight.c \
	  ft_addspot.c ft_intercheck.c ft_distance.c ft_readfile.c \
	  ft_readspot.c ft_readsphere.c ft_readplan.c ft_readcylindre.c \
	  ft_readcone.c ft_addlist.c ft_readcolor.c ft_readcamera.c \
	  ft_initscene.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ all
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

truc:
	make -C libft/ all
	make -C minilibx/ all
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

retruc: fclean truc
