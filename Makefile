# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/08/21 21:17:29 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= lem-in
SRC			= main.c errors_management.c \
			creators.c get_ants_amount.c free_graph.c \
			add_vertexes.c

all: $(NAME)

$(NAME):
	@clang -g -Wall -Wextra -Werror -o $(NAME) \
	$(addprefix src/, $(SRC)) -I includes/ libft/libft.a
	@echo "\033[0;32mLem-in successfully created\033[0m"

fclean:
	rm -f $(NAME)

re: fclean all