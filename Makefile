# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: florientakoudad <florientakoudad@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 13:46:42 by floakoud          #+#    #+#              #
#    Updated: 2019/06/17 13:46:49 by florientako      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#**************************************************#

# Couleur !

END			= \033[0m

RED			= \033[0;31m
GREEN		= \033[0;32m

#**************************************************#

NAME = FDF

SRC = main.c ft_checkfile.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft
	@echo "creation de libft [$(GREEN)OK$(END)]"
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@echo "creation fichier objet [$(GREEN)OK$(END)]"
	@gcc -o $(NAME) $(OBJ) $(LIB)
	@echo "creation executable [$(GREEN)OK$(END)]"

clean :
	@make -C libft clean
	@echo "suppression .o libft [$(RED)OK$(END)]"
	@rm -rf $(OBJ)
	@echo "suppression .o Fdf [$(RED)OK$(END)]"

fclean : clean
	@make -C libft fclean
	@echo "suppression libft.a [$(RED)OK$(END)]"
	@rm -rf $(NAME)
	@echo "suppression executable Fdf [$(RED)OK$(END)]"

re : fclean all
