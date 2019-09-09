/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ants_amount.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/07 17:38:06 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 19:07:42 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool	ft_print(char *line)
{
	ft_printf(line);
	ft_putchar('\n');
	return (1);
}

int		get_ants_amount(void)
{
	char	*line;
	int		ants_amount;

	close(0);
	open("maps/flow_ten1", O_RDONLY);
	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		simple_error_generated(1);
	ft_print(line);
	ants_amount = ft_atoi(line);
	if (!is_only_numbers(line) || ants_amount <= 0)
		simple_error_generated(2);
	ft_strdel(&line);
	return (ants_amount);
}
