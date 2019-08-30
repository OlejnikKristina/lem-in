/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_result.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 21:56:02 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/28 19:58:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
	while (tail)
	{
		printf("Adress prev:[%p] name:[%s]\n", tail, tail->vertex->name);
		tail = tail->prev;
	}
*/

/*
		if (ant[i]->path->prev == NULL)
			ant[i]->arrived = true;
		while (ant[i]->arrived)
			i++;

*/

/*
** set_previous_pointer
*/

t_adjvertex	*get_ants_way(t_adjvertex *path)
{
	t_adjvertex *head;
	bool static first_call;

	head = path;
	first_call = true;
	while (head->next)
	{
		if (first_call)
		{
			head->prev = NULL;
			first_call = false;
		}
		head->next->prev = head;
		head = head->next;
	}

	return (head->prev);
}

void	last_jump(t_ant **ant, int number, char *end)
{
	if (ant[number]->arrived == false)
	{
		ant[number]->arrived = true;
		ft_printf("L%d-%s ", ant[number]->number, end);
	}
}

void	force_ants_to_jump(t_ant **ant, int n_path, int n_ants, char *end)
{
	int		i;
	int		j;
	bool	count;

	i = 0;
	j = 0;
	count  = 0;
	while (!ant[n_ants - 1]->arrived && end)
	{
		if (ant[i]->path)
			ft_printf("L%d-%s ", ant[i]->number, ant[i]->path->vertex->name);
		// while (ant[i]->path->prev == NULL || ant[i]->arrived)
		// {
		// 	last_jump(ant, i, end);
		// 	i++;
		// }
		if (ant[i]->path)
			ant[i]->path = ant[i]->path->prev;
		else
			ant[i]->arrived = true;
		
		i++;
		j++;
		if (j >= n_path)
		{
			if (!count)
				n_path += n_path;
			j = 0;
			i = 0;
			if (count)
				count = 0;
			else
				count = 1;
			ft_putchar('\n');
		}
	}
}

void	print_result(t_paths *paths, t_graph *graph)
{
	t_paths			*path;
	t_ant			**ant;
	int				i;

	i = 0;
	path = paths;
	ant = (t_ant **)malloc(sizeof(t_ant *) * graph->n_ants);
	while (i < graph->n_ants)
	{
		ant[i] = (t_ant *)malloc(sizeof(t_ant));
		ant[i]->number = i + 1;
		ant[i]->path = get_ants_way(path->path);
		ant[i]->arrived = false;
		//ft_printf("Ant%d-room[%s]\n", ant[i]->number, ant[i]->path->vertex->name);
		path = path->next;
		(!path) ? (path = paths) : path;
		i++;
	}ft_putchar('\n');
	force_ants_to_jump(ant, graph->n_paths, graph->n_ants, graph->end_vertex->name);
//	ft_printf("L%d-%s", ant[i]->number, ant[i]->path->vertex->name);
}
