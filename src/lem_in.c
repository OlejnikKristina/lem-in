/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:59:28 by kpereira       #+#    #+#                */
/*   Updated: 2019/08/24 18:12:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	check if any of the connecting room is valid for the queue.

	Queue is the head of the queue
	current_connections is the connections of the current vertex in the queue
	to add is the address of the room we will return to add on the queue
*/

t_vertex		*is_valid_vertex(t_adjvertex *queue, t_adjvertex *current_connections, t_vertex *to_add)
{
	t_vertex	*tmp;
	t_adjvertex	*tmp_queue;

	tmp_queue = queue;
	if (!current_connections)
		return (0);
	if (current_connections->vertex->lvl == -2) /* return if the node to add is the end room */
	{
		if (current_connections->next) /* if there is another node to check, check next node */
			return (is_valid_vertex(queue, current_connections->next, to_add));
		return (0); /* else return */
	}
	tmp = current_connections->vertex;
	while (tmp_queue)
	{
		if (tmp_queue->vertex == tmp) /* if the node is repeating */
		{
			if (current_connections->next) /* if there is another node to check, check next node */
				return (is_valid_vertex(queue, current_connections->next, to_add));
			return (0); /* else return */
		}
		if(tmp_queue->next == 0)
			return (tmp);
		tmp_queue = tmp_queue->next;
	}
	return (0);
}

/*
	add_nodes to the end of the queue
*/

void	push_node(t_adjvertex *queue, t_vertex *to_add, int lvl)
{
	t_adjvertex		*tmp;
	t_adjvertex		*new;

	tmp = queue;
	new = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	new->vertex = to_add;
	new->vertex->lvl = lvl; 
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = 0;
}

/*
	loop forward to get the next vertex.
	return when done.
*/

int		next_node(t_adjvertex **current, t_adjvertex **current_connections)
{
	*current_connections = (*current_connections)->next;
	if (!*current_connections)
	{
		*current = (*current)->next;
		if (*current)
			*current_connections = (*current)->vertex->adj_vertexes;
		else
			return 0;
	}
	return (1);
}

/*
	Add correct nodes to the queue and level them.
*/

void	bfs_search(t_adjvertex *queue, t_adjvertex *current, t_adjvertex *current_connections)
{
	t_vertex	*to_add;
	int			i;

	i = 0;
	to_add = 0;
	to_add = is_valid_vertex(queue, current_connections, to_add);
	while (to_add)
	{
		push_node(queue, to_add, current->vertex->lvl > 0 ? current->vertex->lvl + 1 : 1);
		if (!next_node(&current, &current_connections))
			return ;
		to_add = is_valid_vertex(queue, current_connections, to_add);
	}
	if (!next_node(&current, &current_connections))
		return ;
	bfs_search(queue, current, current_connections);

}

/*
	Initializes the queue.
	Set the begin room in the beginning of the list.

	Send the qeueu and the list of connections of the begin room to the add vertex.

	Begin room is lvled as -1 and the end room is lvled as -2.
	the lvl is important to recognize that the end room is the end room.
*/

void	init_queue(t_graph *graph)
{
	t_adjvertex	*queue;

	queue = (t_adjvertex *)malloc(sizeof(t_vertex));

	queue->vertex = graph->top_vertex;
	queue->vertex->lvl = -1;
	graph->end_vertex->lvl = -2;
	queue->next = 0;
	bfs_search(queue, queue, queue->vertex->adj_vertexes);
	free_adjacent_list(queue);
}

// void	init_queue(t_graph *graph, t_adjvertex **queue)
// {
// 	queue = (t_adjvertex *)malloc(sizeof(t_vertex));

// 	queue->vertex = graph->top_vertex;
// 	queue->vertex->lvl = -1;
// 	graph->end_vertex->lvl = -2;
// 	queue->next = 0;
// }

// void	bfs_search()
// {

// }