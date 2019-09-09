/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 20:46:53 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_graph	graph;
	t_paths	paths;

	create_graph(&graph);
	bfs(&graph, &paths);
	send_ants(&paths, &graph);
	free_data(&graph, &paths);
	return (0);
}
