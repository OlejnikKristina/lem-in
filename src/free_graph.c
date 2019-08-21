/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_graph.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 16:11:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 18:27:17 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_graph(t_graph *graph)
{
	t_vertex *head;
	t_vertex *temp;

	head = graph->top_vertex;
	while (head)
	{
		(head->name) ? ft_strdel(&head->name) : 1;
		temp = head->next;
		(head) ? free(head) : 1;
		head = temp;
	}
}
