FILE = asm

SRC = main.c \
help_functions.c \
header.c \
lexical_analysis.c \
get_labels.c \
write_header_name.c \
get_statement.c \
get_statement_size.c \
get_args.c \
validate.c \
validate_utils.c \
convert_labels.c \
write_hexa.c \
write_arguments.c \
validate_instructions.c \
validate_arguments.c

INC = -I /includes/

LIB = ../ft_printf/libftprintf.a

SRC_DIR = src/

SRCS = $(addprefix $(SRC_DIR),$(SRC))

.PHONY: all clean fclean re

all: $(FILE)

$(FILE):
	@echo "Compiling..."
	@cd ../ft_printf && make re && cd ../asm
	@gcc $(INC) -o $(FILE) $(SRCS) $(LIB)
	@echo "Done."

clean:
	@echo "cleaning libraries..."
	@cd ../ft_printf && make clean && cd ../asm

fclean: clean
	@echo "removing executables..."
	@cd ../ft_printf && make fclean && cd ../asm
	@rm -f $(FILE)

re: fclean all

# NAME = asm

# SRC =	src/main.c \
# 		src/help_functions.c \
# 		src/header.c \
# 		src/lexical_analysis.c \
# 		src/get_labels.c \
#

# CFLAGS = -Wall -Wextra -Werror

# INC = -I ./includes -I ./lib/includes

# LIB = -L ./lib -lft

# .PHONY: all clean fclean re

# all: $(NAME)

# $(NAME):
# 	@make -C lib
# 	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(INC) $(LIB)

# clean:
# 	@make -C lib clean

# fclean: clean
# 	@make -C lib fclean
# 	@rm -f $(NAME)

# re: fclean all
