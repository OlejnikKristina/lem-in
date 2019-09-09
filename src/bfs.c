/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:59:28 by kpereira       #+#    #+#                */
/*   Updated: 2019/09/09 12:55:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	new_parent(t_graph *graph, t_vertex *to_add)
{
	to_add->parents = (int *)malloc(sizeof(int) * graph->top_vertex->p_size);
	set_to_zero(to_add->parents, graph->top_vertex->p_size);
}

void	transmit_charachteristics(t_graph *graph, t_vertex *to_add,
	t_vertex *father, t_adjvertex *queue)
{
	if (!to_add->parents)
		new_parent(graph, to_add);
	if (chenge_of_aspect(to_add, father, graph->top_vertex->p_size, graph))
	{
		if (not_in_queue(queue, to_add))
			push_node(queue, to_add);
	}
	(void)to_add;
}

void	bfs_search(t_graph *graph, t_adjvertex *queue, t_paths *paths)
{
	t_adjvertex	*tmp;
	t_adjvertex	*tmp_queue;
	int			i;

	i = 0;
	tmp_queue = queue;
	while (tmp_queue)
	{
		tmp = tmp_queue->vertex->adj_vertexes;
		while (tmp)
		{
			if (tmp->vertex == graph->end_vertex)
			{
				restore_path(graph, tmp_queue->vertex, paths);
				tmp = tmp->next;
				continue ;
			}
			if (tmp->vertex != graph->top_vertex &&
				tmp->vertex->visited == false)
				transmit_charachteristics(graph, tmp->vertex,
					tmp_queue->vertex, tmp_queue);
			tmp = tmp->next;
		}
		tmp_queue = tmp_queue->next;
	}
}

void	bfs(t_graph *graph, t_paths *paths)
{
	t_adjvertex	*queue;

	queue = NULL;
	queue = init_queue(graph, queue);
	ft_bzero(paths, sizeof(paths));
	bfs_search(graph, queue, paths);
	free_adjacent_list(queue);
}
