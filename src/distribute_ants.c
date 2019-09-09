/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   distribute_ants.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:23:29 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 12:50:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static void	loop_paths(t_paths *path)
{
	while (path)
	{
		path->ant_amount = 0;
		path = path->next;
	}
}

static void	move_ants(t_paths *path, int *i, int *x, short *ants_left)
{
	path->ant_amount = *x - path->length + *ants_left;
	path = path->next;
	*ants_left = 0;
	*i += 1;
}

void		distribute_ants(t_paths *all_paths, int ants_amount, short n_paths)
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
		move_ants(path, &i, &x, &ants_left);
	loop_paths(path);
	if (MORE_INFO)
	{
		print_ants_distribution(all_paths);
		ft_printf("(Paths len [%d] + ants_amount [%d])/paths_num[%d]= X[%d]\n",
		total_paths_len, ants_amount, n_paths, x);
	}
}