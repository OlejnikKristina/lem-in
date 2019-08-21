/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_vertexes.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 21:05:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 21:11:43 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_vertex	*graph_insert_first_vertex(t_graph *graph, char *name)
{
	t_vertex	*new_top_vertex;

	new_top_vertex = create_vertex(name);
	new_top_vertex->next = graph->top_vertex;
	graph->top_vertex = new_top_vertex;
	return (new_top_vertex);
}

void	end_start_comment(char **line, t_graph *g)
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
**	[stop_reading_vertexes]
**	Check if we still reading data about room/room's name
**	Either reached data regarding rooms conections
*/

bool	stop_reading_vertexes(char *line)
{
	int		space;

	space = findchr(line, ' ');
	if ((space != -1 && findchr(&line[space + 1], ' ') != -1) || line[0] == '#')
		return (false);
	return (true);
}
