/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 18:43:54 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/18 23:02:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <errno.h>
# include <stdio.h> 
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>
# include <stdbool.h>
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

typedef struct			s_adjroom
{
	int					room_num;
	char				*room_name;
	struct s_adjroom	*next;

}						t_adjroom;


typedef struct			s_room
{
	int					room_num;
	char				*room_name;
	struct s_room		*next;
	struct s_adjroom	**adj_rooms;
	
}						t_room;

typedef struct			s_graph
{
	int					ants_n;
	int					rooms_n;
	int					tubes_n;
	t_room				**all_rooms;
}						t_graph;

void					error_generated(int error_num);
bool					ft_only_numbers(char *str);

#endif