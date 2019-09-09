/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_help.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 12:54:24 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 12:56:29 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_connections(t_adjvertex *connections)
{
	int rtn;

	rtn = 0;
	while (connections)
	{
		rtn++;
		connections = connections->next;
	}
	return (rtn);
}

void	set_to_zero(int *parents, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		parents[i] = 0;
		i++;
	}
}

int		chenge_of_aspect(t_vertex *to_add, t_vertex *father,
	int size, t_graph *graph)
{
	int i;
	int rtn;

	i = 0;
	rtn = 0;
	if (father == graph->top_vertex)
		return (1);
	while (i < size)
	{
		if (father->parents[i] != 0 && to_add->parents[i] == 0)
		{
			to_add->parents[i] = father->parents[i] + 1;
			rtn = 1;
		}
		i++;
	}
	return (rtn);
}

void	first_linage(t_graph *graph)
{
	t_adjvertex	*tmp;
	int			i;

	i = 0;
	tmp = graph->top_vertex->adj_vertexes;
	while (tmp)
	{
		tmp->vertex->parents = (int *)malloc(sizeof(int) *
			graph->top_vertex->p_size);
		set_to_zero(tmp->vertex->parents, graph->top_vertex->p_size);
		tmp->vertex->parents[i] = 1;
		tmp = tmp->next;
		i++;
	}
}

void	allocate_parents(t_graph *graph)
{
	int *new;

	new = (int *)malloc(sizeof(int) * graph->top_vertex->p_size);
	graph->top_vertex->parents = new;
}
