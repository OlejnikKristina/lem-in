/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:59:28 by kpereira      #+#    #+#                 */
/*   Updated: 2019/08/21 15:59:29 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	test_map_alloc(t_graph *graph)
// {
// 	t_vertex	*node_1;
// 	t_vertex	*node_2;
// 	t_vertex	*node_3;
// 	t_vertex	*node_4;
// 	t_vertex	*node_5;
// 	t_vertex	*node_6;


// 	graph->n_ants = 2;
// 	graph->n_edges = 6;
// 	graph->n_vertexes = 6;

// 	node_1 = (t_vertex *)malloc(sizeof(t_vertex));
// 	node_2 = (t_vertex *)malloc(sizeof(t_vertex));
// 	node_3 = (t_vertex *)malloc(sizeof(t_vertex));
// 	node_4 = (t_vertex *)malloc(sizeof(t_vertex));
// 	node_5 = (t_vertex *)malloc(sizeof(t_vertex));
// 	node_6 = (t_vertex *)malloc(sizeof(t_vertex));

// 	node_1->name = (char *)malloc(sizeof(char) * 2);
// 	node_1->name[0] = '1';
// 	node_1->name[1] = '\0';
// 	node_2->name = (char *)malloc(sizeof(char) * 2);
// 	node_2->name[0] = '2';
// 	node_2->name[1] = '\0';
// 	node_3->name = (char *)malloc(sizeof(char) * 2);
// 	node_3->name[0] = '3';
// 	node_3->name[1] = '\0';
// 	node_4->name = (char *)malloc(sizeof(char) * 2);
// 	node_4->name[0] = '4';
// 	node_4->name[1] = '\0';
// 	node_5->name = (char *)malloc(sizeof(char) * 2);
// 	node_5->name[0] = '5';
// 	node_5->name[1] = '\0';
// 	node_6->name = (char *)malloc(sizeof(char) * 2);
// 	node_6->name[0] = '6';
// 	node_6->name[1] = '\0';

// 	node_1->next = node_2;
// 	node_2->next = node_3;
// 	node_3->next = node_4;
// 	node_4->next = node_5;
// 	node_5->next = node_6;
// 	node_6->next = 0;

// 	node_1->lvl = 0;
// 	node_2->lvl = 0;
// 	node_3->lvl = 0;
// 	node_4->lvl = 0;
// 	node_5->lvl = 0;
// 	node_6->lvl = 0;

// 	graph->end_vertex = node_6;
// 	graph->top_vertex = node_1;

// /*				------------------------------				 */

// 	t_adjvertex		*conn_1;
// 	t_adjvertex		*conn_2;
// 	t_adjvertex		*conn_3;
// 	t_adjvertex		*conn_4;
// 	t_adjvertex		*conn_5;
// 	t_adjvertex		*conn_6;
// 	t_adjvertex		*conn_7;
// 	t_adjvertex		*conn_8;
// 	t_adjvertex		*conn_9;
// 	t_adjvertex		*conn_10;
// 	t_adjvertex		*conn_11;
// 	t_adjvertex		*conn_12;

// 	conn_1 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_2 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_3 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_4 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_5 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_6 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_7 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_8 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_9 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_10 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_11 = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	conn_12 = (t_adjvertex *)malloc(sizeof(t_adjvertex));

// 	conn_1->vertex = node_2;
// 	conn_2->vertex = node_3;
// 	conn_3->vertex = node_5;
// 	conn_4->vertex = node_4;
// 	conn_5->vertex = node_6;
// 	conn_6->vertex = node_6;

// 	conn_7->vertex = node_1;
// 	conn_8->vertex = node_1;
// 	conn_9->vertex = node_2;
// 	conn_10->vertex = node_3;
// 	conn_11->vertex = node_4;
// 	conn_12->vertex = node_5;

// 	node_1->adj_vertexes = conn_1;
// 	conn_1->next = conn_2;
// 	conn_2->next = 0;


// 	node_2->adj_vertexes = conn_4;
// 	conn_4->next = conn_7;
// 	conn_7->next = 0;

