/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distribute_ants.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:23:29 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 20:52:44 by krioliin      ########   odam.nl         */
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

int			count_paths_len(t_paths *all_paths, int n_paths, int i)
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

static void	give_ants_to_paths(t_paths *all_paths, int n_paths,
			int x, int ants_left)
{
	t_paths		*path;
	int			i;

	i = 1;
	path = all_paths;
	while (path && i <= n_paths)
	{
		path->ant_amount = x - path->length;
		path = path->next;
		i++;
	}
	while (path)
	{
		path->ant_amount = 0;
		path = path->next;
	}
	i = 1;
	path = all_paths;
	while (path && i <= n_paths && 0 < ants_left)
	{
		path->ant_amount += 1;
		path = path->next;
		ants_left--;
		i++;
	}
}

void		distribute_ants(t_paths *all_paths, int ants_amount, short n_paths)
{
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
	give_ants_to_paths(all_paths, n_paths, x, ants_left);
	if (MORE_INFO)
	{
		print_ants_distribution(all_paths);
		ft_printf("(Paths len [%d] + ants_amount [%d])/paths_num[%d]= X[%d]\n",
		total_paths_len, ants_amount, n_paths, x);
	}
}
