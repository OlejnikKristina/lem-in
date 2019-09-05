/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distribute_ants.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:23:29 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 14:31:59 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_paths_amount(t_paths *path_head)
{
	t_paths		*head;
	int			amoun_conection;

	amoun_conection = 0;
	head = path_head;
	while (head)
	{
		head = head->next;
		amoun_conection++;
	}
	return (amoun_conection);
}

void	distribute_ants(t_paths *all_paths, int ants_amount, short max_paths_num)
{
	t_paths *path;
	int		i;
	int		path_num;

	i = 0;
	path_num = 1;
	path = all_paths;
	while (path)
	{
		path->ant_amount = 0;
		path = path->next;
	}
	path = all_paths;
	if (path->path == NULL)
		return ;
	while (i < ants_amount)
	{
		path->ant_amount += 1;
		path = path->next;
		i++;
		path_num++;
		if (path == NULL || max_paths_num < path_num)
		{
			path = all_paths;
			path_num = 1;
		}
	}
}

/*
**	[add_end_room] Store pointer to last/target room
**	into first pointer, of our linked list,
**	with lovely name "prev"
**	
*/

t_adjvertex		*add_end_room(t_paths *all_paths, t_vertex *end_vertex)
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

bool		send_first_ant(t_paths *all_paths, int *ant_name, int total_ants, char *end_room)
{
	t_paths	*path;
	int		i;

	i = 0;
	*ant_name = 1;
	path = all_paths;
	if (path->first_room->vertex->next == NULL)
		exit(0);
	while (path)
	{
		if (0 < path->ant_amount)
		{
			while (path->first_room->vertex->ants[i] && i < 9)
				i++;
			path->first_room->vertex->ants[i] = *ant_name;
			if (i == 0 && print_output(*ant_name, path->first_room->vertex->name, total_ants, end_room))
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
