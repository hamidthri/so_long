# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 17:59:28 by htaheri           #+#    #+#              #
#    Updated: 2023/09/21 18:35:48 by htaheri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	     := so_long
LIBMLX	     := ./MLX42

LIBS	     := $(LIBMLX)/build/libmlx42.a -ldl -L"$(HOME)/.brew/Cellar/glfw/3.3.8/lib" -lglfw -pthread -lm

LIBFT_DIR    =     lib/libft
LIBFT        =     $(LIBFT_DIR)/libft.a

GNL_DIR      =     lib/get_next_line
GNL          =     $(GNL_DIR)/libgnl.a
CC			 = cc
CFLAGS	     := -Wextra -Wall -Werror -g $(LIBS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl

SRCS	    :=  src/enemy.c src/img_texture.c src/img_texture2.c src/main.c \
				src/map_initialize.c src/map_valid.c src/map_valid2.c src/moves.c \
				src/render_map.c src/update_map.c src/printing.c
				
all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

mlx:
	git clone https://github.com/codam-coding-college/MLX42 $(LIBMLX); \
	cmake $(LIBMLX) -B $(LIBMLX)/build && cmake --build $(LIBMLX)/build -j4

$(LIBFT):
	@printf "\n \033[32mMaking LIBFT ... \033[0m"
	$(MAKE) -s -C $(LIBFT_DIR)
	$(MAKE) -s bonus -C $(LIBFT_DIR)

$(GNL): 
	@printf "\n \033[32mMaking GNL ...\033[0m"
	$(MAKE) -s -C $(GNL_DIR)


clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	$(MAKE) -s -C $(LIBFT_DIR) fclean
	$(MAKE) -s -C $(GNL_DIR) fclean
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx