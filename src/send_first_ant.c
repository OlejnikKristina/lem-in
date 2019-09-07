/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   send_first_ant.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 15:21:59 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/07 15:23:41 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_end_room(t_adjvertex **vertex, bool *add_end,
		t_vertex *end_vertex)
{
	(*vertex)->prev = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	(*vertex)->prev->vertex = end_vertex;
	(*vertex)->prev->next = *vertex;
	(*vertex)->prev->prev = NULL;
	*add_end = false;
}

bool	send_first_ant(t_paths *all_paths, int *ant_name, int total_ants,
		char *end_room)
{
	t_paths	*path;
	int		i;

	i = 0;
	*ant_name = 1;
	path = all_paths;
	while (path)
	{
		if (0 < path->ant_amount)
		{
			while (path->first_room->vertex->ants[i] && i < 9)
				i++;
			path->first_room->vertex->ants[i] = *ant_name;
			if (i == 0 && print_output(*ant_name,
				path->first_room->vertex->name, total_ants, end_room))
				return (true);
			i = 0;
			path->ant_amount -= 1;
			*ant_name += 1;
		}
		path = path->next;
	}
	ft_putchar('\n');
	return (false);
}
