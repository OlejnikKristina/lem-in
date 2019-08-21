/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creators.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:49:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 15:56:04 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ants_amount()
{
	char	*line;
	int		ants_amount;

	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		error_generated(1);
	ants_amount = ft_atoi(line);
	if (!is_only_numbers(line) || ants_amount <= 0)
		error_generated(2);
	printf("%d\n", ants_amount);
	ft_strdel(&line);
	return (ants_amount);
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

short	graph_insert_vertex(t_graph *graph, char *name)
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

char	*end_start_comment(char **line, char **start_vertex, char **end_vertex)
{
	char	start_end_comment;

	start_end_comment = '\0';
	if (ft_strstr(*line, "##start") || ft_strstr(*line, "##end"))
	{
		if (*start_vertex || *end_vertex)
			error_generated(5);										//Stop program executing. Free graph
		start_end_comment = (*line)[2];
	}
	else
		start_end_comment = 'c';
	ft_strdel(line);
	get_next_line(0, line);
	if (start_end_comment == 'c')
	{
		ft_strdel(line);
		return (NULL);
	}
	if (start_end_comment == 's')
		*start_vertex = get_vertex_name(line);
	else
		*end_vertex = get_vertex_name(line);
	if (*start_vertex || *end_vertex)
		error_generated(4);											//Stop program executing. Free graph
	return ((*start_vertex) ? *start_vertex : *end_vertex);
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

char	*add_vertexes(t_graph *graph, char **start_vertex, char **end_vertex)
{
	// char	*all_vrtxs_names;
	char	*line;
	char	*vertex_name;

	get_next_line(0, &line);
	while (stop_reading_vertexes(line))
	{
		if (line[0] == '#')
			vertex_name = end_start_comment(&line, graph->start_vertex, graph->end_vertex);
		else
			vertex_name = get_vertex_name(&line);
		if (vertex_name)
			graph_insert_vertex(graph, vertex_name);
	}
	return (true);
}

bool	create_graph(t_graph *graph)
{
	char		*vertex_conection;
	char		*start_vertex;
	char		*end_vertex;

	start_vertex = NULL;
	end_vertex = NULL;
	ft_bzero(graph, sizeof(graph));
	graph->n_ants = get_ants_amount();
	add_vertexes(graph, &start_vertex, &end_vertex);
	return (true);
}
