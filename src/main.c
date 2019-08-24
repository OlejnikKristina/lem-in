/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/23 21:53:48 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//printf_graph function located in get_ants_amount

int		main(void)
{
	t_graph	graph;

	create_graph(&graph);
	bfs_search(&graph);
<<<<<<< HEAD

	// tmp = graph.top_vertex;
	// while (tmp)
	// {
	// 	adjs = tmp->adj_vertexes;
	// 	ft_putstr(tmp->name);
	// 	ft_putstr(" connects to: ");
	// 	while (adjs)
	// 	{
	// 		ft_putstr(adjs->vertex->name);
	// 		ft_putchar(' ');
	// 		adjs = adjs->next;
	// 	}
	// 	ft_putchar('\n');
	// 	tmp = tmp->next;
	// }
	// print_graph(graph.top_vertex);
=======
	print_graph(graph.top_vertex);
>>>>>>> 5bf1bd957729c37f214ac7b9d0a09bfa25c643fc
	free_graph(&graph);
	sleep(10);
	return (0);
}