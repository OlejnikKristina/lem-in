// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   find_paths.c                                       :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: kpereira <marvin@codam.nl>                   +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2019/08/24 18:04:20 by kpereira       #+#    #+#                */
// /*   Updated: 2019/08/25 17:03:08 by krioliin      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

// #include "lem_in.h"

// void	push_path_end(t_paths *all_paths, t_paths *new_path)
// {
// 	t_paths	*head;

// 	head = all_paths;
// 	while (head->next)
// 		head = head->next;
// 	head->next = new_path;
// }

// void	populate_path(t_paths *first_path, t_vertex *vertex)
// {
// 	first_path->length += 1;
// 	first_path->path = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	first_path->path->vertex = vertex;
// 	first_path->path->next = NULL;
// 	first_path->path->printed = false;
// 	first_path->next = NULL;
// 	first_path->ant_num = 0;
// }


// void	add_path(t_paths *all_paths, t_vertex *vertex)
// {
// 	t_paths	*new_path;

// 	if (!all_paths->next && !all_paths->path)
// 	{
// 		populate_path(all_paths, vertex);
// 		return ;
// 	}
// 	new_path = (t_paths *)malloc(sizeof(t_paths));
// 	populate_path(new_path, vertex);
// 	push_path_end(all_paths, new_path);
// }

// void	start_path(t_adjvertex *end_adj_vertex, t_paths *paths)
// {
// 	t_adjvertex	*tmp;

// 	tmp = end_adj_vertex;
// 	while (tmp)
// 	{
// 		if (tmp->vertex->lvl > 0)
// 			add_path(paths, tmp->vertex);
// 		tmp = tmp->next;
// 	}
// }

// void	init_paths(t_paths *paths)
// {
// 	paths->length = 0;
// 	paths->next = 0;
// 	paths->path = 0;
// 	paths->ant_num = 0;
// }

// void	chose_vertex_for_path(t_paths *path, t_adjvertex **adj_vertex, t_vertex **best_option)
// {
// 	t_adjvertex	*tmp;

// 	tmp = path->path;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	(*adj_vertex) = tmp->vertex->adj_vertexes;
// 	(*best_option) = (*adj_vertex)->vertex;
// 	if ((*best_option)->lvl == -2)
// 	{
// 		(*best_option) = (*adj_vertex)->next->vertex;
// 		(*adj_vertex) = (*adj_vertex)->next;		
// 	}
// }

// void	add_best_option(t_adjvertex *path, t_vertex *best_vertex)
// {
// 	t_adjvertex	*head;

// 	head = path;
// 	while (head->next)
// 		head = head->next;
// 	head->next = (t_adjvertex *)malloc(sizeof(t_adjvertex));
// 	head->next->vertex = best_vertex;
// 	head->next->next = NULL;
// }

// void	add_step_to_path(t_paths *path)
// {
// 	t_adjvertex	*adj_vertex;
// 	t_vertex	*best_option;

// 	best_option = NULL;
// 	adj_vertex = NULL;
// 	chose_vertex_for_path(path, &adj_vertex, &best_option);
// 	while (adj_vertex)
// 	{
// 		if ((adj_vertex->vertex->lvl < best_option->lvl) && adj_vertex->vertex->lvl != -2)
// 			best_option = adj_vertex->vertex;
// 		adj_vertex = adj_vertex->next;
// 	}
// 	add_best_option(path->path, best_option);
// 	path->length++;
// 	if (best_option->lvl != -1)
// 		add_step_to_path(path);
// }

// void	fill_paths(t_paths *paths)
// {
// 	t_paths		*head;

// 	head = paths;
// 	while (head)
// 	{
// 		add_step_to_path(head);
// 		head = head->next;
// 	}
// }

// void	find_paths(t_graph *graph, t_paths *paths)
// {
// 	init_paths(paths);
// 	start_path(graph->end_vertex->adj_vertexes, paths);
// 	fill_paths(paths);
// 	print_paths(paths);
// }