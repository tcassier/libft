# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcassier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 19:23:42 by tcassier          #+#    #+#              #
#     Updated: 2017/11/12 19:40:03 by tcassier         ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./src
SRC_NAME = ft_atoi.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c \
      ft_isprint.c ft_isspace.c ft_islower.c ft_isupper.c ft_memccpy.c \
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c \
	  ft_memoverlap.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strncmp.c \
      ft_strcpy.c ft_strdup.c ft_strndup.c ft_strlcat.c ft_strlen.c \
	  ft_strncat.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c \
      ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
      ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
      ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
	  ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
      ft_putnbr_fd.c ft_lstnew.c ft_lstmap.c ft_lstiter.c ft_lstdelone.c \
      ft_lstdel.c ft_lstadd.c ft_lstadd_back.c ft_lstsize.c get_next_line.c ft_isneg.c
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC_PATH = ./includes
INC_NAME = libft.h
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(INC) $(OBJ) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH) $(INC)
	$(CC) -c $< -o $@ -I $(INC_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re