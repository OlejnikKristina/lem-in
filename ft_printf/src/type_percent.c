/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_percent.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 12:19:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	type_percent(t_format_spec *s, t_placeholder *result)
{
	s->dig_amount = 1;
	result->str = ft_strnew(0);
	int_width(s, result);
	result->str = ft_superjoin(&result->str, "%");
	int_flag_minus(s, result);
	return (true);
}
