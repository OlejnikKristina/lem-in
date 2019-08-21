/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creators.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:49:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 16:55:39 by krioliin      ########   odam.nl         */
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
	new_vertex->next = NULL;
	return (new_vertex);
}

t_vertex	*graph_insert_first_vertex(t_graph *graph, char *name)
{
	t_vertex	*new_top_vertex;

	new_top_vertex = create_vertex(name);
	new_top_vertex->next = graph->top_vertex;
	graph->top_vertex = new_top_vertex;
	return (new_top_vertex);
}

t_vertex	*graph_insert_vertex(t_graph *graph, char *name)
{
	t_vertex	*current;

	current = graph->top_vertex;
	if (current == NULL)
	{
		graph->top_vertex = create_vertex(name);
		if (!graph->top_vertex)
		{
			//Stop program executing. Free graph
			error_generated(3);
			return (-1);
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

char	*get_vertex_name(char **line)
{
	char	*name;
	int		name_len;

	name_len = findchr(*line, ' ');
	if (!is_only_space_num(*line) || name_len == -1 || (*line[0] == 'L'))
	{
		ft_strdel(line);											// Free top vertex
		error_generated(4);											// You can send here line whith error
		return (NULL);
	}
	name = ft_strsub(*line, 0, name_len);
	return (name);
}

void	end_start_comment(char **line, t_graph *g)
{
	char		start_end_comment;
	bool static	start_vertix;

	start_end_comment = '\0';
	if (ft_strstr(*line, "##start") || ft_strstr(*line, "##end"))
	{
		if (start_vertix || g->end_vertex)
			error_generated(5);										//Stop program executing. Free g
		start_end_comment = (*line)[2];
	}
	else
		start_end_comment = 'c';
	ft_strdel(line);
	get_next_line(0, line);
	if (start_end_comment == 'c')
	{
		ft_strdel(line);
		return ;
	}
	if (start_end_comment == 's')
	{
		g->top_vertex = graph_insert_first_vertex(g, line);
		start_vertix = true;
	}
	else
		g->end_vertex = graph_insert_vertex(g, line);
}

/*
**	[stop_reading_vertexes]
**	Check if we still reading data about room/room's name
**	Either reached data regarding rooms conections
*/

bool	stop_reading_vertexes(char *line)
{
	int		space;

	space = findchr(line, ' ');
	if ((space != -1 && findchr(&line[space + 1], ' ')) != -1 || line[0] == '#')
		return (false);
	return (true);
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
			vertex_name = get_vertex_name(&line);
			graph_insert_vertex(graph, vertex_name);
		}
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
	add_vertexes(graph);
	return (true);
}
