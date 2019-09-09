/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_restore_help.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 13:00:42 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 13:04:35 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_path(t_graph *graph, t_vertex *vertex, int *path_lvls)
{
	int		i;
	int		tmp;
	int		rtn;

	i = 0;
	tmp = 2147483647;
	rtn = -1;
	while (i < graph->top_vertex->p_size)
	{
		if (path_lvls[i] != 0 && path_lvls[i] < tmp &&
			continious_path(graph, vertex, i))
		{
			tmp = path_lvls[i];
			rtn = i;
		}
		i++;
	}
	return (rtn);
}

void	push_path_end(t_paths *all_paths, t_paths *new_path)
{
	t_paths	*head;

	head = all_paths;
	while (head->next)
		head = head->next;
	head->next = new_path;
}

void	populate_path(t_paths *first_path, t_vertex *vertex)
{
	first_path->length += 1;
	first_path->path = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	vertex->visited = true;
	first_path->path->vertex = vertex;
	first_path->path->next = NULL;
	first_path->next = NULL;
}

void	add_path(t_paths *all_paths, t_vertex *vertex)
{
	t_paths	*new_path;

	if (!all_paths->next && !all_paths->path)
	{
		populate_path(all_paths, vertex);
		all_paths->length++;
		return ;
	}
	new_path = (t_paths *)malloc(sizeof(t_paths));
	populate_path(new_path, vertex);
	push_path_end(all_paths, new_path);
	new_path->length++;
}
