# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sepherd <sepherd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 16:33:57 by arecce            #+#    #+#              #
#    Updated: 2023/10/08 00:02:49 by sepherd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = libft/libft.a

SRCS = cub3d.c src/check_file.c src/check_utils.c \
		 src/draw.c src/init.c src/check_utils2.c \
		 src/utils.c src/check_map.c src/ray.c \
		 src/textures.c src/ray_utils.c src/movement.c \
		 src/movement_utils.c src/tex_utils.c src/check_map_utils.c \
		 src/textures_utils.c src/minimap.c

MLX_L = mlx_linux/
# MLX = mlx/

OBJS = $(SRCS:.c=.o)

LIB_L = mlx_linux/libmlx.a
UNAME = $(shell uname)
LIB = libmlx.dylib

# LIBS = -framework OpenGL -lm -framework AppKit
# LIBS_L = -lm -L/usr/X11R6/lib -lmlx -lXext -lX11
LIBS_L = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz #scuola

GREEN = \033[1;32m
RED = \033[1;31m
BLU = \033[1;34m
# YEL = \033[1;33m
# WHT = \033[1;37m
EOC = \033[1;0m

# %.o: %.c
# @$(CC) -I ${MLX} -c $< -o $@

#ifeq ($(shell uname),Darwin)
# ifdef __APPLE__
# 	${NAME}: $(OBJS)
# 			@echo "$(BLU)Compiling libraries...$(EOC)"
# 			@${MAKE} -C libft
# 			@make -C mlx/
# 			@mv mlx/libmlx.dylib .
# 			@echo "$(GREEN)Libraries done.$(EOC)"
# 			@echo "$(BLU)Compiling cub3d...$(EOC)"
# 			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBS) $(LIBFT)
# 			@echo "$(GREEN)Cub3d build completed.$(EOC)"
# else
# 	${NAME}: ${SRCS}
# 			@${MAKE} -C libft
# 			@make re -C ${MLX_L}
# 			@mv ${MLX_L}libmlx_${UNAME}.a .
# 			${CC} ${CFLAGS} ${SRCS} -o ${NAME} ${LIB_L} ${LIBS_L} ${LIBFT}
# endif

# ${NAME}: $(OBJS)
# 	@echo "$(BLU)Compiling libraries...$(EOC)"
# 	@${MAKE} -C libft
# 	@make -C mlx/
# 	@mv mlx/libmlx.dylib .
# 	@echo "$(GREEN)Libraries done.$(EOC)"
# 	@echo "$(BLU)Compiling cub3d...$(EOC)"
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBS) $(LIBFT)
# 	@echo "$(GREEN)Cub3d build completed.$(EOC)"

${NAME}: ${SRCS}
	@${MAKE} -C libft
	@make re -C ${MLX_L}
	@mv ${MLX_L}libmlx_${UNAME}.a .
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME} ${LIB_L} ${LIBS_L} ${LIBFT}

all: ${NAME}

clean:
	@echo "$(RED)Removing .o files...$(EOC)"
	@rm -f $(OBJS)
# @rm -f libmlx.dylib
	@rm -f libmlx.a
	@rm -f libmlx_${UNAME}.a
	@${MAKE} -C libft clean
# @${MAKE} -C mlx clean
	@${MAKE} -C mlx_linux clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(RED)Removing the latest files...$(EOC)"
	@rm -f $(NAME)
	@${MAKE} -C libft fclean
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re