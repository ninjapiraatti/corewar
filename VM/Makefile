# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orantane <orantane@student.hive.fi>	    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 14:58:42 by ksalmi            #+#    #+#              #
#    Updated: 2020/11/06 19:43:27 by ksalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_NAME = main.c \
parse_flags_player_order.c \
read_from_champ_files.c \
vm_error.c \
vm_tools.c \
print_hex.c \
place_in_memory.c \
carriages.c \
vm_loop.c \
<<<<<<< HEAD
manage_st.c \
=======
manage_and.c
>>>>>>> 77d08f012ec03080614a2c5311fb2a8c6edd07e7


SRC_DIR = src/

LIB_DIR = lib/

LIB = lib/libft.a

OBJ_DIR = obj/

INCLUDES = -I includes/ -I lib/includes/

SRCS = $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ = $(subst .c,.o,$(SRC_NAME))

OBJECTS = $(addprefix $(OBJ_DIR),$(OBJ))

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@echo "\033[31mCompiling\033[0m $(NAME)\033[31m...\033[0m"
	@gcc -c $(FLAGS)  $(SRCS) $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	@mv -f $(OBJ) $(OBJ_DIR)
	@gcc $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIB) -o $(NAME)
	@echo "\033[32mCompiled\033[0m $(NAME)\033[32m!\033[0m"

clean:
	@make clean -C $(LIB_DIR)
	@echo "\033[31mRemoving object files\033[0m"
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@echo "\033[31mRemoving\033[0m $(NAME)"
	@/bin/rm -f $(NAME)

re: fclean all