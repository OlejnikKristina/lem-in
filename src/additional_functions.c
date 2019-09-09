/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   additional_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 15:12:33 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 14:18:07 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			simple_error_generated(int error)
{
	ft_putstr_fd("Error ", 2);
	if (error == 1)
		ft_putstr_fd("Fail reading a file ", 2);
	if (error == 2)
	{
		ft_putstr_fd(". Amount of ants, should be a positive number", 2);
		ft_putstr_fd("Biger than 0\n", 2);
	}
	exit(0);
}

void			error_generated(int error, t_graph *graph)
{
	ft_putstr_fd("Error ", 2);
	if (error == 4)
		ft_putstr_fd("in ant's farm description", 2);
	if (error == 5)
		ft_putstr_fd("there can be only two ##start ##end properties", 2);
	if (error == 6)
	{
		ft_putstr_fd("in links description. One from room dose not exist.", 2);
		ft_putstr_fd(" Or incorrect input", 2);
	}
	if (error == 7)
		perror("not enough memory.");
	free_graph(graph);
	ft_putchar('\n');
	exit(0);
}

static void		num_shortest_paths_extend(float *steps, t_paths *path, int *i)
{
	*steps += path->length;
	path = path->next;
	*i += 1;
}

short			num_shortest_paths(t_paths *all_paths,
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
			num_shortest_paths_extend(&steps, path, &i);
		steps = (steps + ants_amount) / j;
		if (pre_steps <= steps)
			break ;
		pre_steps = steps;
		j += 1;
		i = 1;
	}
	return (j - 1);
}
