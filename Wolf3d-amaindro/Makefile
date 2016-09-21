# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaindro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 14:15:04 by amaindro          #+#    #+#              #
#    Updated: 2016/03/17 14:23:41 by amaindro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c \
		   draw.c \
		   draw2.c \
		   get_next_line.c \
		   hook.c \
		   tex.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc

EXE = Wolf3d

LIB = libft/libft.a

MAKELIB = make -C ./libft

CLEANLIB = make clean -C ./libft

FCLEANLIB = make fclean -C ./libft

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit

all : $(EXE)

$(EXE) :
	@$(MAKELIB)
	@$(CC) -I $(LIB) -c $(SRC_NAME)
	@$(CC) -o $(EXE) $(CFLAGS) $(OBJ_NAME) -L libft/ -lft

clean :
	@rm -rf $(OBJ_NAME)
	@$(CLEANLIB)

fclean : clean
	@rm -rf $(EXE)
	@$(FCLEANLIB)

re : fclean all

.PHONY: all clean fclean re
