/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/23 16:09:36 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//printf_graph function located in get_ants_amount

int		main(void)
{
	t_graph	graph;

	// t_vertex	*tmp;
	// t_adjvertex	*adjs;


	create_graph(&graph);
	bfs_search(&graph);

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
	print_graph(graph.top_vertex);
	free_graph(&graph);
	return (0);
}