/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 22:51:07 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/18 23:07:45 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error_generated(int error_num)
{
	if (error_num == 1 && ft_putstr_fd("Fail reading a file\n ", 2) ||
		error_num == 2 && ft_putstr_fd("Error in quantity of ants\n", 2))
		perror(" ");
	exit(0);
}