/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/04 20:14:31 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph	graph;
	t_paths	paths;
	t_paths	*holder;
	int		paths_amount;

	create_graph(&graph);
	bfs(&graph, &paths);
	holder = &paths;
	paths_amount = get_paths_amount(&paths);
	holder = sort_paths(&holder, paths_amount + paths_amount / 2);
	print_result(holder, &graph);

//	print_paths(&paths);
//	print_graph(graph.top_vertex);
	free_data(&graph, &paths);
	return (0);
}