# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 10:52:42 by lde-batz          #+#    #+#              #
#    Updated: 2019/04/11 15:04:05 by lde-batz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = 	main.c\
		win.c\
		read_map.c\
		img.c\
		raycasting.c\
		detection_ver.c\
		detection_hor.c\
		key.c\
		textures.c\
		move.c\
		quit.c\
		mini_map.c\
		segment.c

SRC_DIR = srcs/

OBJ_DIR = objects/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC := $(addprefix $(SRC_DIR), $(SRC))

INC = includes

INCLUDES = $(INC)/image.h  $(INC)/map.h  $(INC)/mini_map.h  $(INC)/raycasting.h  $(INC)/wolf.h

LIB = libft

INC_FLAG = -I$(INC) -I$(LIB)

LIB_FLAG = -L ./$(LIB) -lft -L /usr/local/lib/ -lmlx

GCC = gcc -Wall -Wextra -Werror -o -o1 -o2 -o3

MLX_FLAG = -framework OpenGL -framework AppKit

HEAD = includes/wolf.h

.SILENT:

all: lib $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(INC_FLAG) -o $(NAME) $(SRC) $(LIB_FLAG) $(MLX_FLAG)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Wolf3D"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES) $(LIB)/libft.a
	mkdir -p $(OBJ_DIR)
	$(GCC) $(INC_FLAG) -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

lib:
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -Rf $(OBJ_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Wolf3D"

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Wolf3D"

re: fclean all

.PHONY: all clean fclean re

