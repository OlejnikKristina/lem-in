/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:11:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/02 14:44:11 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_adjacent_list(t_adjvertex *list)
{
	t_adjvertex *head;
	t_adjvertex *temp;

	if (!list)
		return ;
	head = list;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

void	free_graph(t_graph *graph)
{
	t_vertex		*head;
	t_vertex		*temp;

	head = graph->top_vertex;
	while (head)
	{
		free_adjacent_list(head->adj_vertexes);
		(head->name) ? ft_strdel(&head->name) : 1;
		temp = head->next;
		(head) ? free(head) : 1;
		head = temp;
	}
}

void	free_data(t_graph *graph)
{
	free_graph(graph);
}