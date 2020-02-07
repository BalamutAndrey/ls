# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geliz <geliz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 12:46:02 by geliz             #+#    #+#              #
#    Updated: 2020/02/07 16:36:34 by geliz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wall -Wextra -Werror
HEADERS = ./includes
SRC_DIR = ./src
SRC = ft_ls.c  $(SRC_DIR)/ft_parsing.c  $(SRC_DIR)/ft_parsing_key.c $(SRC_DIR)/ft_keylist.c \
	  $(SRC_DIR)/ft_open_and_read_dir.c $(SRC_DIR)/ft_sort_print_recurs_call.c \
	  $(SRC_DIR)/ft_create_and_del_t_fin.c  $(SRC_DIR)/ft_parsing_file_check.c \
	  $(SRC_DIR)/ft_file_info.c $(SRC_DIR)/ft_check_access_rights.c $(SRC_DIR)/ft_sort_list.c \
	  $(SRC_DIR)/ft_check_date_time.c  $(SRC_DIR)/ft_check_login_group_size.c  \
	  $(SRC_DIR)/ft_print_error.c  $(SRC_DIR)/ft_printing.c  $(SRC_DIR)/ft_printing_col.c \
	  $(SRC_DIR)/ft_read_stat.c  $(SRC_DIR)/ft_sort_list_reverse.c \
	  $(SRC_DIR)/ft_ioctl.c $(SRC_DIR)/ft_print_c_check_a_a_big.c
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
