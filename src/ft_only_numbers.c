/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_only_numbers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 22:57:34 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/19 22:44:50 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_only_space_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !space(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_only_numbers(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}