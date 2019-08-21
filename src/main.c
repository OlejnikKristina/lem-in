/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 18:28:45 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_graph(t_vertex *top_vertex)
{
	t_vertex	*vertex;

	vertex = top_vertex;
	while (vertex)
	{
		printf("Graph name: %s\n", vertex->name);
		vertex = vertex->next;
	}
}


int		main(void)
{
	t_graph	graph;

	create_graph(&graph);
	print_graph(graph.top_vertex);
	free_graph(&graph);
	return (0);
}