# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 17:59:28 by htaheri           #+#    #+#              #
#    Updated: 2023/08/30 12:05:05 by htaheri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	     := so_long
CFLAGS	     := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX	     := ./MLX42

HEADERS	     := -I ./include -I $(LIBMLX)/include
LIBS	     := $(LIBMLX)/build/libmlx42.a -ldl -L"/Users/htaheri/.brew/Cellar/glfw/3.3.8/lib" -lglfw -pthread -lm

LIBFT_DIR    =     lib/libft
LIBFT        =     $(LIBFT_DIR)/libft.a

GNL_DIR      =     lib/get_next_line
GNL          =     $(GNL_DIR)/libgnl.a

SRCS	    :=  src/map_validation/enemy.c src/map_validation/img_texture.c src/map_validation/img_texture2.c src/map_validation/main.c \
				src/map_validation/map_initialize.c src/map_validation/map_valid.c src/map_validation/map_valid2.c src/map_validation/moves.c \
				src/map_validation/render_map.c src/map_validation/update_map.c
				
OBJS        := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42 $(LIBMLX); \
	fi
	@printf "\n \033[32mMaking LIBMLX ...\n\033[0m"; \
	cmake $(LIBMLX) -B $(LIBMLX)/build && cmake --build $(LIBMLX)/build -j4; \
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl
	
$(LIBFT):
	@printf "\n \033[32mMaking LIBFT ... \033[0m"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(MAKE) -s bonus -C $(LIBFT_DIR)

$(GNL):
	@printf "\n \033[32mMaking GNL ...\033[0m"
	@$(MAKE) -s -C $(GNL_DIR)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(GNL_DIR) fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx