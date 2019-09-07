/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:21:16 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/07 21:14:05 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ants_distribution(t_paths *paths)
{
	t_paths		*path;

	path = paths;
	while (path)
	{
		ft_printf("There are %d ants in path with len %d\n",
		path->ant_amount, path->length);
		path = path->next;
	}
}

void	print_paths(t_paths *all_paths)
{
	t_paths		*path;
	t_adjvertex	*head;

	path = all_paths;
	while (path)
	{
		ft_putchar('\n');
		head = get_first_room(path->path);
		ft_printf("Path len %d\n", path->length);
		while (head)
		{
			ft_printf("(\033[1;35m%s\033[1;37m)", head->vertex->name);
			head = head->prev;
		}
		ft_putchar('\n');
		path = path->next;
	}
	ft_putstr("\n\n");
}

bool		print_output(int ant_name, char *room_name, int total_ants,
			char *end_room)
{
	static int ants_arrived;

	if (!ft_strcmp(end_room, room_name))
	{
		if (MORE_INFO)
			ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
			ant_name, room_name);
		else
			ft_printf("L%d-%s ", ant_name, room_name);
		ants_arrived++;
		if ((total_ants - ants_arrived) <= 0)
			return (true);
	}
	else
	{
		if (MORE_INFO)
			ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
			ant_name, room_name);
		else
			ft_printf("L%d-%s ", ant_name, room_name);
	}
	return (false);
}
