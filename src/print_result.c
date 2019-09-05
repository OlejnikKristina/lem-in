/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 14:21:16 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 16:24:44 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

bool		print_colorful_output(int ant_name, char *room_name,
			int total_ants, char *end_room)
{
	static int ants_arrived;

	if (!ft_strcmp(end_room, room_name))
	{
		ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
		ant_name, room_name);
		ants_arrived++;
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

bool		print_output(int ant_name, char *room_name, int total_ants,
			char *end_room)
{
	static int ants_arrived;

	if (!ft_strcmp(end_room, room_name))
	{
		ft_printf("%{WHITE_B}L%{BLUE_B}%d%{WHITE_B}-%{GREEN_B}%s ",
		ant_name, room_name);
		ants_arrived++;
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
