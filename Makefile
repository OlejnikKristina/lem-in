# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/18 20:29:00 by krioliin       #+#    #+#                 #
#    Updated: 2019/09/09 20:50:01 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror
LIB			= ft_printf/libftprintf.a
NAME		= lem-in
SRC			= main.c get_ants_amount.c add_end_room.c \
			create_graph.c free_data.c \
			add_vertexes.c set_connections.c bfs.c bfs_help.c \
			path_restore.c send_first_ant.c\
			print_result.c send_ants.c distribute_ants.c \
			additional_functions.c bfs_queue.c \
			path_restore_help.c

all: $(NAME)

$(NAME):
	@make -C ft_printf/
	@clang -o $(NAME) $(FLAGS) $(addprefix src/, $(SRC)) \
	-I includes/ $(LIB) \
	-I ft_printf/includes/ -I ft_printf/libft/includes/ -g
	@echo "\033[0;32mLem-in successfully created\033[0m"
lemin:
	@rm -f $(NAME)
	@clang -o $(NAME) $(FLAGS) -g $(addprefix src/, $(SRC)) \
	-I includes/ $(LIB) \
	-I ft_printf/includes/ -I ft_printf/libft/includes/
	@echo "\033[0;32mLem-in successfully created\033[0m"
clean:
	@make clean -C ft_printf/

fclean:
	@rm -f $(NAME)
	@make fclean -C ft_printf/

re: fclean all
