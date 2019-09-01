/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ants_amount.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:06:42 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/31 21:53:35 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adjvertex	*get_first_room(t_adjvertex *path)
{
	t_adjvertex *vertex;

	vertex = path;
	while (vertex->next)
		vertex = vertex->next;
	return (vertex);
}

void	print_paths(t_paths *all_paths)
{
	t_paths		*path;
	t_adjvertex	*head;

	path = all_paths;
	while (path)
	{
		printf("\n");
		head = get_first_room(path->path);
		printf("Path len %d\n", path->length);
		while (head)
		{
			printf("(\033[1;35m%s\033[1;37m)", head->vertex->name);
			head = head->prev;
		}printf("\n");
		path = path->next;
	}
	printf("\n\n");
}

void	print_reverese_paths(t_paths *all_paths)
{
	t_paths		*path;
	t_adjvertex	*adj_vertex;
	t_adjvertex	*last;

	path = all_paths;
	adj_vertex = all_paths->path;
	while (path)
	{
		printf("\n");
		adj_vertex = path->path;
		printf("Path len %d\n", path->length);
		while (adj_vertex)
		{
			printf("(\033[1;35m%s\033[1;37m)", adj_vertex->vertex->name);
			last = adj_vertex;
			adj_vertex = adj_vertex->next;
		}
		printf("\n");
		path = path->next;
	}
}

void	print_graph(t_vertex *top_vertex)
{
	t_vertex	*vertex;
	t_adjvertex	*adj_vertex;

	vertex = top_vertex;
	adj_vertex = vertex->adj_vertexes;
	while (vertex)
	{
		adj_vertex = vertex->adj_vertexes;
		printf("\033[1;37mVertex:\033[1;36m[%s]", vertex->name);
		printf("\033[1;37m conected with:");
		while (adj_vertex)
		{
			printf(" (\033[1;33m%s\033[1;37m)", adj_vertex->vertex->name);
			adj_vertex = adj_vertex->next;
		}
		vertex = vertex->next;
		printf("\n");
	}
}

bool	is_only_numbers(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
// Don't forget to add -Wall -Wextra -Werror to ft_printf makefile
int		get_ants_amount()
{
	char	*line;
	char	*flow_one = "maps/flow_one.c";
	char	*flow_ten = "maps/flow_ten.txt";
	char	*flow_thousand = "maps/flow_thousand.txt";
	char	*big = "maps/big.txt";
	char	*big2 = "maps/big.txt";
	char	*big_superposition = "maps/big-superposition.txt";
	char	*subject_one = "maps/subject-1.txt";
	char	*snake_in_stairs = "maps/snake_in_stairs.txt";
	char	*normal_map1 = "maps/normal_map1.txt";
	int		ants_amount;

	close(0);
	open(snake_in_stairs, O_RDONLY);
	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		simple_error_generated(1);
	ants_amount = ft_atoi(line);
	if (!is_only_numbers(line) || ants_amount <= 0)
		simple_error_generated(2);
	printf("Ants amount: %d\n", ants_amount);
	ft_strdel(&line);
	return (ants_amount);
}
