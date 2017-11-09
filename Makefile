
#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/07/06 09:32:29 by cpirlot           #+#    #+#             *#
#*   Updated: 2017/10/06 13:42:16 by cpirlot          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
LIB = library/libft
SRC = src
FILES = $(SRC)/main.c $(SRC)/read_input.c $(SRC)/validate.c $(SRC)/error.c\
	$(SRC)/trim_tetri.c

TMP = Makefile~  $(SRC)/fillit.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@echo Project $(NAME)
	@$(CC) -o $(NAME) $(FLAGS) $(FILES) -I $(LIB) -L $(LIB) -lft

clean :
	@echo clean :"\n\tTemporary files deteleted"
	@rm -f $(TMP)

fclean : clean
	@echo fclean :"\n\tExec file deleted"
	@rm -f $(NAME)

re : fclean all