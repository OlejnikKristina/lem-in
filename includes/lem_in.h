/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:37 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <errno.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>

# define vertex_num graph->n_vertexes

/*
** Adjacency rooms are a linked list
** of rooms (vertices) which adjacency to 
** our cuurent room (vertex)
**			①-->③-->④
**		 ⑥<--⑤↙
** If ① our current room. Than,
** adjacency list to ① contains
** rooms ③ and ⑤
*/

// enum					e_colors
// {
// 						white, 
// 						gray, 
// 						black
// };

struct					t_vertex;

typedef struct			s_adjvertex
{
	struct t_vertex			*vertex;
	struct s_adjvertex	*next;

}						t_adjvertex;


typedef struct			s_vertex
{
	char				*name;
	struct s_vertex		*next;
	struct s_adjvertex	**adj_vertexes;
	
}						t_vertex;

typedef struct			s_graph
{
	int					n_ants;
	int					n_vertexes;
	int					n_edges;
	t_vertex			*top_vertex;
	t_vertex			*end_vertex;
}						t_graph;

/*
** ************************** Handle graph **********************************
*/

bool					create_graph(t_graph *graph);
void					free_graph(t_graph *graph);
char					*get_vertex_name(char **line, t_graph *graph);
t_vertex				*create_vertex(char *name);
t_vertex				*graph_insert_first_vertex(t_graph *graph, char *name);
t_vertex				*graph_insert_vertex(t_graph *graph, char *name);
void					end_start_comment(char **line, t_graph *g);
bool					stop_reading_vertexes(char *line);

/*
** ********************** Addtional functions ********************************
*/

int						get_ants_amount();
void					simple_error_generated(int error);
void					error_generated(int error_num, t_graph *graph);
bool					is_only_numbers(char *str);
bool					is_only_space_num(char *str);

#endif