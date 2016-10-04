# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/17 11:18:19 by tandrieu          #+#    #+#              #
#    Updated: 2016/03/03 15:44:51 by tandrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CFLAGS = -Wall -Werror -Wextra
SRC = init.c main.c autre.c get_next_line.c create_map.c resolve.c hook.c  \
	  bmp.c hand.c shoot.c resolve2.c music.c s_win.c

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
