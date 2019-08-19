# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/08/19 14:33:03 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
SRC			= main.c errors_management.c ft_only_numbers.c \
			creators.c

all: $(NAME)

$(NAME):
	@clang -g -Wall -Wextra -Werror -o $(NAME) \
	$(addprefix src/, $(SRC)) -I includes/ libft/libft.a
	@echo "\033[0;32mLem-in successfully created\033[0m"

fclean:
	rm -f $(NAME)

re: fclean all