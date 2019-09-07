# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/09/07 21:05:33 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror
LIB			= ft_printf/libftprintf.a
NAME		= lem-in
SRC			= main.c get_ants_amount.c\
			create_graph.c free_data.c \
			add_vertexes.c set_connections.c bfs.c \
			path_restore.c send_first_ant.c\
			print_result.c send_ants.c distribute_ants.c \
			additional_functions.c

all: $(NAME)

$(NAME):
	@make -C ft_printf/
	@clang -o $(NAME) $(addprefix src/, $(SRC)) -I includes/ $(LIB)
	@echo "\033[0;32mLem-in successfully created\033[0m"
lem_in:
	@rm -f $(NAME)
	@clang -o $(NAME) -g $(addprefix src/, $(SRC)) -I includes/ $(LIB)
	@echo "\033[0;32mLem-in successfully created\033[0m"
clean:
	@make -C ft_printf/ clean
fclean:
	@rm -f $(NAME)
	@make -C ft_printf/ fclean
re: fclean all
