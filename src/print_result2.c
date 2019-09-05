/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 16:45:57 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 12:43:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
	required 61
	orignal 72 use all 11
	orignal 71 use up to 9
	orignal 72 use up to 8
	orignal 74 use up to 7
	orignal 87 use up to 6
*/

void	shortorization(t_paths *all_paths)
{
	t_paths		*head;
	t_adjvertex	*a;
	t_adjvertex	*b;
	t_adjvertex	*temp;
	int			i;

	head = all_paths;
	while (head)
	{
		if (100 <= head->length - 20)
		{
			i = 0;
			a = head->path;
			while (i <= 30)
			{
				a = a->next;
				i++;
			}
			b = a->next;// [elem1] [elem2]
			while (i <= 110)
			{
				temp = b;
				b = b->next;
				//free(temp);
				i++;
			}
			a->next = temp;
		}
		else if (55 <= head->length - 20)
		{
			i = 0;
			a = head->path;
			while (i <= 20)
			{
				a = a->next;
				i++;
			}
			b = a->next;// [elem1] [elem2]
			while (i <= 70)
			{
				temp = b;
				b = b->next;
				//free(temp);
				i++;
			}
			a->next = temp;
		}
		else if (20 <= head->length - 20)
		{
			i = 0;
			a = head->path;
			while (i <= 18)
			{
				a = a->next;
				i++;
			}
			b = a->next;// [elem1] [elem2]
			while (i <= 35)
			{
				temp = b;
				b = b->next;
				//free(temp);
				i++;
			}
			a->next = temp;
		}
		// else if (10 <= head->length - 20)
		// {
		// 	i = 0;
		// 	a = head->path;
		// 	while (i <= 18)
		// 	{
		// 		a = a->next;
		// 		i++;
		// 	}
		// 	b = a->next;// [elem1] [elem2]
		// 	while (i <= 25)
		// 	{
		// 		temp = b;
		// 		b = b->next;
		// 		//free(temp);
		// 		i++;
		// 	}
		// 	a->next = temp;
		// }
		head = head->next;
	}
}

void	distribute_ants(t_paths *all_paths, int ants_amount, short max_paths_num)
{
	t_paths *path;
	int		i;
	int		path_num;

	i = 0;
	path_num = 1;
	path = all_paths;
	printf("---------------------------------------------------------------------\n");
	//shortorization(all_paths);
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
		if (max_paths_num <= path_num || path == NULL)
		{
			path = all_paths;
			path_num = 1;
		}
	}
	path = all_paths;
	while (path)
	{
		printf("There are %d ants in path\n", path->ant_amount);
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
		ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
		ant_name, room_name);
		ants_arrived++;
		count_ants_arrived++;
		if ((total_ants - (ants_arrived + 1)) <= 0)
			return (true);
	}
	else
	{
		ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
		ant_name, room_name);
	}
	return (false);
}

bool		send_first_ant(t_paths *all_paths, int *ant_name, int total_ants)
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
			if (i == 0 && print_output(*ant_name, path->first_room->vertex->name, total_ants))
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
	// while (i < 10)
	// {
	// 	current_room[i] = 0;
	// 	i++;
	// }
}

bool	move_ant_to_next_room(t_adjvertex *room, t_paths *path, int total_ants)
{
	if (room->prev)
	{
		if (print_output(room->vertex->ants[0], room->prev->vertex->name, total_ants))
			return (true);
		put_ant_in_next_room(room->prev->vertex->ants, room->vertex->ants);
	}
	return (false);
}

bool	check_path(t_paths *path, int *prev_ant_name, int total_ants)
{
	t_adjvertex	*room;

	room = path->path;
	while (room->next)
	{
		if (room->vertex->ants[0])
		{
			if (move_ant_to_next_room(room, path, total_ants))
				return (true);
			// if (!room->next->vertex->ants[0])
			// 	break ;
		}
		room = room->next;
	}
	return (send_next_ant(path, prev_ant_name, total_ants));
}

void	print_result(t_paths *paths, t_graph *graph)
{
	int		previous_ant;
	int		count_lines;
	bool	ants_arrived;
	t_paths	*path;

	count_lines = 1;
	path = paths;
	ants_arrived = false;
	count_ants_arrived = 0;
	last_room_name = ft_strdup(graph->end_vertex->name);
	distribute_ants(paths, graph->n_ants,
	choose_shortest_paths(paths, graph->n_ants, get_paths_amount(paths)));
	add_end_room(paths, graph->end_vertex);
	ants_arrived = send_first_ant(paths, &previous_ant, graph->n_ants);
	while (!ants_arrived)
	{
		ants_arrived = check_path(path, &previous_ant, graph->n_ants);
		path = path->next;
		if (path == NULL && ft_printf("\n"))
		{
			path = paths;
			count_lines++;
		}
	}
	ft_printf("\n%{BLUE_B}TOTAL ANTS ARRIVED %d AMOUNT LINES %d\n", count_ants_arrived, count_lines);
	printf("Optimal amount of paths %hd\n",
	choose_shortest_paths(paths, graph->n_ants, get_paths_amount(paths)));
}
