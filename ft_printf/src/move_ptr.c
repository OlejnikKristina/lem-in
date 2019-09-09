/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_ptr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 12:21:18 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	move_ptr(char **input, char move_to, t_output *out)
{
	out->usage = findchr(*input, move_to);
	*input += findchr(*input, move_to);
}
