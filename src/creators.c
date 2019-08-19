/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creators.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:49:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/19 20:35:52 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ants_amount()
{
	char	*line;
	int		ants_amount;

	if (get_next_line(0, &line) == -1 || line[0] == '\0')
		error_generated(1);
	ants_amount = ft_atoi(line);
	if (!ft_only_numbers(line) || ants_amount <= 0)
		error_generated(2);
	printf("%d\n", ants_amount);
	ft_strdel(&line);
	return (ants_amount);
}

t_vertex	*create_vertex(char *name)
{
	t_vertex	*new_vertex;

	new_vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (!new_vertex)
		return (NULL);
	new_vertex->name = ft_strdup(name);
	new_vertex->next = NULL;
	return (new_vertex);
}

short	graph_insert_vertexes(t_graph *graph, char *name)
{
	t_vertex	*current;

	current = graph->top_vertexes;
	if (current == NULL)
	{
		graph->top_vertexes = create_vertex(name);
		if (!graph->top_vertexes)
			return (-1);
	}
	while (current->next)
		current = current->next;
	current->next = create_vertex(name);
	graph->n_vertexes++;

}

// short	graph_insert_vertexes(t_graph *graph, char *name)
// {
// 	t_vertex	*new_vertex;

// 	if (graph->all_vertexes == NULL)
// 	{
// 		new_vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
// 		if (!new_vertex)
// 			return (-1);
// 		new_vertex->next = NULL;
// 		new_vertex->name = ft_strdup(name);
// 	}
// 	graph->all_vertexes = new_vertex;
// 	graph->n_vertexes++;
// 	return (1);
// }

void	read_vertexes(t_graph *graph)
{

}

bool	creat_graph(t_graph *graph)
{
	ft_bzero(graph, sizeof(graph));
	graph->n_ants = get_ants_amount();
	read_vertexes(graph);
	return (true);
}