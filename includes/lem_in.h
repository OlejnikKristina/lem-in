/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/09/04 19:58:51 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <errno.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define MAX_ANTS_IN_ONE_ROOM 10
# define LAST_ANT -1
# define PATH_PASSED -2
# include <stdio.h>

struct					s_vertex;
struct					s_adjvertex;

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
	int					ant;
	bool				visited;
	int					ants[10];
	char				*name;
	struct s_vertex		*next;
	struct s_adjvertex	*adj_vertexes;
}						t_vertex;

typedef struct			s_graph
{
	int					n_ants;
	int					n_vertexes;
	int					n_edges;
	int					n_paths;
	t_vertex			*top_vertex;
	t_vertex			*end_vertex;
}						t_graph;

char					*last_room_name;
int						count_ants_arrived;

/*
** ************************** Create graph **********************************
*/

bool					create_graph(t_graph *graph);
void					free_graph(t_graph *graph);
char					*get_vertex_name(char **line, t_graph *graph);
t_vertex				*create_vertex(char *name);
t_vertex				*graph_insert_first_vertex(t_graph *graph, char *name);
t_vertex				*graph_insert_vertex(t_graph *graph, char *name);
bool					read_vertexes(char *line);


void					set_connections(t_graph *graph, char *first_conection);

/*
	************************* Find the best paths ****************************
*/

void					bfs(t_graph *graph, t_paths	*paths);
void					restore_path(t_graph *graph, t_vertex *vertex, t_paths *paths);
short					choose_shortest_paths(t_paths *all_paths, int ants_amount, int paths_amount);
int						get_paths_amount(t_paths *path_head);
t_paths					*sort_paths(t_paths **paths, int count);

/*
** ************************* Addtional functions ********************************
*/

int						get_ants_amount();

void					free_data(t_graph *graph);
void					simple_error_generated(int error);
void					error_generated(int error_num, t_graph *graph);
bool					is_only_numbers(char *str);
void					free_adjacent_list(t_adjvertex *list);
t_adjvertex				*get_first_room(t_adjvertex *path);
t_adjvertex				*get_first_room_add_end_room(t_adjvertex *path, t_vertex *end_vertex);

/*
** ******************************* Printing *************************************
*/

void					print_reverese_paths(t_paths *all_paths);
void					print_all_paths(t_paths *all_path, t_graph *graph);
void					print_graph(t_vertex *top_vertex);
void					print_paths(t_paths *all_paths);
void					print_result(t_paths *paths, t_graph *graph);

#endif
