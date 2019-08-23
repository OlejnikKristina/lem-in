/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_graph.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:49:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/23 17:58:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex	*create_vertex(char *name, int id)
{
	t_vertex	*new_vertex;

	new_vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (!new_vertex)
		return (NULL);
	new_vertex->name = ft_strdup(name);
	new_vertex->id = id + 1;
	new_vertex->next = NULL;
	return (new_vertex);
}

t_vertex	*graph_insert_vertex(t_graph *graph, char *name)
{
	t_vertex	*current;

	current = graph->top_vertex;
	if (current == NULL)
	{
		graph->top_vertex = create_vertex(name, 0);
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
		current->next = create_vertex(name, current->id);
	}
	graph->n_vertexes++;
	return (current->next);
}

void	end_start_comment(char **line, t_graph *g, char **all_names)
{
	char		start_end_comment;
	bool static	start_vertix;
	char		*name;

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
	add_name_to_strlist(all_names, name);
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

char	*add_vertexes(t_graph *graph, char **all_names)
{
	char	*line;
	char	*vertex_name;

	get_next_line(0, &line);
	while (read_vertexes(line))
	{
		if (line[0] == '#')
			end_start_comment(&line, graph, all_names);
		else
		{
			vertex_name = get_vertex_name(&line, graph);
			graph_insert_vertex(graph, vertex_name);
			add_name_to_strlist(all_names, vertex_name);
		}
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	return (line);
}

bool	create_graph(t_graph *graph)
{
	char		*first_conection;
	char		*all_names;

	all_names = NULL;
	graph->end_vertex = NULL;
	ft_bzero(graph, sizeof(graph));
	graph->n_ants = get_ants_amount();
	first_conection = add_vertexes(graph, &all_names);
	printf("%s\n", all_names);
	set_connections(graph, first_conection, all_names);
	return (true);
}
