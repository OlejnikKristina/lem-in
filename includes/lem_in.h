/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/21 14:46:45 by krioliin      ########   odam.nl         */
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

//typedef enum {false, true} bool; 
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

enum					e_colors
{
						white, 
						gray, 
						black
};

typedef struct			s_adjvertex
{
	char				*vertex_name;
	struct s_adjvertex	*next;

}						t_adjvertex;


typedef struct			s_vertex
{
	int					id;
	char				*name;
	struct s_vertex		*next;
	struct s_adjvertex	**adj_vertexes;
	
}						t_vertex;

typedef struct			s_graph
{
	char				*start_vertex;
	char				*end_vertex;
	int					n_ants;
	int					n_vertexes;
	int					n_edges;
	t_vertex			*top_vertex;
}						t_graph;

void					save_input_get_info(t_graph *graph);
bool					create_graph(t_graph *graph);

/*
** ********************** Addtional functions ********************************
*/

void					error_generated(int error_num);
bool					is_only_numbers(char *str);
bool					is_only_space_num(char *str);

#endif