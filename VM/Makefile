# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 10:57:42 by ksalmi            #+#    #+#              #
#    Updated: 2021/03/18 10:57:46 by ksalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRC_NAME = main.c \
parse_flags.c \
player_order.c \
read_from_champ_files.c \
vm_error.c \
vm_tools.c \
print_dump.c \
place_in_memory.c \
carriages.c \
vm_loop.c \
manage_live.c \
manage_st_sti.c \
manage_and_or_xor.c \
manage_ld_ldi_lld_lldi.c \
manage_fork_lfork.c \
manage_zjmp.c \
manage_aff.c \
manage_add_sub.c \
check_args.c \
op_tools.c \
perform_statement.c \
op_tools2.c \
visualizer_ncurses1.c \
visualizer_ncurses2.c \


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
	@gcc $(FLAGS) $(OBJECTS) $(INCLUDES) $(LIB) -o $(NAME) -lncurses
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