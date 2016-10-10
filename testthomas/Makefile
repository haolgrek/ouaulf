# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rluder <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/10 15:24:24 by rluder            #+#    #+#              #
#    Updated: 2016/10/10 17:41:03 by rluder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CFLAGS = -Wall -Werror -Wextra
SRC = init.c main.c verif_map.c get_next_line.c create_map.c hook.c
OBJ = $(SRC:.c=.o)
mlx = minilibx_macos
lft = libft

all : $(NAME)

$(NAME) : $(lft) $(mlx)
	make -C $(lft)
	make -C $(mlx)
	gcc $(CFLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -L $(lft) -lft -L $(mlx) -lmlx -framework openGL -framework AppKit

libft:
	make -C libft fclean
	make -C libft

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)

re : fclean all
