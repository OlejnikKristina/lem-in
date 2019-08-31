/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/31 11:57:39 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <errno.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define LAST_ANT -1
# define PATH_PASSED -2
# include <stdio.h>

struct					s_vertex;
struct					s_adjvertex;

typedef struct			s_paths
{
	int					length;		//???
	int					ant_amount;//print 2
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
	int					lvl;
	int					ant;
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

// typedef struct			s_ant
// {
// 	int					number;
// 	bool				arrived;
// 	t_adjvertex			*path;
// }						t_ant;


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
	******************************* BFS ****************************
*/

void					bfs(t_graph *graph);
void					find_paths(t_graph *graph, t_paths *paths);

/*
** ********************** Addtional functions ********************************
*/

int						get_ants_amount();

void					print_reverese_paths(t_paths *all_paths);
void					print_all_paths(t_paths *all_path, t_graph *graph);
void					print_graph(t_vertex *top_vertex);
void					print_paths(t_paths *all_paths);
void					print_result(t_paths *paths, t_graph *graph);

void					free_data(t_graph *graph);
void					simple_error_generated(int error);
void					error_generated(int error_num, t_graph *graph);
bool					is_only_numbers(char *str);
void					free_adjacent_list(t_adjvertex *list);

t_adjvertex				*get_first_room(t_adjvertex *path);
t_adjvertex				*get_first_room_add_end_room(t_adjvertex *path, t_vertex *end_vertex);


#endif
