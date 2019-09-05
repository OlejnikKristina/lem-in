/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   additional_functions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 15:12:33 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/05 16:33:01 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	simple_error_generated(int error)
{
	ft_putstr_fd("Error ", 2);
	if (error == 1)
		ft_putstr_fd("Fail reading a file ", 2);
	if (error == 2)
		ft_putstr_fd(". First line, amount of ants, should be a number", 2);
}

void	error_generated(int error, t_graph *graph)
{
	ft_putstr_fd("Error ", 2);
	if (error == 4)
		ft_putstr_fd("in ant's farm description", 2);
	if (error == 5)
		ft_putstr_fd("there can be only two ##start ##end properties", 2);
	if (error == 6)
	{
		ft_putstr_fd("in links description. One from room dose not exist.", 2);
		ft_putstr_fd(" Or incorrect input", 2);
	}
	if (error == 7)
		perror("not enough memory.");
	free_graph(graph);
	ft_putchar('\n');
	exit(0);
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
		}
		ft_putchar('\n');
		path = path->next;
	}
	ft_putstr("\n\n");
}

int		get_ants_amount(void)
{
	char	*line;
	int		ants_amount;

	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		simple_error_generated(1);
	ants_amount = ft_atoi(line);
	if (!is_only_numbers(line) || ants_amount <= 0)
		simple_error_generated(2);
	ft_strdel(&line);
	return (ants_amount);
}
