/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/31 17:48:13 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/31 21:03:27 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_paths_amount(t_paths *path_head)
{
	t_paths *head;
	int			amoun_conection;

	amoun_conection = 0;
	head = path_head;
	while (head)
	{
		head = head->next;
		amoun_conection++;
	}
	return (amoun_conection);
}


t_paths	*swap(t_paths *ptr1, t_paths *ptr2)
{
	t_paths *temp;

	temp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = temp;
	return (ptr2);
}

t_paths	*sort_paths(t_paths **paths, int count)
{
	t_paths		**head;
	t_paths		*p1;
	t_paths		*p2;
	int			swapped;
	int			i;
	int			j;

	i = 0;
	while (i <= count)
	{
		head = paths;
		swapped = 0;
		j = 0;
		while ((j <= count - i - j) && (*head)->next)
		{
			p1 = *head;
			p2 = p1->next;
			if (p2->length < p1->length)
			{
				*head = swap(p1, p2);
				swapped = 1;
			}
			head = &(*head)->next;
			j++;
		}
		if (swapped == 0)
			break ; 
		i++;
	}
	return (*paths);
}
