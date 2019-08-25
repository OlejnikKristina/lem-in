# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/08/25 17:17:49 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# 42
# ##start
# start 23 3
# 2 start6 7
# #comment
# 3 [16 3]
# 4 [16 5]
# 5 [9 3]
# 6 [1 5]
# 7 [4 8]
# ##end
# end 9 5
# end-4
# end-6
# start-3
# 4-3
# 5-2
# 3-5
# #another comment
# 4-2
# 2-start
# 7-6
# 7-2
# 7-4
# 6-5
# #another comment

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