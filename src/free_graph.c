/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:11:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/23 17:57:58 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	free_adj_list(t_adjvertex *adj_list)
// {
// 	t_adjvertex	*adjlist;
// 	t_adjvertex	*temp;

// 	adjlist = adj_list;
// 	while (adjlist)
// 	{
// 		temp = adjlist->next;
// 		free(adjlist);
// 		adjlist = temp;
// 	}
// }

void	free_graph(t_graph *graph)
{
	t_vertex *head;
	t_vertex *temp;

	head = graph->top_vertex;
	//free(graph->end_vertex);
	while (head)
	{
		//head->adj_vertexes
		(head->name) ? ft_strdel(&head->name) : 1;
		temp = head->next;
		(head) ? free(head) : 1;
		head = temp;
	}
}
