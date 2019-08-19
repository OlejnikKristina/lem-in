/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 22:51:07 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/19 22:07:06 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_generated(int error_num)
{
	ft_putstr_fd("Error ", 2);
	if ((error_num == 1 && ft_putstr_fd("Fail reading a file\n ", 2)) ||
		(error_num == 2 && ft_putstr_fd(". First line, amount of ants, \
		should be a number\n", 2)) ||
		/*Free top vertex*/
		(error_num == 4 && ft_putstr_fd("in ant's farm description\n", 2)))
		perror(" ");
	exit(0);
}