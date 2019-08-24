/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/24 17:56:11 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//printf_graph function located in get_ants_amount

int		main(void)
{
	t_graph	graph;

	create_graph(&graph);
	init_queue(&graph);
	print_graph(graph.top_vertex);
	free_graph(&graph);
	return (0);
}