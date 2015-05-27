#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:32:10 by flagoutt          #+#    #+#              #
#    Updated: 2015/05/27 14:53:07 by flagoutt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_init.c \
		srcs/ft_mktable.c \
		srcs/mlx_putline.c \
		srcs/mlx_putgrid.c \
		srcs/mlx_putpxl_img.c \
		srcs/mlx_getpxl_img.c \
		srcs/mlx_create_img.c \
		srcs/mlx_hooks.c \
		srcs/wolf_show.c \
		srcs/wolf_raycast.c \
		srcs/mlx_img_cpy.c \
		srcs/setup_intersections_params.c \
		srcs/wolf_move.c
SRCO = $(SRCS:.c=.o)
INCLUDE = -Iincludes/ -Ilibft/
LIBS = -Lminilibx -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft -lm
NAME = Wolf3D

$(NAME): all

all:
	make fclean -C libft/
	make -C libft/
	@echo "#####      Compile tooooouuuuut      #####"
	gcc -o $(NAME) main.c $(SRCS) $(FLAGS) $(INCLUDE) $(LIBS) -g

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re:	fclean all
