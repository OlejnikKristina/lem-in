/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   choose_shortest_paths.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 17:34:51 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 12:40:05 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Ants = 232

// 10	= {253}
// 20	= (20 + 36 + 232) / 2=	144
// 30	= (20+36+38+232) / 3 = 108.6
// 80	= (20+36+38+45+232) / 4 = 197
// 186	(20+36+38+45+47+232) / 5 = 83
// 471	(20+36+38+45+47+53+232) / 6 = 78.5
//		(20+36+38+45+47+53+63+232) / 7 = 76.2
//		(20+36+38+45+47+53+63+84+232) / 8 = 106

short	choose_shortest_paths(t_paths *all_paths,
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
