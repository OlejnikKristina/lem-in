/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 16:45:57 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/01 15:11:11 by krioliin      ########   odam.nl         */
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
	ft_printf("%{WHITE_B}L-%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
	ant_name, room_name);
}

void		print_output(int ant_name, char *room_name)
{
	if (!ft_strcmp(last_room_name, room_name))
	{
		ft_printf("%{WHITE_B}L-%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
		ant_name, room_name);
		ant_arrived++;
	}
	else
		ft_printf("%{WHITE_B}L-%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
		ant_name, room_name);
}

short		send_first_ant(t_paths *all_paths, int *ant_name)
{
	t_paths	*path;

	*ant_name = 1;
	path = all_paths;
	while (path)
	{
		if (0 < path->ant_amount)
		{
			path->first_room->vertex->ant = *ant_name;
			print_output(*ant_name, path->first_room->vertex->name);
			path->ant_amount -= 1;
			*ant_name += 1;
		}
		path = path->next;
	}
	ft_putchar('\n');
	return (0);
}

short	send_next_ant(t_paths *path, t_adjvertex *room, int *last_ant_name)
{
	int			i;
	t_adjvertex	*head;

	i = 0;
	head = path->first_room;
	if (0 < path->ant_amount)
	{
		path->first_room->vertex->ant = *last_ant_name;
		//print_output(*last_ant_name, path->first_room->vertex->name);
		ft_printf("%{WHITE_B}L-%{YELLOW_B}%d%{WHITE_B}-%{PINK_B}%s ",
		*last_ant_name, path->first_room->vertex->name);
		*last_ant_name += 1;
		path->ant_amount -= 1;
	}
	else
	{
		path->ant_amount -= 1;
		i = path->ant_amount * -1;
		while (i)
		{
			head->vertex->ant = 0;
			head = head->prev;
			i--;
		}
	}
	return (0);
}

bool	move_ant_forward(t_adjvertex *room, t_paths *path, int last_ant_name)
{
	if (room->prev)
	{
		room->prev->vertex->ant = room->vertex->ant;
		//room->vertex->ant = 0;
		print_output(room->prev->vertex->ant, room->prev->vertex->name);
		if ((last_ant_name == room->vertex->ant) && !room->prev->prev)
			return (1);
	}
	return (0);
}

bool	check_path(t_paths *path, int *prev_ant_name, int last_ant_name)
{
	t_adjvertex	*room;
	bool		last_ant_got;

	last_ant_got = false;
	room = path->path;
	while (room->next)
	{
		if (room->vertex->ant)
		{
			last_ant_got = move_ant_forward(room, path, last_ant_name);
			if (last_ant_got)
				return (1);
		}
		room = room->next;
	}
	send_next_ant(path, room, prev_ant_name);
	return (last_ant_got);
}

void	print_result(t_paths *paths, t_graph *graph)
{
	int		previous_ant;
	bool	ants_arrived;
	t_paths	*path;

	path = paths;
	ants_arrived = false;
	ant_arrived = 0;
	//print_reverese_paths(paths);
	distribute_ants(paths, graph->n_ants);
	add_end_room(paths, graph->end_vertex);
	send_first_ant(paths, &previous_ant);
	while (!ants_arrived)
	{
		ants_arrived = check_path(path, &previous_ant, graph->n_ants);
		path = path->next;
		if (path == NULL && ft_printf("\n"))
			path = paths;
	}
	print_paths(paths);
	ft_printf("%{BLUE_B}TOTAL ANTS ARRIVED %d\n", ant_arrived);
}
