# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 09:41:56 by tlouekar          #+#    #+#              #
#    Updated: 2021/01/19 11:07:53 by tlouekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = src/ft_atoi.c \
src/ft_isascii.c \
src/ft_isprint.c \
src/ft_isspace.c \
src/ft_isalpha.c \
src/ft_isdigit.c \
src/ft_isalnum.c \
src/ft_bzero.c \
src/ft_lstdelone.c \
src/ft_lstadd.c \
src/ft_lstdel.c \
src/ft_lstmap.c \
src/ft_lstiter.c \
src/ft_memalloc.c \
src/ft_lstnew.c \
src/ft_memchr.c \
src/ft_memdel.c \
src/ft_memcpy.c \
src/ft_memcmp.c \
src/ft_itoa.c \
src/ft_itoa_base.c \
src/ft_putendl.c \
src/ft_putchar.c \
src/ft_memmove.c \
src/ft_memset.c \
src/ft_putstr.c \
src/ft_putendl_fd.c \
src/ft_putnbr.c \
src/ft_putnbr_fd.c \
src/ft_putstr_fd.c \
src/ft_memccpy.c \
src/ft_strclr.c \
src/ft_strcat.c \
src/ft_strdel.c \
src/ft_strcpy.c \
src/ft_putchar_fd.c \
src/ft_striter.c \
src/ft_strcmp.c \
src/ft_strequ.c \
src/ft_strchr.c \
src/ft_strdup.c \
src/ft_strlen.c \
src/ft_striteri.c \
src/ft_strjoin.c \
src/ft_strmapi.c \
src/ft_strlcat.c \
src/ft_strmap.c \
src/ft_strncat.c \
src/ft_strncpy.c \
src/ft_strncmp.c \
src/ft_strnequ.c \
src/ft_strrchr.c \
src/ft_strsub.c \
src/ft_strnew.c \
src/ft_toupper.c \
src/ft_strnstr.c \
src/ft_tolower.c \
src/ft_strstr.c \
src/ft_wordlen.c \
src/ft_wordcnt.c \
src/ft_strsplit.c \
src/ft_strtrim.c \
src/ft_strcsub.c \
src/get_next_line.c \

INCS = includes/

CFLAGS = -g -Wall -Wextra -Werror

OUTPUT = ft_atoi.o \
ft_isascii.o \
ft_isprint.o \
ft_isspace.o \
ft_isalpha.o \
ft_isdigit.o \
ft_isalnum.o \
ft_bzero.o \
ft_lstdelone.o \
ft_lstadd.o \
ft_lstdel.o \
ft_lstmap.o \
ft_lstiter.o \
ft_memalloc.o \
ft_lstnew.o \
ft_memchr.o \
ft_memdel.o \
ft_memcpy.o \
ft_memcmp.o \
ft_itoa.o \
ft_itoa_base.o \
ft_putendl.o \
ft_putchar.o \
ft_memmove.o \
ft_memset.o \
ft_putstr.o \
ft_putendl_fd.o \
ft_putnbr.o \
ft_putnbr_fd.o \
ft_putstr_fd.o \
ft_memccpy.o \
ft_strclr.o \
ft_strcat.o \
ft_strdel.o \
ft_strcpy.o \
ft_putchar_fd.o \
ft_striter.o \
ft_strcmp.o \
ft_strequ.o \
ft_strchr.o \
ft_strdup.o \
ft_strlen.o \
ft_striteri.o \
ft_strjoin.o \
ft_strmapi.o \
ft_strlcat.o \
ft_strmap.o \
ft_strncat.o \
ft_strncpy.o \
ft_strncmp.o \
ft_strnequ.o \
ft_strrchr.o \
ft_strsub.o \
ft_strnew.o \
ft_toupper.o \
ft_strnstr.o \
ft_tolower.o \
ft_strstr.o \
ft_wordlen.o \
ft_wordcnt.o \
ft_strsplit.o \
ft_strtrim.o \
ft_strcsub.o \
get_next_line.o \

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -I $(INCS) -c $(SRCS)
	ar rc $(NAME) $(OUTPUT)
	ranlib $(NAME)

norm:
	norminette $(SRCS)

clean:
	/bin/rm -f $(OUTPUT)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
