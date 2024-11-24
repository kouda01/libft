# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 10:27:46 by yel-mako          #+#    #+#              #
#    Updated: 2024/11/16 22:24:09 by yel-mako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#projects files

NAME = libft.a

SRC = ft_atoi.c ft_isprint.c ft_memmove.c ft_strchr.c ft_strmapi.c \
	ft_bzero.c ft_itoa.c ft_memset.c ft_strdup.c ft_strncmp.c \
	ft_calloc.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_isalnum.c \
	ft_putendl_fd.c ft_strjoin.c ft_strrchr.c ft_isalpha.c \
	ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c ft_isascii.c \
	ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
	ft_isdigit.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c ft_toupper.c

BONUS_SRC = ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c \
	ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c

#compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror

#objects files

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

#rules

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
	@touch bonus
clean:
	rm -f $(OBJ) $(BONUS_OBJ) bonus
fclean:clean
	rm -f $(NAME)
re: fclean all

#compilation rule for .o files

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
#preventing issues with files named the same as targets

.PHONY: all clean fclean re
