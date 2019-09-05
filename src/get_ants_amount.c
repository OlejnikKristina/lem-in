/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_ants_amount.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:06:42 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 15:09:09 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adjvertex	*get_first_room(t_adjvertex *path)
{
	t_adjvertex *vertex;

	vertex = path;
	while (vertex->next)
		vertex = vertex->next;
	return (vertex);
}

void	print_paths(t_paths *all_paths)
{
	t_paths		*path;
	t_adjvertex	*head;

	path = all_paths;
	while (path)
	{
		ft_putchar('\n');
		head = get_first_room(path->path);
		ft_printf("Path len %d\n", path->length);
		while (head)
		{
			ft_printf("(\033[1;35m%s\033[1;37m)", head->vertex->name);
			head = head->prev;
		}printf("\n");
		path = path->next;
	}
	ft_putstr("\n\n");
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
// Don't forget to add -Wall -Wextra -Werror to ft_printf makefile
int		get_ants_amount()
{
	char	*line;
	char	*flow_one = "maps/flow_one.c";
	char	*flow_ten = "maps/flow_ten.txt";// OK
	char	*flow_thousand = "maps/flow-thousand.txt";// OK
	char	*big = "maps/big.txt";
	char	*big2 = "maps/big.txt";
	char	*big_superposition = "maps/big-superposition.txt";
	char	*subject_one = "maps/subject-1.txt";
	char	*snake_in_stairs = "maps/snake_in_stairs.txt";
	char	*normal_map1 = "maps/normal_map1.txt";
	int		ants_amount;

	close(0);
	open(big_superposition, O_RDONLY);
	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		simple_error_generated(1);
	ants_amount = ft_atoi(line);
	if (!is_only_numbers(line) || ants_amount <= 0)
		simple_error_generated(2);
	printf("Ants amount: %d\n", ants_amount);
	ft_strdel(&line);
	return (ants_amount);
}
