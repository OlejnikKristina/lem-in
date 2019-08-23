/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_connections.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 21:23:17 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/23 15:03:29 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
if (adj_list)
	adj_list->next = new_edge;
else
	adj_list = new_edge;
*/

	// printf("Edge between vertext [%p] and [%p]", vertex1, vertex2);
	// printf("First edge between vertext [%s] and [%s]", vertex1->name, vertex2->name);
	// adjacent = vertex1->adj_vertexes;
	// while (adjacent->next)
	// {
	// 	if (adjacent->vertex == vertex2)
	// 		return (1);
	// 	adjacent = adjacent->next;
	// }
	// if (adjacent->vertex == vertex2)
	// 		return (1);
	// adjacent->next = (t_adjvertex *)ft_memalloc(sizeof(t_adjvertex));
	// adjacent->next->vertex = vertex1;
	// adjacent->next->next = NULL;

t_vertex	*find_vertex(t_vertex *list, char *name)
{
	t_vertex	*head;

	head = list;
	while (head)
	{
		//printf("name: %s\n", head->name);
		if (!ft_strcmp(head->name, name))
			return (head);
		head = head->next;
	}
	return (NULL);
}

short	create_edge(t_adjvertex **vertex1_adjlist, t_vertex *vertex2)
{
	t_adjvertex		*adj_list;
	t_adjvertex		*new_edge;

	adj_list = *vertex1_adjlist;
	while (adj_list)
	{
		if (adj_list->vertex == vertex2)
			return (1);
		if (adj_list->next == NULL)
			break ;
		adj_list = adj_list->next;
	}
	new_edge = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	if (!new_edge)
		error_generated(7, (t_graph *)vertex1_adjlist);
	new_edge->vertex = vertex2;
	new_edge->next = NULL;
	(!adj_list) ? (*vertex1_adjlist = new_edge) : (adj_list->next = new_edge);
	return (0);
}

/*
**
**	[graph_insert_edge]
**	Insert the edge (conection) to adjacency list,
**	between vertex with name1 and vertex with name2
**	Return Value 0 if inserting the edge is successful,
**	1 if the edge already exists, or –1 otherwise
**
*/

short	graph_insert_edge(t_graph *graph, char *name1, char *name2)
{
	t_vertex	*vertex1;
	t_vertex	*vertex2;
	t_vertex	*head;

	head = graph->top_vertex;
	vertex1 = NULL;
	vertex2 = NULL;
	while (head)
	{
		vertex1 = (!ft_strcmp(head->name, name1)) ? head : vertex1;
		vertex2 = (!ft_strcmp(head->name, name2)) ? head : vertex2;
		head = head->next;
	}
	if (!vertex1 || !vertex2)
		error_generated(6, graph);
	return (create_edge(&vertex1->adj_vertexes, vertex2));
}

void	set_connections(t_graph *graph, char *first_edge, char *all_names)
{
	char	*line;
	char	**names;

	line = first_edge;
	while (ft_strlen(line))
	{
		if (line[0] != '#')
		{
			names = ft_strsplit(line, '-');
			if (!ft_strstr(all_names, names[0]) || !ft_strstr(all_names, names[1]))
			{
				printf("room1 %s room2 %s\n", names[0], names[1]);
				error_generated(6, graph);
			}
			graph_insert_edge(graph, names[0], names[1]);
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	if (first_edge)
		ft_strdel(&line);
}
