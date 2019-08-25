/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/25 21:09:49 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph	graph;
	t_paths	paths;

	ft_printf("Printf succsesfuly includet\n");
	create_graph(&graph);
	bfs(&graph);
	find_paths(&graph, &paths);
	shortest_paths(&graph, &paths);
//	print_result(&paths, graph.top_vertex ,graph.n_ants);
//	print_all_paths(&paths, &graph);
//	print_graph(graph.top_vertex);
	free_data(&graph);
	return (0);
}