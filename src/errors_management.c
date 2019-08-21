/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 22:51:07 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 21:00:24 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	simple_error_generated(int error)
{
	ft_putstr_fd("Error ", 2);
	if (error == 1)
	 ft_putstr_fd("Fail reading a file ", 2);
	if (error == 2)
		ft_putstr_fd(". First line, amount of ants, should be a number", 2);
}

void	error_generated(int error, t_graph *graph)
{
	if ((error == 4 && ft_putstr_fd("in ant's farm description", 2)) ||
		(error == 5 && ft_putstr_fd("there can be only two ##start ##end properties", 2)))
	{
		free_graph(graph);
		perror("\n");
	}
	exit(0);
}