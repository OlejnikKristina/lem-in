/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ants_amount.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:06:42 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 16:08:10 by krioliin      ########   odam.nl         */
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
	if (!is_only_numbers(line) || ants_amount <= 0)
		error_generated(2);
	printf("%d\n", ants_amount);
	ft_strdel(&line);
	return (ants_amount);
}