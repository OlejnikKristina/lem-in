/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_shortest_paths.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 17:34:51 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 14:07:20 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

short	num_shortest_paths(t_paths *all_paths,
		int ants_amount, int paths_amount)
{
	t_paths	*path;
	float	pre_steps;
	float	steps;
	int		i;
	int		j;

	j = 2;
	pre_steps = all_paths->length + ants_amount;
	while (path && j < get_paths_amount(all_paths))
	{
		path = all_paths;
		steps = 0;
		while (i <= j && path)
		{
			steps += path->length;
			path = path->next;
			i++;
		}
		steps = (steps + ants_amount) / j;
		printf("Calculation %d result[%f]\n", j, steps);
		if (pre_steps <= steps)
			break ;
		pre_steps = steps;
		j += 1;
		i = 1;
	}
	pre_steps += 0.3;
	printf("Optimal amount of paths %hd\n", (short int)j);
	return (j);
}
