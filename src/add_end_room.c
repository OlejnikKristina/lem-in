/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distribute_ants_helper.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 12:43:09 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 20:27:08 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	[add_end_room] Store pointer to last/target room
**	into first pointer, of our linked list,
**	with lovely name "prev"
*/

void		add_end_room(t_paths *all_paths, t_vertex *end_vertex)
{
	t_adjvertex *vertex;
	t_paths		*path;
	bool		add_end;

	add_end = true;
	path = all_paths;
	vertex = all_paths->path;
	while (path)
	{
		while (vertex->next)
		{
			if (add_end)
				create_end_room(&vertex, &add_end, end_vertex);
			vertex->next->prev = vertex;
			vertex = vertex->next;
			if (vertex->next == NULL)
				path->first_room = vertex->prev;
		}
		add_end = true;
		path = path->next;
		(path) ? vertex = path->path : NULL;
	}
}
