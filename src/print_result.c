/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 16:45:57 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/02 10:02:34 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
			CHECK COLISION
	if (room->ant && ft_strcmp(last_room_name, room->name))
	{
		printf("Ant num %d in room %s replace by ant num %d\n",
		room->ant, room->name, *last_ant_name);
	}
	if (room->prev->vertex->ant && ft_strcmp(last_room_name, room->prev->vertex->name))
	{
	printf("Ant num %d in room %s replace by ant num %d\n",
	room->prev->vertex->ant, room->prev->vertex->name, room->vertex->ant);
	}
*/
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
	while (path)
	{
		printf("There are %d ants in path 1\n", path->ant_amount);
		path = path->next;
	}
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

void		print_colorful_output(int ant_name, char *room_name)
{
	ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
	ant_name, room_name);
}

bool		print_output(int ant_name, char *room_name, int total_ants)
{
	int static ants_arrived;

	if (!ft_strcmp(last_room_name, room_name))
	{
		// ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
		// ant_name, room_name);
		ants_arrived++;
		count_ants_arrived++;
		if (count_ants_arrived == 330)
			count_ants_arrived = 330;
		if ((total_ants - (ants_arrived + 1)) <= 0)
			return (true);
	}
	else
	{
		// ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
		// ant_name, room_name);
	}
	return (false);
}

bool		send_first_ant(t_paths *all_paths, int *ant_name, int total_ants)
{
	t_paths	*path;

	*ant_name = 1;
	path = all_paths;
	while (path)
	{
		if (0 < path->ant_amount)
		{
			path->first_room->vertex->ant = *ant_name;
			if (path->first_room->vertex->ant)
			{
				printf("Ant num %d in room %s replace by ant num %d\n",
				path->first_room->vertex->ant, path->first_room->vertex->name, *ant_name);
			}
			if (print_output(*ant_name, path->first_room->vertex->name, total_ants))
				return (true);
			path->ant_amount -= 1;
			*ant_name += 1;
		}
		path = path->next;
	}
	ft_putchar('\n');
	return (false);
}

bool	send_next_ant(t_paths *path, int *last_ant_name, int total_ants)
{
	t_vertex	*room;

	room = path->first_room->vertex;
	if (0 < path->ant_amount)
	{
		room->ant = *last_ant_name;
		if (print_output(*last_ant_name, room->name, total_ants))
			return (true);
		// ft_printf("%{WHITE_B}L-%{YELLOW_B}%d%{WHITE_B}-%{PINK_B}%s ",
		// 	*last_ant_name, path->first_room->vertex->name);
		*last_ant_name += 1;
		path->ant_amount -= 1;
	}
	return (false);
}

bool	move_ant_forward(t_adjvertex *room, t_paths *path, int total_ants)
{
	if (room->prev)
	{
		room->prev->vertex->ant = room->vertex->ant;
		if (print_output(room->vertex->ant, room->prev->vertex->name, total_ants))
			return (true);
		room->vertex->ant = 0;
			// if (!room->prev->prev)
			// 	room->prev->vertex->ant = 0;
	}
	return (false);
}

bool	check_path(t_paths *path, int *prev_ant_name, int total_ants)
{
	t_adjvertex	*room;

	room = path->path;
	while (room->next)
	{
		if (room->vertex->ant)
		{
			if (move_ant_forward(room, path, total_ants))
				return (true);
			if (!room->next->vertex->ant)
				break ;
		}
		room = room->next;
	}
	return (send_next_ant(path, prev_ant_name, total_ants));
}

void	print_result(t_paths *paths, t_graph *graph)
{
	int		previous_ant;
	bool	ants_arrived;
	t_paths	*path;
	int		i;

	i = 0;
	path = paths;
	ants_arrived = false;
	count_ants_arrived = 0;
	print_reverese_paths(paths);
	add_end_room(paths, graph->end_vertex);
	distribute_ants(paths, graph->n_ants);
	ants_arrived = send_first_ant(paths, &previous_ant, graph->n_ants);
	while (!ants_arrived)
	{
		ants_arrived = check_path(path, &previous_ant, graph->n_ants);
		path = path->next;
		if (path == NULL) //&& ft_printf("\n"))
			path = paths;
		i++;
		if (1500 < i)
			break ;
	}
	print_paths(paths);
	ft_printf("%{BLUE_B}TOTAL ANTS ARRIVED %d\n", count_ants_arrived);
}
