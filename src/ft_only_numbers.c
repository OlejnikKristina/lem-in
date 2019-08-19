/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_only_numbers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 22:57:34 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/18 23:03:12 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_only_numbers(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}