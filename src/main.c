/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/08/24 17:56:11 by krioliin      ########   odam.nl         */
=======
/*   Updated: 2019/08/24 20:25:25 by krioliin      ########   odam.nl         */
>>>>>>> 1f0ffdfca61aa71e5ac6c0ff297e9f26b46237d9
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//printf_graph function located in get_ants_amount

int		main(void)
{
	t_graph	graph;
	t_paths	paths;


	create_graph(&graph);
	init_queue(&graph);

	find_paths(&graph, &paths);
	
	// print_graph(graph.top_vertex);
	free_graph(&graph);
	return (0);
}