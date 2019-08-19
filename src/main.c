/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:10:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/18 23:09:19 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ants_amount()
{
	char	*line;
	int		ants_amount;

	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		error_generated(1);
	ants_amount = ft_atoi(line);
	if (!ft_only_numbers(line) || ants_amount <= 0)
		error_generated(2);
	ft_strdel(&line);
	return (ants_amount);
}

int		main(void)
{
	t_graph graph;

	graph.ants_n = get_ants_amount();
	return (0);
}