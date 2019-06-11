# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floakoud <floakoud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/11 13:46:42 by floakoud          #+#    #+#              #
#    Updated: 2019/06/11 14:45:57 by floakoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#**************************************************#

# Couleur !

END			= \033[0m

RED			= \033[0;31m
GREEN		= \033[0;32m

#**************************************************#

NAME = FDF

SRC = main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft
	@echo "creation de libft [$(GREEN)OK$(END)]"
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@echo "creation fichier objet [$(GREEN)OK$(END)]"
	@gcc -o $(NAME) $(OBJ) -L libft -lft -lm -lmlx -framework OpenGL -framework AppKit
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
