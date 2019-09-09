/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_queue.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 12:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 12:56:58 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			not_in_queue(t_adjvertex *queue, t_vertex *to_add)
{
	t_adjvertex	*tmp;

	tmp = queue;
	while (tmp)
	{
		if (tmp->vertex == to_add)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_adjvertex	*init_queue(t_graph *graph, t_adjvertex *queue)
{
	queue = (t_adjvertex *)malloc(sizeof(t_vertex));
	queue->vertex = graph->top_vertex;
	queue->next = 0;
	graph->top_vertex->p_size =
		count_connections(graph->top_vertex->adj_vertexes);
	allocate_parents(graph);
	first_linage(graph);
	return (queue);
}

void		push_node(t_adjvertex *queue, t_vertex *to_add)
{
	t_adjvertex		*tmp;
	t_adjvertex		*new;

	tmp = queue;
	new = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	new->vertex = to_add;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = 0;
}
