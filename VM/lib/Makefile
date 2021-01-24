# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 15:00:26 by ksalmi            #+#    #+#              #
#    Updated: 2021/01/20 18:06:05 by ksalmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = ft_atoi.c \
ft_itoa.c \
ft_count_digits.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_islowercase.c \
ft_isuppercase.c \
ft_strlen.c \
ft_strdup.c \
ft_strnew.c \
ft_strcpy.c \
ft_strncpy.c \
ft_strcat.c \
ft_strncat.c \
ft_strlcat.c \
ft_strcmp.c \
ft_strncmp.c \
ft_strequ.c \
ft_strnequ.c \
ft_strstr.c \
ft_strnstr.c \
ft_strchr.c \
ft_strrchr.c \
ft_strsub.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strsplit.c \
ft_strdel.c \
ft_strclr.c \
ft_strrev.c \
ft_striter.c \
ft_striteri.c \
ft_strmap.c \
ft_strmapi.c \
ft_strswap.c \
ft_swap.c \
ft_memalloc.c \
ft_memdel.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memset.c \
ft_memchr.c \
ft_memmove.c \
ft_toupper.c \
ft_tolower.c \
ft_putchar.c \
ft_putstr.c \
ft_putendl.c \
ft_putnbr.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstadd_back.c \
ft_lstiter.c \
ft_lstmap.c \
ft_free_char_array.c \
ft_free_int_tab.c \
get_next_line.c \
ft_printf.c \
	init.c init_first_time.c save_area_and_cut_specs.c \
	add_to_final_str.c read_specs.c make_formatting.c cs_formatting.c \
	diuf_formatting.c oxpb_formatting.c print_text.c ft_itoa_base_ll.c \
	handle_precision.c ft_itoa_double.c ft_itoa_ll.c implement_flags.c \
	put_field_width.c put_hash_flag.c put_justify_flag.c \
	put_plus_space_flag.c put_zero_flag.c  \
	handle_double_percent.c error.c \
	intlength_double_all_zeroes.c

SRCS = $(addprefix src/,$(SRC_NAME))

OBJ_DIR = obj/

OBJ = $(subst .c,.o,$(SRC_NAME))

OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ))

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "\033[31mCompiling\033[0m $(NAME)\033[31m...\033[0m"
	@gcc -c $(FLAGS)  $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mkdir -p $(OBJ_DIR)
	@mv -f $(OBJ) $(OBJ_DIR)
	@echo "\033[32mCompiled\033[0m $(NAME)\033[32m!\033[0m"

clean:
	@echo "\033[31mRemoving object files\033[0m"
	@/bin/rm -f $(OBJECTS)
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[31mRemoving\033[0m $(NAME)"
	@/bin/rm -f $(NAME)

re: fclean all