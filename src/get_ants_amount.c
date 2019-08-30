/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ants_amount.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:06:42 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/28 20:02:36 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_paths(t_paths *all_paths)
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
		while (adj_vertex)
		{
			printf("(\033[1;33m%s\033[1;37m)", adj_vertex->vertex->name);
			last = adj_vertex;
			adj_vertex = adj_vertex->next;
		}
		// while (last)
		// {
		// 	printf("(\033[1;35m%s\033[1;37m)", last->vertex->name);
		// 	printf("Last elem %p las prev %p, \n", last, last->prev);
		// 	last = last->prev;
		// }
		path = path->next;
		printf("\n");
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

int		get_ants_amount()
{
	char	*line;
//	char	*flow_ten = "maps/flow_ten.txt";
	int		ants_amount;

	close(0);
	open("maps/subject-2.txt", O_RDONLY);
	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		simple_error_generated(1);
	ants_amount = ft_atoi(line);
	if (!is_only_numbers(line) || ants_amount <= 0)
		simple_error_generated(2);
	printf("Ants amount: %d\n", ants_amount);
	ft_strdel(&line);
	return (ants_amount);
}
