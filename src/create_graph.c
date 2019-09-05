/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_graph.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:49:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 15:28:16 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex	*create_vertex(char *name)
{
	t_vertex	*new_vertex;

	new_vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (!new_vertex)
		return (NULL);
	new_vertex->name = ft_strdup(name);
	new_vertex->p_size = 0;
	new_vertex->parents = 0;
	new_vertex->visited = false;
	ft_bzero(new_vertex->ants, sizeof(new_vertex->ants));
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
		{
			if (!ft_strcmp(current->name, name))
				return (NULL);
			current = current->next;
		}
		current->next = create_vertex(name);
	}
	return (current->next);
}

void		end_start_comment(char **line, t_graph *g)
{
	char			start_end_comment;
	static bool		start_vertix;
	char			*name;

	start_end_comment = '\0';
	if (ft_strstr(*line, "##start") || ft_strstr(*line, "##end"))
	{
		if (start_vertix && g->end_vertex)
			error_generated(5, g);
		start_end_comment = (*line)[2];
	}
	if (!start_end_comment)
		return ;
	ft_strdel(line);
	get_next_line(0, line);
	name = get_vertex_name(line, g);
	if (start_end_comment == 's')
	{
		g->top_vertex = graph_insert_first_vertex(g, name);
		start_vertix = true;
	}
	else if (start_end_comment == 'e')
		g->end_vertex = graph_insert_vertex(g, name);
	ft_strdel(&name);
}

/*
**	[add_vertexes] Read ant farm
**	Check if there is: start room (vertex), end room, comment or
**	regular room. Extract name of it. Add it as a new vertex to a graph
*/

char		*add_vertexes(t_graph *graph)
{
	char	*line;
	char	*vertex_name;

	get_next_line(0, &line);
	while (read_vertexes(line))
	{
		if (line[0] == '#')
			end_start_comment(&line, graph);
		else
		{
			vertex_name = get_vertex_name(&line, graph);
			graph_insert_vertex(graph, vertex_name);
			ft_strdel(&vertex_name);
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	return (line);
}

bool		create_graph(t_graph *graph)
{
	char		*first_conection;

	graph->end_vertex = NULL;
	ft_bzero(graph, sizeof(graph));
	graph->n_ants = get_ants_amount();
	first_conection = add_vertexes(graph);
	set_connections(graph, first_conection);
	return (true);
}
