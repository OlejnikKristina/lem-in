/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:59:28 by kpereira       #+#    #+#                */
/*   Updated: 2019/08/25 17:06:36 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_to_zero(int	*parents, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		parents[i] = 0;
		i++;
	}
}

int		not_in_queue(t_adjvertex *queue, t_vertex *to_add)
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

/*
	add_nodes to the end of the queue

	also adds charachteristics from the parents to the new node in the queue
*/

void	push_node(t_adjvertex *queue, t_vertex *to_add)
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

void	new_parent(t_graph *graph, t_vertex *to_add)
{
	to_add->parents = (int *)malloc(sizeof(int) * graph->top_vertex->p_size);
	set_to_zero(to_add->parents, graph->top_vertex->p_size);
}


int		chenge_of_aspect(t_vertex *to_add, t_vertex *father, int size, t_graph *graph)
{
	int		i;
	int		rtn;

	i = 0;
	rtn = 0;
	if (father == graph->top_vertex)
		return (1);
	while (i < size)
	{
		if (father->parents[i] != 0 && to_add->parents[i] == 0)
		{
			to_add->parents[i] = father->parents[i] + 1;
			rtn = 1;
		}
		i++;
	}
	return (rtn);
}


void	transmit_charachteristics(t_graph *graph, t_vertex *to_add, t_vertex *father, t_adjvertex *queue)
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

/*
	Add correct nodes to the queue and level them.
*/

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
			if (tmp->vertex != graph->top_vertex && tmp->vertex->visited == false)
				transmit_charachteristics(graph, tmp->vertex, tmp_queue->vertex, tmp_queue);
			tmp = tmp->next;
		}
		tmp_queue = tmp_queue->next;
	}
}


int		count_connections(t_adjvertex *connections)
{
	int		rtn;

	rtn = 0;
	while (connections)
	{
		rtn++;
		connections = connections->next;
	}
	return (rtn);
}

void	allocate_parents(t_graph *graph)
{
	int		*new;

	new = (int *)malloc(sizeof(int) * graph->top_vertex->p_size);
	graph->top_vertex->parents = new;
}


void	first_linage(t_graph *graph)
{
	t_adjvertex	*tmp;
	int			i;

	i = 0;
	tmp = graph->top_vertex->adj_vertexes;
	while (tmp)
	{
		tmp->vertex->parents = (int *)malloc(sizeof(int) * graph->top_vertex->p_size);
		set_to_zero(tmp->vertex->parents, graph->top_vertex->p_size);
		tmp->vertex->parents[i] = 1;
		tmp = tmp->next;
		i++;
	}
}

t_adjvertex	*init_queue(t_graph *graph, t_adjvertex *queue)
{
	queue = (t_adjvertex *)malloc(sizeof(t_vertex));
	queue->vertex = graph->top_vertex;
	queue->next = 0;
	graph->top_vertex->p_size = count_connections(graph->top_vertex->adj_vertexes);
	allocate_parents(graph);
	first_linage(graph);
	return (queue);
}

/*
	Initializes the queue.
	Set the begin room in the beginning of the list.

	Send the queue and the list of connections of the begin room to the add vertex.

	Begin room is lvled as -1 and the end room is lvled as -2.
	the lvl is important to recognize that the end room is the end room.
*/

void	bfs(t_graph *graph, t_paths	*paths)
{
	t_adjvertex	*queue;

	queue = NULL;
	queue = init_queue(graph, queue);
	ft_bzero(paths, sizeof(paths));
	bfs_search(graph, queue, paths);
	free_adjacent_list(queue);
}
