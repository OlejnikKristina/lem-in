/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distribute_ants.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:23:29 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/07 21:52:45 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_paths_amount(t_paths *path_head)
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

int		count_paths_len(t_paths *all_paths, int n_paths, int i)
{
	t_paths		*path;
	int			total_paths_len;

	total_paths_len = 0;
	path = all_paths;
	while (path && i <= n_paths)
	{
		total_paths_len += path->length;
		path = path->next;
		i++;
	}
	return (total_paths_len);
}

void	distribute_ants(t_paths *all_paths, int ants_amount, short n_paths)
{
	t_paths		*path;
	short		ants_left;
	int			total_paths_len;
	int			x;
	int			i;

	ants_left = 0;
	x = 0;
	i = 1;
	if (1 < ants_amount && ants_amount < 20)
		n_paths++;
	total_paths_len = count_paths_len(all_paths, n_paths, i);
	ants_left = (total_paths_len + ants_amount) % n_paths;
	x += (total_paths_len + ants_amount) / n_paths;
	path = all_paths;
	while (path && path->next && i <= n_paths)
	{
		path->ant_amount = x - path->length + ants_left;
		path = path->next;
		ants_left = 0;
		i++;
	}
	while (path)
	{
		path->ant_amount = 0;
		path = path->next;
	}
	if (MORE_INFO)
	{
		print_ants_distribution(all_paths);
		ft_printf("(Paths len [%d] + ants_amount [%d])/paths_num[%d]= X[%d]\n",
		total_paths_len, ants_amount, n_paths, x);
	}
}


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
