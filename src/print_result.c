/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:21:16 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 14:31:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_colorful_output(int ant_name, char *room_name)
{
	ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
	ant_name, room_name);
}

bool		print_output(int ant_name, char *room_name, int total_ants, char *end_room)
{
	int static ants_arrived;

	if (!ft_strcmp(end_room, room_name))
	{
		ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
		ant_name, room_name);
		ants_arrived++;
		count_ants_arrived++;
		if ((total_ants - ants_arrived) <= 0)
			return (true);
	}
	else
	{
		ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{PINK_B}%s ",
		ant_name, room_name);
	}
	return (false);
}
