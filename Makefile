# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <geliz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 12:46:02 by geliz             #+#    #+#              #
#    Updated: 2020/01/24 17:40:27 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes
SRC_DIR = ./src
SRC = main.c  $(SRC_DIR)/parsing.c $(SRC_DIR)/keylist.c \
	  $(SRC_DIR)/open_and_read_dir.c $(SRC_DIR)/ft_sort_print_recurs_call.c $(SRC_DIR)/ft_create_and_del_t_fin.c \
	  $(SRC_DIR)/ft_file_info.c $(SRC_DIR)/ft_check_access_rights.c $(SRC_DIR)/ft_sort_list.c
OBJ_DIR = ./obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIB_DIR = ./libft
all: $(NAME)

.PHONY: clean fclean re

$(NAME): LIB $(OBJ)
		@gcc $(FLAGS) $(OBJ) -I$(HEADERS) -L$(LIB_DIR) -lft -o $(NAME)
		@echo "[\x1b[37;42;1m$(NAME) COMPILED\x1b[0m]"

LIB:
		@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		@gcc -c $(FLAGS) -I$(HEADERS) $< -o $@

clean:
		@make clean -C $(LIB_DIR)
		@rm -rf $(OBJ_DIR)
		@echo "[\x1b[37;41;1m$(NAME) OBJECTS DELETED\x1b[0m]"

fclean: clean
		@make fclean -C $(LIB_DIR)
		@rm -f $(NAME)
		@rm -rf $(OBJ_DIR)
		@echo "[\x1b[37;41;1m$(NAME) DELETED\x1b[0m]"

re: fclean all
