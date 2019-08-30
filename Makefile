# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/08/28 11:26:10 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# 3 2 2
# ##start
# start 4 0
# ##end
# end 4 6
# 4 0 4
# 1 4 2
# 2 4 4
# 5 8 2
# 6 8 4
# start-1
# 3-4
# 2-4
# 1-5
# 6-5
# end-6
# 1-2
# 2-end
# 3-start

LIB			= ft_printf/libftprintf.a
NAME		= lem-in
SRC			= main.c errors_management.c \
			create_graph.c get_ants_amount.c free_data.c \
			add_vertexes.c set_connections.c lem_in.c \
			find_paths.c print_result.c

all: $(NAME)

$(NAME):
	@clang -g -Wall -Wextra -Werror -o $(NAME) \
	$(addprefix src/, $(SRC)) -I includes/ $(LIB)
	@echo "\033[0;32mLem-in successfully created\033[0m"

fclean:
	@rm -f $(NAME)

re: fclean all