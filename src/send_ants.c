/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   send_ants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 16:45:57 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 16:26:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	send_next_ant(t_paths *path, int *last_ant_name, int total_ants)
{
	t_vertex	*room;
	int			i;

	i = 0;
	room = path->first_room->vertex;
	if (0 < path->ant_amount)
	{
		while (room->ants[i] && i < 9)
			i++;
		room->ants[i] = *last_ant_name;
		// if (print_output(*last_ant_name, room->name, total_ants))
		// 	return (true);
		ft_printf("%{WHITE_B}L%{YELLOW_B}%d%{WHITE_B}-%{PINK_B}%s ",
			*last_ant_name, path->first_room->vertex->name);
		*last_ant_name += 1;
		path->ant_amount -= 1;
	}
	return (false);
}

void	put_ant_in_next_room(int next_room[10], int current_room[10])
{
	int		i;

	i = 0;
	while (next_room[i] && i < 9)
		i++;
	next_room[i] = current_room[0];
	i = 1;
	while (current_room[i] && i < 10)
	{
		current_room[i - 1] = current_room[i];
		i++;
	}
	current_room[i - 1] = 0;
}

bool	move_ant_to_next_room(t_adjvertex *room, t_paths *path,
		int total_ants, char *end_room)
{
	if (room->prev)
	{
		if (print_output(room->vertex->ants[0], room->prev->vertex->name,
			total_ants, end_room))
			return (true);
		put_ant_in_next_room(room->prev->vertex->ants, room->vertex->ants);
	}
	return (false);
}

bool	check_path(t_paths *path, int *prev_ant_name, int total_ants,
		char *end_room)
{
	t_adjvertex	*room;

	room = path->path;
	while (room->next)
	{
		if (room->vertex->ants[0])
			if (move_ant_to_next_room(room, path, total_ants, end_room))
				return (true);
		room = room->next;
	}
	return (send_next_ant(path, prev_ant_name, total_ants));
}

void	send_ants(t_paths *paths, t_graph *graph)
{
	int			previous_ant;
	bool		ants_arrived;
	t_paths		*path;

	path = paths;
	ants_arrived = false;
	distribute_ants(paths, graph->n_ants,
	num_shortest_paths(paths, graph->n_ants, get_paths_amount(paths)));
	add_end_room(paths, graph->end_vertex);
	ants_arrived = send_first_ant(paths, &previous_ant,
	graph->n_ants, graph->end_vertex->name);
	while (!ants_arrived)
	{
		ants_arrived =
		check_path(path, &previous_ant, graph->n_ants, graph->end_vertex->name);
		path = path->next;
		if (path == NULL && ft_printf("\n"))
			path = paths;
	}
}
