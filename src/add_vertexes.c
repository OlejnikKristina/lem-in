/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_vertexes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 21:05:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 16:34:49 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		is_only_numbers(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

t_adjvertex	*get_first_room(t_adjvertex *path)
{
	t_adjvertex *vertex;

	vertex = path;
	while (vertex->next)
		vertex = vertex->next;
	return (vertex);
}

char		*get_vertex_name(char **line, t_graph *graph)
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

t_vertex	*graph_insert_first_vertex(t_graph *graph, char *name)
{
	t_vertex	*new_top_vertex;

	new_top_vertex = create_vertex(name);
	new_top_vertex->next = graph->top_vertex;
	graph->top_vertex = new_top_vertex;
	return (new_top_vertex);
}

/*
**	[stop_reading_vertexes]
**	Check if we still reading data about room/room's name
**	Either reached data regarding rooms conections
*/

bool		read_vertexes(char *line)
{
	int		space;

	space = findchr(line, ' ');
	if ((space != -1 && (findchr(&line[space + 1], ' ') != -1))
		|| line[0] == '#')
		return (true);
	return (false);
}
