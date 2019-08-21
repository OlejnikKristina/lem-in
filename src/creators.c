/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creators.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:49:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 21:11:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*get_vertex_name(char **line, t_graph *graph)
{
	char	*name;
	int		name_len;

	name_len = findchr(*line, ' ');
	if (name_len == -1 || (*line[0] == 'L'))
	{
		ft_strdel(line);
		error_generated(4, graph);
		return (NULL);
	}
	name = ft_strsub(*line, 0, name_len);
	return (name);
}

t_vertex	*create_vertex(char *name)
{
	t_vertex	*new_vertex;

	new_vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (!new_vertex)
		return (NULL);
	new_vertex->name = ft_strdup(name);
	new_vertex->next = NULL;
	return (new_vertex);
}

t_vertex	*graph_insert_vertex(t_graph *graph, char *name)
{
	t_vertex	*current;

	current = graph->top_vertex;
	if (current == NULL)
	{
		graph->top_vertex = create_vertex(name);
		current = graph->top_vertex;
		if (!graph->top_vertex)
		{
			error_generated(3, graph);
			return (NULL);
		}
	}
	else
	{
		while (current->next)
			current = current->next;
		current->next = create_vertex(name);
	}
	graph->n_vertexes++;
	return (current->next);
}

/*
**	[add_vertexes] Read ant farm
**	Check if there is: start room (vertex), end room, comment or
**	regular room. Extract name of it. Add it as a new vertex to a graph
*/

char	*add_vertexes(t_graph *graph)
{
	char	*line;
	char	*vertex_name;

	get_next_line(0, &line);
	while (!stop_reading_vertexes(line))
	{
		if (line[0] == '#')
			end_start_comment(&line, graph);
		else
		{
			vertex_name = get_vertex_name(&line, graph);
			graph_insert_vertex(graph, vertex_name);
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	return (line);
}

bool	create_graph(t_graph *graph)
{
	char		*vertex_conection;

	graph->end_vertex = NULL;
	ft_bzero(graph, sizeof(graph));
	graph->n_ants = get_ants_amount();
	vertex_conection = add_vertexes(graph);
	return (true);
}
