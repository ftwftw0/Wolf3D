#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/08 17:19:58 by flagoutt          #+#    #+#              #
#    Updated: 2015/06/08 17:22:25 by flagoutt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# **************************************************************************** #
# 		PROGRAM																   #
# **************************************************************************** #
NAME		=	Wolf3D

# **************************************************************************** #
#		SOURCES
# **************************************************************************** #

DIRSRC		=	srcs

SRCS =	$(DIRSRC)/ft_init.c \
        $(DIRSRC)/ft_mktable.c \
        $(DIRSRC)/mlx_putline.c \
        $(DIRSRC)/mlx_putgrid.c \
        $(DIRSRC)/mlx_putpxl_img.c \
        $(DIRSRC)/mlx_getpxl_img.c \
        $(DIRSRC)/mlx_create_img.c \
        $(DIRSRC)/mlx_hooks.c \
        $(DIRSRC)/wolf_show.c \
        $(DIRSRC)/wolf_raycast.c \
        $(DIRSRC)/wolf_raycast_horiz.c \
        $(DIRSRC)/wolf_raycast_verti.c \
        $(DIRSRC)/setup_intersections_params.c \
        $(DIRSRC)/wolf_move.c \
        $(DIRSRC)/maptextures.c \
        $(DIRSRC)/load_txtures.c \
        $(DIRSRC)/wolf_putweapon.c \
        $(DIRSRC)/gettextures.c \
        $(DIRSRC)/wolf_controller.c \
        main.c

# **************************************************************************** #
#		DIRECTORIES
# **************************************************************************** #

DIRBIN		=	bin
BIN			=	$(addprefix $(DIRBIN)/, $(SRCS:.c=.o))
DIRLIST		=	srcs
DIRINC		=	./includes/
DIRINC_FT	=	./libft/
DIRINC_MLX	=	./minilibx/

# **************************************************************************** #
#		COMPILE
# **************************************************************************** #

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
INCS		=	-I$(DIRINC) -I$(DIRINC_FT) -I$(DIRINC_MLX)
LIBS		=   -Lminilibx -lmlx -framework OpenGL -framework AppKit -Llibft/ -lft -lm

# **************************************************************************** #
#		RULES																   #
# **************************************************************************** #

all: libft $(NAME)

libft:
	@$(MAKE) -C libft

$(NAME): $(DIRBIN) $(BIN)
	@printf " ------------------------------------------------------------ \n"
	@$(CC) $(CFLAG) $(BIN) $(LIBS) -o $(NAME)
	@printf "\n\t\tMAKING PROJECT\t\t\t"
	@printf "\t\e[32m[DONE]\e[0m\n\n"
	@printf " ------------------------------------------------------------ \n"

$(addprefix $(DIRBIN)/, %.o) : %.c $(DIRINC) $(DIRINC_FT)
	@mkdir -p $(@D)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(CFLAG) $(INCS) -o $@ -c $<
	@printf "\t\e[32m[DONE]\e[0m\n"

$(DIRBIN) :
	@/bin/mkdir $(DIRBIN); \
		for DIR in $(DIRLIST); \
		do \
		/bin/mkdir $(DIRBIN)/$$DIR; \
		done

clean:
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning binaries...\t\t\t\t\t"
	@/bin/rm -rf $(DIRBIN);
	@printf "\e[32m[DONE]\e[0m\n"

fclean: clean
	@$(MAKE) -C libft $@
	@printf " ------------------------------------------------------------ \n"
	@printf "cleaning project...\t\t\t\t\t"
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[DONE]\e[0m\n"
	@printf " ------------------------------------------------------------ \n"

re: fclean all

.PHONY: clean fclean re libft
