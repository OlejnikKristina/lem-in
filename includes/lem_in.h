/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/09 20:53:40 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <errno.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>

# define MAX_ANTS_IN_ONE_ROOM 10
# define LAST_ANT -1
# define PATH_PASSED -2
# define MORE_INFO 0

struct s_vertex;
struct s_adjvertex;

typedef struct			s_paths
{
	int					length;
	int					ant_amount;
	struct s_adjvertex	*first_room;
	struct s_adjvertex	*path;
	struct s_paths		*next;
}						t_paths;

typedef struct			s_adjvertex
{
	struct s_vertex		*vertex;
	struct s_adjvertex	*last;
	struct s_adjvertex	*next;
	struct s_adjvertex	*prev;
}						t_adjvertex;

typedef struct			s_vertex
{
	int					*parents;
	int					p_size;
	bool				visited;
	int					ants[10];
	char				*name;
	struct s_vertex		*next;
	struct s_adjvertex	*adj_vertexes;
}						t_vertex;

typedef struct			s_graph
{
	int					n_ants;
	t_vertex			*top_vertex;
	t_vertex			*end_vertex;
}						t_graph;

/*
** ************************** Create graph *************************************
*/

bool					create_graph(t_graph *graph);
bool					read_vertexes(char *line);
char					*get_vertex_name(char **line, t_graph *graph);
t_vertex				*create_vertex(char *name);
t_vertex				*graph_insert_first_vertex(t_graph *graph, char *name);
t_vertex				*graph_insert_vertex(t_graph *graph, char *name);
void					set_connections(t_graph *graph, char *first_conection);
t_adjvertex				*get_first_room(t_adjvertex *path);
void					create_end_room(t_adjvertex **vertex, bool *add_end,
						t_vertex *end_vertex);
void					free_graph(t_graph *graph);

/*
	************************* Find the best paths *****************************
*/

void					bfs(t_graph *graph, t_paths	*paths);
void					restore_path(t_graph *graph, t_vertex *vertex,
						t_paths *paths);
short					num_shortest_paths(t_paths *all_paths, int ants_amount);
int						get_ants_amount();
int						chenge_of_aspect(t_vertex *to_add, t_vertex *father,
						int size, t_graph *graph);
int						not_in_queue(t_adjvertex *queue, t_vertex *to_add);
void					push_node(t_adjvertex *queue, t_vertex *to_add);
t_adjvertex				*init_queue(t_graph *graph, t_adjvertex *queue);
int						get_path(t_graph *graph, t_vertex *vertex,
						int *path_lvls);
void					populate_path(t_paths *first_path, t_vertex *vertex);
void					push_path_end(t_paths *all_paths, t_paths *new_path);
int						count_connections(t_adjvertex *connections);
void					allocate_parents(t_graph *graph);
void					first_linage(t_graph *graph);
int						continious_path(t_graph *graph, t_vertex *vertex,
						int index);
/*
** ***************************** Ants distributing ****************************
*/

int						get_paths_amount(t_paths *path_head);
void					send_ants(t_paths *paths, t_graph *graph);
void					distribute_ants(t_paths *all_paths, int ants_amount,
						short max_paths_num);
bool					send_first_ant(t_paths *all_paths, int *ant_name,
						int total_ants, char *end_room);
void					add_end_room(t_paths *all_paths, t_vertex *end_vertex);
bool					print_output(int ant_name, char *room_name,
						int total_ants, char *end_room);
bool					ft_print(char *line);
void					print_paths(t_paths *all_paths);
void					print_ants_distribution(t_paths *paths);
/*
** ************************* Addtional functions *******************************
*/

void					simple_error_generated(int error);
void					error_generated(int error_num, t_graph *graph);
bool					is_only_numbers(char *str);
void					free_adjacent_list(t_adjvertex *list);
void					free_data(t_graph *graph, t_paths *paths);
void					set_to_zero(int *parents, int size);
char					**end_start_helper(char **line);

#endif
