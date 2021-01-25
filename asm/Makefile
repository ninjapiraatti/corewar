FILE = asm

SRC = src/main.c \
src/help_functions.c \
src/header.c src/lexical_analysis.c \
src/get_labels.c \
src/outputbin.c \
../ft_printf/libftprintf.a

INC = /includes/asm.h

.PHONY: all clean fclean re

all: $(FILE)

$(FILE):
	@echo "Compiling..."
	@cd ../ft_printf && make re && cd ../asm
	gcc -I $(INC) -o $(FILE) $(SRC)
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
# 		src/validate.c

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
