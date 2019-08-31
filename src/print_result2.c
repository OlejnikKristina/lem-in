/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 16:45:57 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/31 12:01:39 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	distribute_ants(t_paths *all_paths, int ants_amount)
{
	t_paths *path;
	int		i;

	i = 0;
	path = all_paths;
	while (path)
	{
		path->ant_amount = 0;
		path = path->next;
	}
	path = all_paths;
	while (i < ants_amount)
	{
		path->ant_amount += 1;
		path = path->next;
		i++;
		if (path == NULL)
			path = all_paths;
	}
	path = all_paths;
	printf("There are %d ants in path 1\n", path->ant_amount);
	printf("There are %d ants in path 2\n", path->next->ant_amount);
}

/*
**	[add_end_room] Store pointer to last/target room
**	into first pointer, of our linked list,
**	with lovely name "prev"
**	
*/

t_adjvertex	*add_end_room(t_paths *all_paths, t_vertex *end_vertex)
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
			{
				vertex->prev = (t_adjvertex *)malloc(sizeof(t_adjvertex));
				vertex->prev->vertex = end_vertex;
				vertex->prev->next = vertex;
				vertex->prev->prev = NULL;
				add_end = false;
			}
			vertex->next->prev = vertex;
			vertex = vertex->next;
			if (vertex->next == NULL)
				path->first_room = vertex->prev;
		}
		add_end = true;
		path = path->next;
		(path) ? vertex = path->path : NULL;
	}
	return (vertex->prev);
}

// short	send_next_ant(t_adjvertex *room, int ants_left, int *last_ant_name)
// {
// 	if (room->next == room->last)
// 	{
// 		if (0 < ants_left)
// 		{
// 			*last_ant_name += 1;
// 			room->vertex->ant = *last_ant_name;
// 		}
// 	}
// 	return (0);
// }

short		send_first_ant(t_paths *all_paths)
{
	int		ant_name;
	t_paths	*path;

	ant_name = 1;
	path = all_paths;
	while (path)
	{
		if (0 < path->ant_amount)
		{
			path->first_room->vertex->ant = ant_name;
			ft_printf("L-%d-%s ", ant_name, path->first_room->vertex->name);
			ant_name++;
		}
		path = path->next;
	}
	ft_putchar('\n');
	return (0);
}

short	move_ants_forward(t_adjvertex *main_room, int ants_left, int *last_ant_name)
{
	t_adjvertex *room;

	room = main_room;
	while (room != room->last)
	{
		if (room->prev && room->vertex->ant)
		{
			room->prev->vertex->ant = room->vertex->ant;
			ft_printf("L-%d-%s ", room->prev->vertex->ant, room->prev->vertex->name);
		}
		room = room->next;
	}
	if (0 < ants_left)
	{
		*last_ant_name += 1;
		room->prev->vertex->ant = *last_ant_name;
		ft_printf("L-%d-%s ", *last_ant_name, room->prev->vertex->name);
	}
	return (0);
}

void	check_path(t_paths *path, int *last_ant_name)
{
	t_adjvertex	*room;

	room = path->path;
	while (room)
	{
		if (room->vertex->ant)
		{
			move_ants_forward(room, path->ant_amount, last_ant_name);
			ft_putchar('\n');
		//	send_next_ant(room, path->ant_amount, last_ant_name);
		}
		room = room->next;
	}
}

void	print_result(t_paths *paths, t_graph *graph)
{
	int		last_ant_name;
	t_paths	*path;

	path = paths;
	print_reverese_paths(paths);
	distribute_ants(paths, graph->n_ants);
	add_end_room(paths, graph->end_vertex);
	printf("First room: %s\n", paths->first_room->vertex->name);
	last_ant_name = send_first_ant(paths);
	while (path)
	{
		//check_path(path, &last_ant_name);
		path = path->next;
	}
	//print_paths(paths);
}
