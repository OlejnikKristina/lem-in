/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_restore.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 11:55:03 by kpereira      #+#    #+#                 */
/*   Updated: 2019/09/04 11:55:03 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int		continious_path(t_graph *graph, t_vertex *vertex, int index)
{
	t_vertex 	*tmp;
	t_adjvertex	*tmp_conn;

	tmp = vertex;
	tmp_conn = tmp->adj_vertexes;
	while (tmp_conn)
	{
		if ((tmp_conn->vertex->parents && tmp_conn->vertex->parents[index] == tmp->parents[index] - 1 && !tmp_conn->vertex->visited) || tmp_conn->vertex == graph->top_vertex)
		{
			tmp = tmp_conn->vertex;
			tmp_conn = tmp->adj_vertexes;
			if (tmp == graph->top_vertex)
				return (1);
			continue ;
		}
		tmp_conn = tmp_conn->next;
	}
	return (0);
}

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
		if (path_lvls[i] != 0 && path_lvls[i] < tmp && continious_path(graph, vertex, i))
		{
			tmp = path_lvls[i];
			rtn = i;
		}
		i++;
	}
	return (rtn);

}

void	add_vertex_path(t_adjvertex *path, t_vertex *vertex)
{
	t_adjvertex	*head;

	head = path;
	while (head->next)
		head = head->next;
	head->next = (t_adjvertex *)malloc(sizeof(t_adjvertex));
	vertex->visited = true;
	head->next->vertex = vertex;
	head->next->next = NULL;
	
}

void	build_path(t_graph *graph, t_vertex *node, t_paths *paths, int index)
{
	t_adjvertex	*tmp;
	t_vertex	*prev;

	tmp = node->adj_vertexes;
	prev = node;
	while (tmp)
	{
		if (tmp->vertex == graph->top_vertex)
		{
			add_vertex_path(paths->path, tmp->vertex);
			paths->length++;
			return ;
		}
		if (tmp->vertex->parents && (tmp->vertex->parents[index] == prev->parents[index] - 1) && !tmp->vertex->visited)
		{
			add_vertex_path(paths->path, tmp->vertex);
			paths->length++;
			prev = tmp->vertex;
			tmp = tmp->vertex->adj_vertexes;
			continue ;
		}
		tmp = tmp->next;
	}

}

void	restore_path(t_graph *graph, t_vertex *vertex, t_paths *paths)
{
	int		index;
	t_paths	*new_path;


	new_path = 0;
	index = get_path(graph, vertex, vertex->parents);
	if (index == -1)
		return ;
	if (!paths->next && !paths->path)
	{
		populate_path(paths, vertex);
		build_path(graph, vertex, paths, index);
	}
	else
	{
		new_path = (t_paths *)malloc(sizeof(t_paths));
		populate_path(new_path, vertex);
		push_path_end(paths, new_path);
		build_path(graph, vertex, new_path, index);
	}
}