// 	node_3->adj_vertexes = conn_3;
// 	conn_3->next = conn_8;
// 	conn_8->next = 0;

// 	node_4->adj_vertexes = conn_5;
// 	conn_5->next = conn_9;
// 	conn_9->next = 0;

// 	node_5->adj_vertexes = conn_6;
// 	conn_6->next = conn_10;
// 	conn_10->next = 0;

// 	node_6->adj_vertexes = conn_11;
// 	conn_11->next = conn_12;
// 	conn_12->next = 0;

// }

/*
	check if any of the connecting room is valid for the queue.

	Queue is the head of the queue
	current_connections is the connections of the current vertex in the queue
	to add is the address of the room we will return to add on the queue
*/

t_vertex		*nodes_to_add(t_adjvertex *queue, t_adjvertex *current_connections, t_vertex *to_add)
{
	t_vertex	*tmp;
	t_adjvertex	*tmp_queue;

	tmp_queue = queue;
	if (!current_connections)
		return (0);
	if (current_connections->vertex->lvl == -2) /* return if the node to add is the end room */
	{
		if (current_connections->next) /* if there is another node to check, check next node */
			return (nodes_to_add(queue, current_connections->next, to_add));
		return (0); /* else return */
	}
	tmp = current_connections->vertex;
	while (tmp_queue)
	{
		if (tmp_queue->vertex == tmp) /* if the node is repeating */
		{
			if (current_connections->next) /* if there is another node to check, check next node */
				return (nodes_to_add(queue, current_connections->next, to_add));
			return (0); /* else return */
		}
		if(tmp_queue->next == 0)
			return (tmp);
		tmp_queue = tmp_queue->next;
	}
	return (0);
}

/*
	add_nodes
*/

void	add_nodes(t_adjvertex *queue, t_vertex *to_add)
{
	t_adjvertex		*tmp;
	t_adjvertex		*new;

	tmp = queue;
	new = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	new->vertex = to_add;
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
	Add correct nodes to the queue.
*/

void	add_vertex(t_adjvertex *queue, t_adjvertex *current, t_adjvertex *current_connections)
{
	t_vertex	*to_add;
	int			i;

	i = 0;
	to_add = 0;
	to_add = nodes_to_add(queue, current_connections, to_add);
	while (to_add)
	{
		add_nodes(queue, to_add);
		if (!next_node(&current, &current_connections))
			return ;
		to_add = nodes_to_add(queue, current_connections, to_add);
	}
	if (!next_node(&current, &current_connections))
		return ;
	add_vertex(queue, current, current_connections);

}

/*
	Initializes the queue.
	Set the begin room in the beginning of the list.

	Send the qeueu and the list of connections of the begin room to the add vertex.

	Begin room is lvled as -1 and the end room is lvled as -2.
	the lvl is important to recognize that the end room is the end room.
*/

void	bfs_search(t_graph *graph)
{
	t_adjvertex	*queue;

	queue = (t_adjvertex *)malloc(sizeof(t_vertex));

	queue->vertex = graph->top_vertex;
	queue->vertex->lvl = -1;
	graph->end_vertex->lvl = -2;
	queue->next = 0;
	add_vertex(queue, queue, queue->vertex->adj_vertexes);
}

// int     main(void)
// {
//     t_graph     graph;

// 	// t_vertex	*tmp;
// 	// t_adjvertex	*adjs;
   
//     test_map_alloc(&graph);

// 	bfs_search(&graph);

// 	// tmp = graph.top_vertex;
// 	// while (tmp)
// 	// {
// 	// 	adjs = tmp->adj_vertexes;
// 	// 	ft_putstr(tmp->name);
// 	// 	ft_putstr(" connects to: ");
// 	// 	while (adjs)
// 	// 	{
// 	// 		ft_putstr(adjs->vertex->name);
// 	// 		ft_putchar(' ');
// 	// 		adjs = adjs->next;
// 	// 	}
// 	// 	ft_putchar('\n');
// 	// 	tmp = tmp->next;
// 	// }
	
	
//     return (0);
// }