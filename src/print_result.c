/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 21:56:02 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/25 13:39:33 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	print_ants_paths(t_paths *paths, char *end_vertex, int num_ants_run)
// {

// }

// short		print_one_path(t_adjvertex *path_steps, int ant_number)
// {

// }

// short		print_all_paths(t_paths *all_paths, int ants_amount)
// {
// 	int		ant_run;
// 	t_paths	*one_path;

// 	ant_run = 1;
// 	one_path = all_paths;
// 	while (ant_run <= ants_amount)
// 	{
// 		print_one_path(one_path->path, ant_run);
// 		one_path = one_path->next;
// 	}
	
// }

// short		print_all_paths(t_paths *path, t_adjvertex *room,  int ant_num, int ants_amount)
// {
// 	if ((ant_num <= ants_amount) && path->next)
// 		print_all_paths(path->next, ant_num + 1, room->next, ants_amount);
// 	while ()
// 	{
// 		/* code */
// 	}
	
	
// }

void		print_one_step(t_paths *one_way, char *end_room, int ant_number)
{
	t_adjvertex	*path;

	path = one_way->path;
	if (!one_way->ant_num)
		one_way->ant_num = ant_number;
	if (path->printed)
	{
		ft_printf("L-%d room(%s) ", one_way->ant_num, end_room);
		while (path)
		{
			one_way->ant_num = 0;
			path->printed = false;
			path = path->next;
		}
		return ;
	}
	while (path)
	{
		if (path->next == NULL || path->next->printed)
		{
			path->printed = true;
			break ;
		}
		path = path->next;
	}
	ft_printf("L-%d room(%s) ", one_way->ant_num, path->vertex->name);
}

void		print_all_paths(t_paths *all_paths, char *end_room, int ants_amount)
{
	t_paths *path;
	int		ant_num;

	path = all_paths;
	ant_num = 1;
	while (ant_num <= ants_amount)// 3
	{
		path = all_paths;
		while (path)
		{
			print_one_step(path, end_room, ant_num);
			path = path->next;
			ant_num++;
		}
		ft_printf(" \n");
		//if (path == NULL)
		path = all_paths;
	}
	
	
}


// void	print_result(t_paths *paths, t_vertex *start_vertex, int ants_amount)
// {
// 	t_adjvertex	*start_adjlist;
// 	int			num_start_paths;

// 	start_adjlist = start_vertex->adj_vertexes;
// 	num_start_paths = 0;
// 	while (start_adjlist && paths && ants_amount)
// 	{
// 		start_adjlist = start_adjlist->next;
// 		num_start_paths++;
// 	}
// 	ft_printf("start paths %d\n", num_start_paths);
// }