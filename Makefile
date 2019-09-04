# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/08/31 19:17:23 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror
LIB			= ft_printf/libftprintf.a
NAME		= lem-in
SRC			= main.c errors_management.c \
			create_graph.c get_ants_amount.c free_data.c \
			add_vertexes.c set_connections.c bfs.c \
			path_restore.c print_result2.c sort_paths.c

all: $(NAME)

$(NAME):
	@clang -g -o $(NAME) \
	$(addprefix src/, $(SRC)) -I includes/ $(LIB)
	@echo "\033[0;32mLem-in successfully created\033[0m"

fclean:
	@rm -f $(NAME)
re: fclean all
