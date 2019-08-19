/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/19 17:17:58 by krioliin      ########   odam.nl         */
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
	char				*name;
	struct s_vertex		*next;
	struct s_adjvertex	**adj_vertexes;
	
}						t_vertex;

typedef struct			s_graph
{
	int					n_ants;
	int					n_vertexes;
	int					n_edges;
	t_vertex			*all_vertexes;
}						t_graph;

void					error_generated(int error_num);
bool					ft_only_numbers(char *str);
bool					creat_graph(t_graph *graph);
#endif