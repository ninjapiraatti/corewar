FILE = asm

SRC = src/main.c src/help_functions.c src/header.c src/lexical_analysis.c \
src/get_labels.c ../get_next_line/get_next_line.c ../ft_printf/libftprintf.a

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
