#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfautier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:54:38 by rfautier          #+#    #+#              #
#    Updated: 2017/12/27 10:46:55 by rfautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_NAME =	main.c\
			error.c\
			list.c\
			trie.c\
			affichage.c\
			optionR.c \
			listR.c \
		 	trie_date.c\
		 	checkerror.c

SRC_PATH = .
OBJ_PATH = .
CC = gcc
CFLAGS = -Wall -Wextra
CPPFLAGS = -I. -I./libft/
LDFLAGS = -Llibft/
LDLIBS = -lft
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

.PHONY: all, clean, fclean, re

clean:
		/bin/rm -f $(OBJ)
		make clean -C ./libft
fclean: clean
		/bin/rm -f $(NAME)
		make fclean -C ./libft

re: fclean all