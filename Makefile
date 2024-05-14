# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:22:29 by jcardina          #+#    #+#              #
#    Updated: 2024/05/14 19:44:32 by mcamilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = cub3D
LIBFT = lib/libft/libft.a
PRINTF = lib/ft_printf/libftprintf.a

src = \
	cub3d.c\
	./src/start.c\
	./src/map_check.c\
	./src/map_check1.c\
	./src/info_utils.c\
	./src/utils.c\
	./src/info_check.c\
	./src/player_utils.c\
	./lib/gnl/get_next_line.c\
	./lib/gnl/get_next_file.c\
	./src/hooknmove.c\
	./ray/ray1.c\
	./ray/ray2.c\

OBJ = $(src:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

all: $(NAME)

$(NAME) : $(OBJ)
	make all bonus -C lib/libft
	make -C lib/ft_printf
	make -C mlx_linux/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "\033[32mcubitron compiled\033[0m"
clean:
	make clean -C lib/libft
	make clean -C lib/ft_printf
	rm -f $(OBJ)
	@echo "\033[33mno sauce\033[0m"

fclean: clean
	make fclean -C lib/libft
	make fclean -C lib/ft_printf
	rm -f $(NAME)
	@echo "\033[33m& no name\033[0m"

re: fclean all

we: re
	gdb ./cub3D

.PHONY:		all clean fclean re
