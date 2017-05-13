# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romontei <romontei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 13:26:38 by romontei          #+#    #+#              #
#*   Updated: 2015/03/25 17:46:23 by romontei         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCFILES = main.c\
		   key_entry.c\
		   draw.c\
		   raycast.c\
		   read_map.c\
		   motion_move.c\
		   load_m.c\
		   gnl/get_next_line.c\

SRC = $(addprefix ./,$(SRCFILES))
OBJECTS = $(SRC:./%.c=obj/%.o)
GRAPH = -lmlx -framework openGL -framework AppKit

Y=\033[0;33m
R=\033[0;31m
G=\033[0;32m
E=\033[39m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(Y)[COMPILING WOLF3D]$(E)"
	make -C libft
	gcc -o $(NAME) -Wall -Wextra -Werror $(OBJECTS) -I ./libft  -L ./libft -lft $(GRAPH)
	@echo "$(G)[COMPILATION DONE !]$(E)"
	@echo "$(R)[ENJOY THE WOLF3D !]$(E)"

$(OBJECTS): obj/%.o : ./%.c
	@echo "$(Y)[OBJECT PREPARATION]$(E)"
	mkdir -p $(dir $@)
	gcc -o $@ -g -Wall -Wextra -Werror -I ./libft  -c $<
	@echo "$(G)[PREPARATION DONE !]$(E)"

clean:
	@echo "$(R)[ClEANING]$(E)"
	rm -rf obj
	make clean -C libft

fclean: clean
	@echo "$(R)[TOTAL ClEANING]$(E)"
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: clean
